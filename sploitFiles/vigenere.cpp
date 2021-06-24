/*
 * This program encrypts/decrypts an input string (ASCII printable chars 32 to 126 inclusive)
 * using a vigenere cipher, with a provided encryption key. The alphabet is over the
 * ASCII printable chars 32 to 126 inclusive. 
 * 
 * This program is a helper file for the exploit of my (Michelle Nguyen's) CPSC 525 Project. 
 * 
 */

#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <signal.h>
#include <ctype.h>
#include <string>
#include <iostream>


// Encode a char
char encode(char m, char k){
    return ((((m-32) + (k-32)) + 95))%95+32;
}

// Decode a char
char decode(char m, char k){
    return ((((m-32) - (k-32)) + 95))%95+32;
}

int main(int argc, char * argv[])
{

    // Check command line args
    if (argc != 2){
        printf("Usage: %s [mode of operation]\n\n", argv[0]);
        printf("Mode of operation: \n\t0 - Encrypt \n\t1 - Decrypt\n");
        return 1;
    }

    // Parse mode command line arg
    int mode = std::stoi(argv[1]);
    if (mode != 0 && mode != 1){printf("??? mode.\n"); return 1;}

    // Get plain/ciphertext + encryption key
    std::string plainOrCiphertext;
    std::string key;
    printf("Please enter the plaintext or ciphertext: ");
    std::getline (std::cin,plainOrCiphertext);
    int len = plainOrCiphertext.size();
    printf("Please enter the encryption key: ");
    std::getline (std::cin,key);

    // Encrypt or decrypt
    std::string result = "";
    for(int index = 0; index < len; index++){

        int k_index = index % key.size();

        if(plainOrCiphertext[index] < 32 || plainOrCiphertext[index] > 126){printf("Hm. Sus input... Quiting. \n"); return(1);}

        if (mode == 0) result += encode(plainOrCiphertext[index], key[k_index]);
        if (mode == 1) result += decode(plainOrCiphertext[index], key[k_index]);

    }

    // Print results of encryption/decryption
    printf("Result: %s\n", result.c_str());

    return 0;
}
