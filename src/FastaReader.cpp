#include "../include/FastaReader.h"
#include <string>
#include <iostream>
#include <fstream>

FastaReader::FastaReader(){
}

std::string FastaReader::read(std::string file)
{
    std::ifstream input(file);
    if (!input.good()) {
        std::cerr << "Error opening: " << file << " . You have failed." << std::endl;
        return "";
    }
    
    std::string line, DNA_sequence;

    while (std::getline(input, line)) {

        if(line.empty())
            continue;

        if (line[0] != '>' and line[0] != ' ') {
            DNA_sequence += line;
        }
    }

    return DNA_sequence;
}