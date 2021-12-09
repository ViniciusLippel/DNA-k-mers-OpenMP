#include "../include/KGen.h"
#include <iostream>
#include <list>
#include <stdio.h>
#include <omp.h>
using namespace std;

KGen::KGen(string dna_str, int k_num)
{
    dna = dna_str;
    k = k_num;
}

void KGen::start(){
    int indexDif = dna.length()/numThreads;

    printf("DNA length: %d", dna.length());

    #pragma omp parallel num_threads(numThreads)
    {
        int tNum = omp_get_thread_num();
        
        int begin = indexDif*tNum;
        int end = indexDif*(tNum+1)-1;

        if(tNum != numThreads-1){
            generate(begin, end);
        }
        else {
            generate(begin, dna.length()-k);
        }
    } 
}

void KGen::generate(int begin, int end){
    for(int i=begin; i<=end; i++){
        k_mers.push_back(dna.substr(i, k));
    }
}

void KGen::printK_mers(){
     printf("\nk-mers: ");
    for(auto const &i: k_mers){
        std::cout << i << " ";
    }
}