#include "arena.hpp"
#include <iostream>

Arena::Arena() : count_rounds(0){}

void Arena::add_warrior(const Warrior& warrior){
    warriors.push_back(warrior);
}

void Arena::status_warriors() const {
    std::cout << "\nLista de Guerreiros na Arena \n";
    for (const auto& w : warriors) {
        std::cout << w.name << " vida: " << w.health << "/" << w.max_life << ")\n";
    }
    std::cout << "\n";
}

void Arena::apply_action(std::string action, int value, Warrior& warrior1, Warrior& warrior2){
    if(action == "heal"){
        warrior1.health = warrior1.health + warrior1.healing; 
        std::cout << "guerreiro " << warrior1.name << " se curou, vida: " << warrior1.health; 
    } else if(action == "attack"){
        warrior2.health = warrior2.health - warrior1.attack;
        std::cout << "vida guerreiro " << warrior2.name << " após ataque: " << warrior2.health << "|" << warrior2.max_life << "\n"; 
    } 
}