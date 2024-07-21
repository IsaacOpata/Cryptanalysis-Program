#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Function to read the ciphertext from a file
string readCiphertext(const string& filename) 
{
    ifstream file(filename, ios::in | ios::binary | ios::ate);
    if (!file) 
    {
        cout << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    // Get the size of the file
    streamsize size = file.tellg();
    file.seekg(0, ios::beg);

    // Read the entire file into a string
    string ciphertext(size, ' ');
    if (!file.read(&ciphertext[0], size)) 
    {
        cout << "Error: An error occurred while reading the file " << filename << endl;
        exit(1);
    }

    file.close();
    return ciphertext;
}

// Function to calculate the frequency of each letter in the ciphertext
map<char, int> frequencyAnalysis(const string& text) 
{
    map<char, int> freq;
    // Iterate through each character in the text
    for (char c : text) 
    {
        if (isalpha(c)) 
        {
            // Convert to lowercase to handle case insensitivity
            char lower_c = tolower(c);
            // Increment the frequency count of the character
            freq[lower_c]++;
        }
    }
    return freq;
}

// Function to find the shift value based on frequency analysis
int findShift(const map<char, int>& freq) 
{
    // Assume 'e' is the most frequent letter in English
    char mostFrequent = 'e';
    int maxFreq = 0;
    char maxChar = ' ';
    // Find the most frequent character in the ciphertext
    for (const auto& pair : freq) 
    {
        if (pair.second > maxFreq) 
        {
            maxFreq = pair.second;
            maxChar = pair.first;
        }
    }
    // Calculate the shift by comparing the most frequent character to 'e'
    int shift = (maxChar - mostFrequent + 26) % 26;
    return shift;
}

// Function to decrypt the ciphertext using the identified shift
string decrypt(const string& ciphertext, int shift) 
{
    string plaintext;
    // Iterate through each character in the ciphertext
    for (char c : ciphertext) 
    {
        if (isalpha(c)) 
        {
            // Determine the base character ('a' for lowercase, 'A' for uppercase)
            char base = islower(c) ? 'a' : 'A';
            // Decrypt the character and add it to the plaintext
            plaintext += (c - base - shift + 26) % 26 + base;
        }
        else 
        {
            // If the character is not alphabetic, add it unchanged
            plaintext += c;
        }
    }
    return plaintext;
}

int main() 
{
    // Filename of the ciphertext file
    string filename = "ciphertext.txt";
    // Read the ciphertext from the file
    string ciphertext = readCiphertext(filename);

    // Perform frequency analysis on the ciphertext
    map<char, int> freq = frequencyAnalysis(ciphertext);
    // Determine the shift value
    int shift = findShift(freq);

    // Decrypt the ciphertext using the identified shift
    string plaintext = decrypt(ciphertext, shift);

    // Output the detected shift and the plaintext
    cout << "Detected shift: " << shift << endl;
    cout << "Plaintext: " << endl << plaintext << endl;

    return 0;
}
