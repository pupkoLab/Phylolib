#include <iostream>
#include "../includes/gammaDistribution.h"
#include "../includes/DiscreteDistribution.h"


int main() {
    gammaDistribution gd(1, 1);

    std::cout << gd.categories() << "\n";
    std::cout << gd.rates(0) << "\n";
    std::cout << gd.ratesProb(0) << "\n";

    std::vector<MDOUBLE> rateProbs;
    for (int j = 0 ; j < gd.categories(); ++j) {
        rateProbs.push_back(gd.ratesProb(j));
    }

    DiscreteDistribution d(rateProbs);
    d.drawSample();

    return 0;
}