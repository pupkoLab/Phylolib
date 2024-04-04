#include <iostream>
#include <cassert>
#include "../includes/tamura92.h"




int main() {

    tamura92 model(1.0, 0.5);

    
    for (size_t i = 0; i < model.alphabetSize(); i++)
    {
        for (size_t j = 0; j < model.alphabetSize(); j++)
        {
            assert(model.dPij_dt(i,j,0) - model.Qij(i,j) < 0.00001);
            std::cout << model.dPij_dt(i,j,0) << " = " << model.Qij(i,j) << "\n";
        }
        
    }
    

}