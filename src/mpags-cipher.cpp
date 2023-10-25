#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Include our functions defined in other files
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};
    bool encrypt{true};
    size_t key{0};
    bool cipherEnabled{false};

    // Process command line input
    processCommandLine(cmdLineArgs, helpRequested, versionRequested,
                     inputFile, outputFile, encrypt, key, cipherEnabled);

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;
    std::string outputText;

    // Check whether user has specified an input file, and has not requested help or version
    if (!inputFile.empty() and helpRequested == false and versionRequested == false and cipherEnabled == true) {
        
        // Create instance of ifstream to read in file
        std::ifstream in_file {inputFile};
        // Check if file has opened properly
        bool ok_to_read = in_file.good();
        // If it has, then read from file
        if (ok_to_read == true)
        {
            // Loop over input and apply function to each character, adding returned string to total string
            while (in_file >> inputChar)
            {
                inputText += (transformChar(inputChar));
            }
        }
        // Inform user that they the input file they specified was not found
        else {
            std::cerr << "[error] Input file " << inputFile << " not found. Could not load data.\n";
            return 1; 
        }
    }

    // If user has not provided an input file, read from user input to terminal
    else if (helpRequested == false and versionRequested == false and cipherEnabled == true)
    {
        std::cout << "Enter input cipher text, press Enter, then press Ctrl + D to process.\n>>> ";
        
        // Loop over input and apply function to each character, adding returned string to total string
        while (std::cin >> inputChar)
        {
            inputText += (transformChar(inputChar));

        }
    }

    // Update user with intermediate step of conveting text
    std::cout << "Converted input to alpanumerical and uppercase: " << inputText << std::endl;

    // With processed uppercase alphanumerical text, apply Caesar cipher
    outputText = runCaesarCipher(encrypt, inputText, key);

    // If user has provided an output file, write result to it
    if (!outputFile.empty() and helpRequested == false and versionRequested == false and cipherEnabled == true) {
        // Create instance of ifstream to read in file
        std::ofstream out_file {outputFile};
        // Check if file has opened properly
        bool ok_to_write = out_file.good();

        // If so, write output text to file
        if (ok_to_write == true)
        {
            std::cout << "Written output to file: " << outputFile << std::endl;
            out_file << outputText << std::endl;
        }

        else {
            std::cerr << "[error] Output file " << outputFile << " not found. Could not write data.\n";
            return 1;
        }
    }
    // Otherwise, as long as help or version not requested, print to terminal
    else if (helpRequested == false and versionRequested == false and cipherEnabled == true)
    {
        // Print out the transliterated text
        std::cout << "Output: " << outputText << std::endl;
    }

    
    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}