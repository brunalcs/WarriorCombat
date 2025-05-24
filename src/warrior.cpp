#include "warrior.hpp"
#include "dado.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

//construtor
Warrior::Warrior(int max_life, const std::string& name, int health, float attack, float defense, float healing)
    : max_life(max_life),name(name), health(health), attack(attack), defense(defense), healing(healing) {
    //valores iniciais
    action_probs["attack"] = 50;
    action_probs["defend"] = 30;
    action_probs["heal"]   = 20;
}

bool Warrior::is_alive() const{ //enquanto a saude (vida atual) for maior que 0 ta vivo
    return health>0;
}

void Warrior::actions_probabilities(int attack_prob, int defend_prob, int heal_prob){
    //int total = attack_prob + defend_prob + heal_prob;
    action_probs["attack"] = attack_prob;
    action_probs["defend"] = defend_prob;
    action_probs["heal"]   = heal_prob;
}

std::string Warrior::get_action() const{
    return Dado::sort_action(action_probs);
}

int Warrior::get_attack_value() const{
    return static_cast<int>(health * attack);
}

int Warrior::get_healing_value() const{
    return static_cast<int>(health * healing);
}

int Warrior::get_defend_value() const{
    return static_cast<int>(health*defense);
}