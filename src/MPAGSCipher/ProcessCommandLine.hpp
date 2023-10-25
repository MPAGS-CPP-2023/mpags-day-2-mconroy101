#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& args,   // We pass in the vector of C arguments entered on running the code
                        bool& helpRequested,                    // We pass in the empty declared variables for the possible options
                        bool& versionRequested,                 // Here, we choose to pass by reference because we want to alter these
                        std::string& inputFileName,             // variables so that they update and the rest of the code can see their
                        std::string& outputFileName);           // new states.;

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_CPP