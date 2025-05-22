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
        int heal = warrior1.get_healing_value(); //calcular valor de cura com base na vida atual
        warrior1.health += heal; 

        if(warrior1.health > warrior1.max_life){
            warrior1.health = warrior1.max_life;
        }
        std::cout << "guerreiro " << warrior1.name << " se curou, vida: " << warrior1.health <<"\n"; 
    } else if(action == "attack"){
        int damage = warrior1.get_attack_value();  //calcular valor de ataque com base na vida atual
        warrior2.health -= damage;
        
        if(warrior2.health < 0){
            warrior2.health = 0;
        }
        std::cout << "vida guerreiro " << warrior2.name << " após ataque: " << warrior2.health << "|" << warrior2.max_life << "\n"; 
    } 
}