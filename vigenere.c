#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string vigenere(string plainText, string key);

int main(int argc, string argv[]) {
    // Get the key and validate the command line arg
    while (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string key = argv[1];
    
    // Get the plain text
    printf("Type your plain text: \n");
    string plainText = GetString();
    printf("%s\n", plainText);
    
    /* 
    * Encipher
    * Ci = (Pi + Ki)% 26
    * Vigenere Cipher
    */
    string cipherText = vigenere(plainText, key);
    
    // print the ciphered text
    printf("The ciphered text: %s\n", cipherText);
    return 0;
}

string vigenere(string plainText, string key) {
    int textLength = strlen(plainText);
    int keyLength = strlen(key);
    for (int i = 0, j = 0; i < textLength; i++) {
        if (isalpha(*(plainText + i))) {
            if (isupper(*(plainText + i))) {
                //
                plainText[i] = 'A' + (((*(plainText + i)) - 'A') + (key[j] - (isupper(key[j])? 'A' : 'a'))) % 26; 
                        
                if (j == (keyLength - 1)) {
                    j = 0;
                    continue;
                } else {
                    j++;
                }
            } else {
                //
                plainText[i] = 'a' + (((*(plainText + i)) - 'a') + (key[j] - (isupper(key[j])? 'A' : 'a'))) % 26; 
                
                if (j == (keyLength - 1)) {
                    j = 0;
                    continue;
                } else {
                    j++;
                }
            }
        }
    }
    return plainText;
}
