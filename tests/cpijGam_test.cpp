#include "../includes/computePijComponent.h"
#include "../includes/amino.h"
#include "../includes/nucleotide.h"
#include "../includes/chebyshevAccelerator.h"
#include "../includes/trivialAccelerator.h"
#include "../includes/gammaDistribution.h"
#include "../includes/readDatMatrix.h"

int main() {

    tree test_tree = tree("/home/elyalab/Dev/failed_syncs/Sailfish-backend/tests/trees/normalbranches_nLeaves100.treefile");

    std::cout << sizeof(double) << "\n";
    std::cout << sizeof(int) << "\n";
    std::cout << sizeof(std::stack<std::pair<int,double>>) << "\n";

    // std::unique_ptr<replacementModel> repModel;
    auto repModel = std::make_unique<pupAll>(datMatrixHolder::wag);
    // std::unique_ptr<pijAccelerator> pij;
    auto pij = std::make_unique<chebyshevAccelerator>(repModel.get());

    // auto _alph = new amino();
    gammaDistribution dist(2.0, 1000);

    auto sp = std::make_shared<stochasticProcess>(&dist, pij.get());

    
    auto cpijGam = computePijGam();

    cpijGam.fillPij(test_tree, *sp);

    DiscreteDistribution::setSeed(39);

    for (size_t i = 0; i < 100; i++)
    {
        std::cout << int(cpijGam.getRandomChar(10, 42, 3)) << " ";
    }
    std::cout << "\n";
    std::cin.get();

}