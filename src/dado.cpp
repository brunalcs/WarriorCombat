#include "dado.hpp"
#include <iostream>
#include <string>
#include <map>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>

std::string Dado::sort_action(const std::map<std::string, int>& probs){
    
    std::vector<std::string> actions;
    size_t index = 0;

    for(const auto& p : probs){
        for(int i = 0; i < p.second; ++i){
            actions.push_back(p.first);
        }
    }
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(actions.begin(), actions.end(), std::default_random_engine(seed));
    
    return actions[index];
}