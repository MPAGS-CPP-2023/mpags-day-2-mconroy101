#include <string>
#include <vector>
#include <cctype>
#include <iostream>

#include "ProcessCommandLine.hpp"

bool processCommandLine(const std::vector<std::string>& args,   // We pass in the vector of C arguments entered on running the code
                        bool& helpRequested,                    // We pass in the empty declared variables for the possible options
                        bool& versionRequested,                 // Here, we choose to pass by reference because we want to alter these
                        std::string& inputFileName,             // variables so that they update and the rest of the code can see their
                        std::string& outputFileName)            // new states.
    {

        //const std::size_t n_args {args.size()};

        // Process command line arguments - ignore zeroth element, as we know this
        // to be the program name and don't need to worry about it
        for (std::size_t i{1}; i < args.size(); ++i) {

            if (args[i] == "-h" || args[i] == "--help") {
                helpRequested = true;
            } 
            
            else if (args[i] == "--version") {
                versionRequested = true;
            } 
            
            else if (args[i] == "-i") {
                // Handle input file option
                // Next element is filename unless "-i" is the last argument

                if (i == args.size() - 1) {
                    std::cerr << "[error] -i requires a filename argument"
                            << std::endl;
                    // exit main with non-zero return to indicate failure
                    return 1;
                } 
                
                else {
                    // Got filename, so assign value and advance past it
                    inputFileName = args[i + 1];
                    ++i;
                }
            } 
            
            else if (args[i] == "-o") {
                // Handle output file option
                // Next element is filename unless "-o" is the last argument
                if (i == args.size() - 1) {
                    std::cerr << "[error] -o requires a filename argument"
                            << std::endl;
                    // exit main with non-zero return to indicate failure
                    return 1;
                } 
                
                else {
                    // Got filename, so assign value and advance past it
                    outputFileName = args[i + 1];
                    ++i;
                }
            } 
            
            else {
                // Have an unknown flag to output error message and return non-zero
                // exit status to indicate failure
                std::cerr << "[error] unknown argument '" << args[i]
                        << "'\n";
                return 1;
            }
        }

        // Handle help, if requested
        if (helpRequested) {
            // Line splitting for readability
            std::cout
                << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
                << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
                << "Available options:\n\n"
                << "  -h|--help        Print this help message and exit\n\n"
                << "  --version        Print version information\n\n"
                << "  -i FILE          Read text to be processed from FILE\n"
                << "                   Stdin will be used if not supplied\n\n"
                << "  -o FILE          Write processed text to FILE\n"
                << "                   Stdout will be used if not supplied\n\n"
                << std::endl;
            // Help requires no further action, so return from main
            // with 0 used to indicate success
            return 0;
        }

        // Handle version, if requested
        // Like help, requires no further action,
        // so return from main with zero to indicate success
        if (versionRequested) {
            std::cout << "0.1.0" << std::endl;
            return 0;
        }

    return 0;
    }