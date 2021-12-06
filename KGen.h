#include <list>
#include <stdio.h>
#include <string>
using namespace std;

class KmerGenerator{
    private:
        std::string dna;
        int k;
        std::list <string> k_mers;
        const int numThreads;
    public:
        KmerGenerator(std::string dna, int k);
        void start();
        void generate();
};