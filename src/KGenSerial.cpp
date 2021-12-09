#include "../include/KGenSerial.h"
#include <iostream>
#include <list>
#include <stdio.h>
using namespace std;

KGenSerial::KGenSerial(string dna_str, int k_num)
{
    dna = dna_str;
    k = k_num;
}

void KGenSerial::start(){

    printf("DNA length: %d", dna.length());

    for(int i=0; i<=dna.length()-k; i++){
        k_mers.push_back(dna.substr(i, k));
    }
}

void KGenSerial::printK_mers(){
     printf("\nk-mers: ");
    for(auto const &i: k_mers){
        std::cout << i << " ";
    }
}