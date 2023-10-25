#include <string>
#include <vector>
#include <iostream>

std::string runCaesarCipher (const bool encrypt, const std::string inputText, const size_t key)
// Function takes a boolean value whether to encrypt or decrypt,
// text to process and a key to shift by. Returns shifted string.

{
    // First, define vector of all alphabet characters
    std::vector<char> alphabet {'A', 'B', 'C', 'D', 'E', 'F',
                                'G', 'H', 'I', 'J', 'K',
                                'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 
                                'V', 'W', 'X', 'Y', 'Z'};
    // And a string to hold the output
    std::string outputText {""};
    // And a character to hold the shifted character
    char shifted {'X'};
    // And an integer to shift by 
    int N_shift {0};

    // Encryption
    if  (encrypt == true)
    {
        // Iterate through each character of string
        for (auto &ch : inputText)
        {
            // Create an interative variable to index the alphabet vector
            int i {0};
            // Iterate through each character in alphabet
            for (auto &alph : alphabet)
            {
                // Check if current char matches letter of the alphabet
                if (alph == ch)
                {   
                    // If a match, calculate amount to shift by
                    N_shift = (i + key) % 26;
                    // Define new shifted character
                    shifted = alphabet[N_shift];
                }
                // Increment alphabet index iterator
                i++;
            }
            // Add shifted array to output string
            outputText += shifted;

        }

    }

    // Decryption
    else if (encrypt == false)
    {
        
        // Iterate through each character of string
        for (auto &ch : inputText)
        {
            // Create an interative variable to index the alphabet vector
            int i {0};
            // Iterate through each character in alphabet
            for (auto &alph : alphabet)
            {
                // Check if current char matches letter of the alphabet
                if (alph == ch)
                {   
                    // Calculate amount to shift by
                    N_shift = (i - key + 26) % 26;  // For decryption, shift all characters by 26 
                    // Define new shifted character
                    shifted = alphabet[N_shift];
                }
                // Increment alphabet index iterator
                i++;
            }
            // Add shifted char to output string
            outputText += shifted;

        }
    }

    // Return resulting shifted string
    return outputText;
}