#include <iostream>
#include <vector>


#include "../includes/tree.h"

using namespace std;


int main(){


    tree tr = tree("/home/elyalab/Dev/projects/Sailfish-backend/libs/Phylolib/tests/likelihood/simple.tree", true); // read a tree from a newick formatted file.

    
    vector<tree::nodeP> vec;
    // tr.getAllLeaves(vec, tr.getRoot());
    double sum = 0;
    tr.getAllNodes(vec, tr.getRoot());

    for (size_t i=0; i < vec.size(); ++i) {
        std::cout << vec[i]->getNumberLeaves() << "\n";
    }
    
    return 0;
}