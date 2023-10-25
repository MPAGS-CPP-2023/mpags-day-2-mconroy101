#include <cctype>
#include <iostream>
#include     <string>
#include <vector>

#include "TransformChar.hpp"

std::string transformChar (const char in_char) {

// Function takes a single char variable and returns a string object with this
// character converted to upper case (if a letter) or a word (if a number).

    // Define outputs string as empty string
    std::string outputString {""};

    // Check if is an alphabetic character
    if (std::isalpha(in_char)) {
        // If so, convert to uppper case
        outputString += std::toupper(in_char);
        std::cout << outputString << std::endl;
    }

    // Transliterate digits to English words
    switch (in_char) {
        case '0':
            outputString += "ZERO";
            break;
        case '1':
            outputString += "ONE";
            break;
        case '2':
            outputString += "TWO";
            break;
        case '3':
            outputString += "THREE";
            break;
        case '4':
            outputString += "FOUR";
            break;
        case '5':
            outputString += "FIVE";
            break;
        case '6':
            outputString += "SIX";
            break;
        case '7':
            outputString += "SEVEN";
            break;
        case '8':
            outputString += "EIGHT";
            break;
        case '9':
            outputString += "NINE";
            break;
    }

    // If the character isn't alphabetic or numeric, DONT add it

    return outputString;

}
