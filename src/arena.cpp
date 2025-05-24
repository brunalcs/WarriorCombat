#include "arena.hpp"
#include "dado.hpp"
#include "warrior.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

Arena::Arena() : count_rounds(0){}

void Arena::add_warrior(const Warrior& warrior){
    warriors.push_back(warrior);
}

int Arena::count_alive() const {
    int alive = 0;
    for (const auto& w : warriors) {
        if (w.is_alive()) ++alive;
    }
    return alive;
}

void Arena::status_warriors() const {
    std::cout << "\nLista de Guerreiros na Arena \n";
    for (const auto& w : warriors) {
        std::cout << w.name << " vida: (" << w.health << "/" << w.max_life << ")\n";
    }
    std::cout << "\n";
}

void Arena::clear_unused_defenses(Warrior& w1, Warrior& w2, const std::string& action1, const std::string& action2) {
    if (action2 != "attack") w1.pending_defense = 0; //limpa a defesa do primeiro guerreiro caso a ação do segundo guerreiro não for ataque
    if (action1 != "attack") w2.pending_defense = 0; //limpa a defesa do segundo guerreiro caso a ação do primeiro guerreiro não for ataque
}


void Arena::apply_action(std::string action, int value, Warrior& warrior1, Warrior& warrior2){
    if(action == "heal"){
        int heal = warrior1.get_healing_value(); //calcular valor de cura com base na vida atual
        warrior1.health += heal; //adiciona o valor de cura a vida atual do guerreiro

        if(warrior1.health > warrior1.max_life){ //garante que a vida não ultrapasse 100
            warrior1.health = warrior1.max_life;
        }
        std::cout << warrior1.name << " se curou em " << heal
        << " (vida atual: " << warrior1.health << "/" << warrior1.max_life << ")\n"; 
    } else if(action == "attack"){
        int damage = warrior1.get_attack_value();  //calcular valor de ataque com base na vida atual

        int reduced_damage = std::max(0, damage - warrior2.pending_defense); // calcula a defesa considerando a defesa pendente do guerreiro 2
        warrior2.health -= reduced_damage; //aplica o dano a vida do guerreiro 2
        warrior2.pending_defense = 0; // defesa só vale uma vez
        
        if(warrior2.health < 0){ //garante que o guerreiro não fique com a vida negativa
            warrior2.health = 0;
        }
       std::cout << warrior1.name << " atacou " << warrior2.name
          << " causando " << reduced_damage << " de dano"
          << " (vida de " << warrior2.name << ": " << warrior2.health << "/" << warrior2.max_life << ")\n";
    }
    else if(action=="defend"){
        int defend = warrior1.get_defend_value(); //calcula a defesa
        warrior1.pending_defense=defend; //define o valor da defesa pendente do guerreiro 1 
        std::cout << warrior1.name << " (valor de defesa: " << defend << ", vida: " << warrior1.health << "/" << warrior1.max_life << ")\n";
    }
}

void Arena::figth(){
    if(warriors.size()<2){
        std::cout<<"There are not enough warriors to fight."<<"\n"; //se não houver no minimo dois guerreiros não como ter luta
        exit(1);
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(warriors.begin(), warriors.end(), std::default_random_engine(seed));
    
    Warrior& w = warriors[0];
    Warrior& w2 = warriors[1];

    while(count_alive() >= 2){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(warriors.begin(), warriors.end(), std::default_random_engine(seed));

        count_rounds++;
        std::cout << "\n===== Rodada " << count_rounds << " =====\n";

        std::string actionw = w.get_action();
        std::string actionw2 = w.get_action();

        std::cout << "Acao sorteada [" << w.name << "]: " << actionw << "\n";
        std::cout << "Acao sorteada [" << w2.name << "]: " << actionw2 << "\n";
        
        apply_action(actionw, w.attack, w, w2);
        apply_action(actionw2, w2.attack, w2, w);
        clear_unused_defenses(w, w2, actionw, actionw2); 
        status_warriors();
    }
    std::cout << "\n===== Combate encerrado =====\n";
    if(w.is_alive()){
        std::cout << "O vencedor foi o guerreiro: " << w.name << "\n";
    }else{
        std::cout << "O vencedor foi o guerreiro: " << w2.name << "\n";
    }
    
}