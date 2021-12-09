#include "KGenSerial.h"
#include <list>
#include <stdio.h>
#include <omp.h>
using namespace std;

KGenSerial::KGenSerial(string dna_str, int k_num)
{
    dna = dna_str;
    k = k_num;
}

void KGenSerial::start(){

    printf("DNA length: %d", dna.length());

    for(int i=0; i<=dna.length()-k; i++){

    }
}