#include "src/KGen.cpp"
#include "src/KGenSerial.cpp"
#include "src/FastaReader.cpp"
#include <stdio.h>
#include <iostream>
#include <chrono>
using namespace std;

const int k = 3;

void runParallel(std::string dna) {
    
    KGen kGen(dna, k);
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    kGen.start();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    
        std::cout << "\nTime taken: " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    //kGen.printK_mers();
}

void runSerial(std::string dna) {

    KGenSerial kGenSerial(dna, k);
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    kGenSerial.start();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    
    std::cout << "\nTime taken: " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    //kGenSerial.printK_mers();
    
}

int main () {
    
    FastaReader fasta;
    std::string dna = fasta.read("dna_files/dna_5.fa");
    
    std::cout << "\nParallel: \n";
    runParallel(dna);
    
    std::cout << "\nSerial: \n";
    runSerial(dna);
    
}

