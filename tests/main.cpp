#include <iostream>
#include <vector>


#include "../includes/tree.h"

using namespace std;


int main(){


    tree tr = tree("likelihood/simple.tree"); // read a tree from a newick formatted file.

    vector<tree::nodeP> vec;
    tr.getAllLeaves(vec, tr.getRoot());


    for (size_t i=0; i < vec.size(); ++i){
        cout << vec[i]->name() << "\n"; 
    }
    
    
    return 0;
}