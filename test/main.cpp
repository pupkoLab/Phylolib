#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>


#include "../src/tree.h"

/*
Read a tree and a fasta file and check whether or not they have the same species.
*/
int main(){


    tree tr = tree("likelihood/simple.tree"); // read a tree from a newick formatted file.

    std::vector<tree::nodeP> vec;
    tr.getAllHTUs(vec, tr.getRoot());

    for (size_t i=0; i < vec.size(); ++i){
        std::cout << vec[i]->name() << "\n"; 
    }
    
    // sub_model.Pij_t()
    
    return 0;
}