#include "arena.hpp"
#include <iostream>

Arena::Arena() : count_rounds(0){}

void Arena::add_warrior(const Warrior& warrior){
    warriors.push_back(warrior);
}

void Arena::print_warriors() const {
    std::cout << "\nLista de Guerreiros na Arena \n";
    for (const auto& w : warriors) {
        std::cout << w.name << " vida: " << w.health << "/" << w.max_life << ")\n";
    }
    std::cout << "\n";
}
