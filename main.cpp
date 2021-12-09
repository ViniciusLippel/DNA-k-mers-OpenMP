#include "KGen.cpp"
#include "FastaReader.cpp"
#include <stdio.h>
#include <iostream>
using namespace std;

const int k = 3;

int main () {
    
    FastaReader fasta;
    std::string dna = fasta.read("dna_files/dna_0.fa");
    
    runParallel(dna);
}

void runParallel(std::string dna) {
    
    KGen kGen(dna, k);
    kGen.start();
   
    std::list <string> k_list = kGen.getK_mers();
    
    printf("\nk-mers: ");
    for(auto const &i: k_list){
        std::cout << i << " ";
    }
}

void runSerial(std::string dna) {

    for(int i=0; i<=dna.length()-k; i++) {

    }
}