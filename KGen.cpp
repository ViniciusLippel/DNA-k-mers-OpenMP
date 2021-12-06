#include "KGen.h"
#include <list>
#include <stdio.h>
#include <omp.h>
using namespace std;

class KGen{
    private:
        string dna;
        int k;
        list <string> k_mers;
        final int numThreads=  4;

    public:
        KGen::KGen( dna, int k){
            this.dna = dna;
            this.k = k;
        }

        KmerGenerator::start(){
            int indexDif = this.dna.length()/this.numThreads;

            printf("DNA length: %d", indexDif)

            #pragma omp parallel num_threads(this.numThreads)
            {
                int tNum = omp_get_thread_num();
                
                int begin = indexDif*tNum;
                int end = indexDif*(tNum+1)-1

                if(tNum != numThreads-1){
                    generate(begin, end);
                }
                else {
                    generate(begin, dna.length()-k)
                }
            } 
        }

        KmerGenerator::generate(int begin, int end){
            for(int i=begin; i<=end; i++){
                k_mers.push_back(dna.substr(i, k))
            }
        }
}