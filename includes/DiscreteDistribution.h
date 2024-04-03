#pragma once

#include <random>
#include <utility>
#include <vector>
#include <stack>
#include <iostream>

// Implementation of Vose's alias method, given a list of probabilities
// representing a finite distribution builds a datastructure in O(n) time
// that allows O(1) drawing from the distribution.

class DiscreteDistribution
{
private:
    std::vector<double> probabilities_;
    std::vector<int> alias_;
    static std::random_device rd_;
    static std::mt19937_64 rng_;
    static std::uniform_real_distribution<double> biased_coin_;
    static std::uniform_int_distribution<int> fair_die_;


public:
    DiscreteDistribution(std::vector<double> probabilities) {
        int n = probabilities.size();
        fair_die_ = std::uniform_int_distribution<int>(0, n-1);
        biased_coin_ = std::uniform_real_distribution<double>(0,1);
        rng_ = std::mt19937_64(rd_());

        std::stack<std::pair<int, double>> small_;
        std::stack<std::pair<int, double>> large_;

        probabilities_.resize(n);
        alias_.resize(n);


        for(int i = 0; i < n; i++) {
            double scaled_prob = n*probabilities[i];
            std::pair<int, double> current_prob(i, scaled_prob);
            if (current_prob.second < 1) {
                small_.push(current_prob);
            } else {
                large_.push(current_prob);
            }
        }
        while (!small_.empty() && !large_.empty()) {
            std::pair<int, double> s = small_.top();
            std::pair<int, double> l = large_.top();
            small_.pop();
            large_.pop();

            probabilities_[s.first] = s.second;
            alias_[s.first] = l.first;

            l.second = (l.second + s.second) - 1;
            if(l.second < 1) {
                small_.push(l);
            } else {
                large_.push(l);
            }
        }
        while (!large_.empty()) {
            std::pair<int, double> l = large_.top();
            large_.pop();
            probabilities_[l.first] = 1;
        }
        while (!small_.empty()) {
            std::pair<int, double> s = small_.top();
            small_.pop();
            probabilities_[s.first] = 1;
        }
    }

    int drawSample() {
        int die_roll = fair_die_(rng_);
        if (biased_coin_(rng_) < probabilities_[die_roll]) return die_roll + 1;
        return alias_[die_roll] + 1;
    }

    void printTable() {
        for(auto &i: probabilities_){
            std::cout << i << " ";
        }
        std::cout << "\n";
        for(auto &i: alias_){
            std::cout << i << " ";
        }
        std::cout << "\n";
    }

    static void setSeed(int seed) {
        rng_ = std::mt19937_64(seed);
    }

    std::vector<std::pair<double, int>> getTable() {
        std::vector<std::pair<double, int>> prob_alias_table;
        for(int i=0; i < probabilities_.size(); i++){
            std::pair<double, int> current_item (probabilities_[i], alias_[i]);
            prob_alias_table.push_back(current_item);
        }
        return prob_alias_table;
    }

    // DiscreteDistribution(const DiscreteDistribution& d) :  
    //     probabilities_(d.probabilities_), 
    //     alias_(d.alias_),
    //     small_(d.small_),
    //     large_(d.large_),
    //     rng_(d.rng_),
    //     biased_coin_(d.biased_coin_),
    //     fair_die_(d.fair_die_) {};

    // DiscreteDistribution& operator=(DiscreteDistribution& other) {
    //     std::swap(probabilities_, other.probabilities_);
    //     std::swap(alias_, other.alias_);
    //     std::swap(small_, other.small_);
    //     std::swap(large_, other.large_);
    //     std::swap(rng_, other.rng_);
    //     std::swap(biased_coin_, other.biased_coin_);
    //     std::swap(fair_die_, other.fair_die_);
    //     return *this;
    // };     // copy assignment operator

};