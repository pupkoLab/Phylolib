#include "../includes/DiscreteDistribution.h"


std::random_device DiscreteDistribution::rd_;
std::mt19937_64 DiscreteDistribution::rng_ = std::mt19937_64(DiscreteDistribution::rd_());
std::uniform_real_distribution<double> DiscreteDistribution::biased_coin_ = std::uniform_real_distribution<double>(0,1);