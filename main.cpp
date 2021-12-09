#include "KGen.cpp"
#include "KGenSerial.cpp"
#include "FastaReader.cpp"
#include <stdio.h>
#include <iostream>
using namespace std;

const int k = 3;

void runParallel(std::string dna) {
    
    KGen kGen(dna, k);
    kGen.start();
   
    kGen.printK_mers();
}

void runSerial(std::string dna) {

    KGenSerial kGenSerial(dna, k);
    kGenSerial.start();

    kGenSerial.printK_mers();
}

int main () {
    
    FastaReader fasta;
    std::string dna = fasta.read("dna_files/dna_0.fa");
    
    std::cout << "Parallel: \n";
    runParallel(dna);

    std::cout << "\nSerial: \n";
    runSerial(dna);
}

