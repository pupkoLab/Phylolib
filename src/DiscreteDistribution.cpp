#include "../includes/DiscreteDistribution.h"


std::random_device DiscreteDistribution::rd_;
std::mt19937_64 DiscreteDistribution::rng_;
std::uniform_real_distribution<double> DiscreteDistribution::biased_coin_;