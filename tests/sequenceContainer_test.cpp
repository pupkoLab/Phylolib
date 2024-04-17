#include <iostream>

#include "../includes/sequenceContainer.h"
#include "../includes/sequence.h"
#include "../includes/nucleotide.h"


int main(){
    nucleotide alph;
    sequence seq1(&alph);
    sequence seq2(&alph);

    seq1.setID(0);
    seq1.setName("0");
    seq1.resize(1024*1024*1024);

    seq2.setID(1);
    seq2.setName("1");
    seq2.resize(1024*1024*1024);

    sequenceContainer container;
    container.add(seq1);
    container.add(seq2);

    std::cin.get();

    std::cout << sizeof(std::vector<ALPHACHAR>) << "\n";
    std::cout << sizeof(std::string) << "\n";
    std::cout << sizeof(const alphabet*) << "\n";
    std::cout << sizeof(vector<ALPHACHAR>::iterator) << "\n";
    std::cout << sizeof(vector<ALPHACHAR>::const_iterator) << "\n";
    std::cout << sizeof(sequence) << "\n";
    std::cout << sizeof(sequenceContainer) << "\n";
    std::cout << sizeof(ALPHACHAR) << "\n";


    return 0;
}