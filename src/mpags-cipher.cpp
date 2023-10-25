#include <cctype>
#include <iostream>
#include <string>
#include <vector>

// Include our functions defined in other files
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"


int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    // Process command line input
    processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, inputFile);

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // Loop over input and apply function to each character, adding returned string to total string
    while (std::cin >> inputChar)
    {
        inputText += (transformChar(inputChar));
    }

    // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {
        std::cerr << "[warning] input from file ('" << inputFile
                  << "') not implemented yet, using stdin\n";
    }

    // Print out the transliterated text
    std::cout << "Output: " << inputText << std::endl;

    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        std::cerr << "[warning] output to file ('" << outputFile
                  << "') not implemented yet, using stdout\n";
    }


    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}