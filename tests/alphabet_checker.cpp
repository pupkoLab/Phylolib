#include <iostream>

#include "../includes/amino.h"
#include "../includes/nucleotide.h"


bool checkAminoAcids() {
    amino a;

    if (a.fromInt(a.fromChar('A')) != "A") return false;

    std::vector<ALPHACHAR> allChars =  a.fromString("ARNDCQEGHILKMFPSTWYVBZ?-");

    for (size_t i = 0; i < allChars.size(); i++)
    {
        // std::cout << '0'+ allChars[i] << "\n";

        if(allChars[i] != i) return false;
    }
    


    return true;
}



bool checkNucleotides() {
    nucleotide a;

    if (a.fromInt(a.fromChar('C')) != "C") return false;

    std::vector<ALPHACHAR> allChars =  a.fromString("ACGTURYKMSWBDHVN-.");

    for (size_t i = 0; i < allChars.size(); i++)
    {
        // std::cout << '0'+ allChars[i] << "\n";
        if(allChars[i] != i) return false;
    }
    


    return true;
}


int main() {
    
    if(!checkAminoAcids()) std::cerr << "fail 1!\n";
    if(!checkNucleotides()) std::cerr << "fail 2!\n";

    return 0;
}