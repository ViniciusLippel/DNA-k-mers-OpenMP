#include <list>
#include <stdio.h>
#include <string>
using namespace std;

class KGenSerial{
    private:
        std::string dna;
        int k;
        std::list <string> k_mers;
    public:
        KGenSerial(std::string dna, int k);
        void start();
        void printK_mers();

        std::list <string> getK_mers() { return k_mers; }
};