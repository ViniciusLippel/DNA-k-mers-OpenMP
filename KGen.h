#include <list>
#include <stdio.h>
#include <string>
using namespace std;

class KGen{
    private:
        std::string dna;
        int k;
        std::list <string> k_mers;
        const int numThreads = 4;
    public:
        KGen(std::string dna, int k);
        void start();
        void generate(int begin, int end);
        void printK_mers();

        std::list <string> getK_mers() { return k_mers; }
};