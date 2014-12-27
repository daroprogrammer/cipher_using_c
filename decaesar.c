#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string decaesar(string plainText, int key);

int main(int argc, string argv[]) {
    // Get the key and validate the command line arg
    while (argc != 2) {
        printf("Usage: ./decaesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    if (key == 0) {
        printf ("Key must be an integer\n");
    }
    
    // Get the plain text
    printf("Type your ciphertext: \n");
    string cipherText = GetString();
    printf("%s\n", cipherText);
    
    /* 
    * Encipher
    * Ci = (Pi + k)% 26
    * Caesar Cipher
    */
    string plainText = decaesar(cipherText, key);
    
    // print the ciphered text
    printf("The plain text: %s\n", plainText);
    return 0;
}

string decaesar(string cipherText, int key) {
    int textLength = strlen(cipherText);
    for (int i = 0; i < textLength; i++) {
        if (isalpha(*(cipherText + i))) {
            if (isupper(*(cipherText + i))) {
                //
                cipherText[i] = 'A' + (((*(cipherText + i)) - 'A') + (key+26)) % 26;  
            } else {
                //
                *(cipherText + i) = 'a' + (((*(cipherText + i)) - 'a') + (key+26)) % 26;  
            }
        }
    }
    return cipherText;
}
