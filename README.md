Overview:
This program is a simple frequency analysis-based decryption tool for Caesar ciphers. 
It reads a ciphertext from a file, analyzes the frequency of characters, determines 
the most likely shift value, and then decrypts the ciphertext using that shift value.

Prerequisites:
C++ compiler
A text file named ciphertext.txt containing the encrypted message

Files
main.cpp: The main C++ source file containing the program
ciphertext.txt: The file containing the ciphertext to be decrypted

How It Works:
Reading the Ciphertext: The program reads the ciphertext from a specified file.
Frequency Analysis: It calculates the frequency of each letter in the ciphertext.
Determining the Shift: It assumes that the most frequent letter in the ciphertext 
corresponds to 'e', the most common letter in English, to determine the shift value.
Decrypting the Ciphertext: Using the identified shift value, the program decrypts the 
ciphertext and outputs the plaintext.
