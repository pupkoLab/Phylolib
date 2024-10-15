#include <iostream>
#include "../includes/treeUtil.h"



int main() {

    tree bigtree("(A:0.5,B:0.5,C:0.5);",false);
    
    std::cout << "bigtree before new node:" << "\n";

    std::cout << bigtree.getNodesNum() << "\n";
    std::cout << bigtree.getAllBranchesLengthSum() << "\n";

    std::vector<tree::TreeNode*> parents;
    std::vector<tree::TreeNode*> sons;


    
    tree newTree;
    std::cout << bigtree.getNodesNum() << "\n";
    bigtree.rootTreeOnBranch(newTree, 0, 0.1);

    std::cout << "newTree:" << "\n";

    std::cout << newTree.getNodesNum() << "\n";
    std::cout << newTree.getAllBranchesLengthSum() << "\n\n";

    newTree.getAllBranches(parents, sons);

    for (size_t i = 0; i < parents.size(); i++)
    {
        std::cout << parents[i]->name() << " " << sons[i]->name() << " " << sons[i]->dis2father() << "\n";
    }

    return 0;

}
