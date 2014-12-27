#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string devigenere(string plainText, string key);

int main(int argc, string argv[]) {
    // Get the key and validate the command line arg
    while (argc != 2) {
        printf("Usage: ./devigenere key\n");
        return 1;
    }
    string key = argv[1];
    
    // Get the plain text
    printf("Type your ciphertext: \n");
    string cipherText = GetString();
    printf("%s\n", cipherText);
    
    /* 
    * Encipher
    * Ci = (Pi + Ki)% 26
    * Vigenere Cipher
    */
    string plainText = devigenere(cipherText, key);
    
    // print the ciphered text
    printf("The plain text: %s\n", plainText);
    return 0;
}

string devigenere(string cipherText, string key) {
    int textLength = strlen(cipherText);
    int keyLength = strlen(key);
    for (int i = 0, j = 0; i < textLength; i++) {
        if (isalpha(*(cipherText + i))) {
            if (isupper(*(cipherText + i))) {
                //
                cipherText[i] = 'A' + (((*(cipherText + i)) - 'A') - (key[j] - (isupper(key[j])? 'A' : 'a'))) % 26; 
                        
                if (j == (keyLength - 1)) {
                    j = 0;
                    continue;
                } else {
                    j++;
                }
            } else {
                //
                cipherText[i] = 'a' + (((*(cipherText + i)) - 'a') - (key[j] - (isupper(key[j])? 'A' : 'a'))) % 26; 
                
                if (j == (keyLength - 1)) {
                    j = 0;
                    continue;
                } else {
                    j++;
                }
            }
        }
    }
    return cipherText;
}
