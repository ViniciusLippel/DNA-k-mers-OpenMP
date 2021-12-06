#include "KmerGenerator.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    KmerGenerator kGen("AAGATGCACGTAGGGTAC", 3);
    kGen.start();
}