#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string caesar(string plainText, int key);

int main(int argc, string argv[]) {
    // Get the key and validate the command line arg
    while (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    if (key == 0) {
        printf ("Key must be an integer\n");
    }
    
    // Get the plain text
    printf("Type your plain text: \n");
    string plainText = GetString();
    printf("%s\n", plainText);
    
    /* 
    * Encipher
    * Ci = (Pi + k)% 26
    * Caesar Cipher
    */
    string cipherText = caesar(plainText, key);
    
    // print the ciphered text
    printf("The ciphered text: %s\n", cipherText);
    return 0;
}

string caesar(string plainText, int key) {
    int textLength = strlen(plainText);
    for (int i = 0; i < textLength; i++) {
        if (isalpha(*(plainText + i))) {
            if (isupper(*(plainText + i))) {
                //
                plainText[i] = 'A' + (((*(plainText + i)) - 'A') + key) % 26;  
            } else {
                //
                *(plainText + i) = 'a' + (((*(plainText + i)) - 'a') + key) % 26;  
            }
        }
    }
    return plainText;
}
