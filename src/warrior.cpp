#include "warrior.hpp"
#include <iostream>
#include <stdexcept>


//construtor
Warrior::Warrior(const std::string& name, int health, float attack, float defense, float healing)
    : name(name), health(health), max_life(100), attack(attack), defense(defense), healing(healing) {
    //valores iniciais
    action_probs["attack"] = 50;
    action_probs["defend"] = 30;
    action_probs["heal"]   = 20;
}

bool Warrior::is_alive() const{ //enquanto a saude (vida atual) for maior que 0 ta vivo
    return health>0;
}

void Warrior::actions_probabilities(int attack_prob, int defend_prob, int heal_prob){
    int total = attack_prob + defend_prob + heal_prob;
    action_probs["attack"] = attack_prob;
    action_probs["defend"] = defend_prob;
    action_probs["heal"]   = heal_prob;
}
