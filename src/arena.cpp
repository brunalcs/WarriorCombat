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

void Arena::apply_action(std::string action_w1, std::string action_w2, Warrior& warrior1, Warrior& warrior2){
    if(action_w1 == "heal"){
        int heal = warrior1.get_healing_value(); //calcular valor de cura com base na vida atual
        warrior1.health += heal; //adiciona o valor de cura a vida atual do guerreiro

        if(warrior1.health > warrior1.max_life){ //garante que a vida não ultrapasse 100
            warrior1.health = warrior1.max_life;
        }
        std::cout << warrior1.name << " se curou em " << heal
        << " (vida atual: " << warrior1.health << "/" << warrior1.max_life << ")\n"; 
    } 
    if(action_w2 == "heal"){
        int heal = warrior2.get_healing_value(); //calcular valor de cura com base na vida atual
        warrior2.health += heal; //adiciona o valor de cura a vida atual do guerreiro

        if(warrior2.health > warrior2.max_life){ //garante que a vida não ultrapasse 100
            warrior2.health = warrior2.max_life;
        }
        std::cout << warrior2.name << " se curou em " << heal
        << " (vida atual: " << warrior2.health << "/" << warrior2.max_life << ")\n"; 
    } 
    if(action_w1 == "attack"){
        int damage = warrior1.get_attack_value();  //calcular valor de ataque com base na vida atual

            warrior2.health -= damage; //aplica o dano a vida do guerreiro 2
            
            if(warrior2.health < 0){ //garante que o guerreiro não fique com a vida negativa
                warrior2.health = 0;
            }
            std::cout << warrior1.name << " atacou " << warrior2.name
            << " causando " << damage << " de dano"
            << " (vida de " << warrior2.name << ": " << warrior2.health << "/" << warrior2.max_life << ")\n";          
    }
    if(action_w2 == "attack"){
        int damage = warrior2.get_attack_value();  //calcular valor de ataque com base na vida atual
        if(action_w1 == "defend"){
            int reduced_damage =  warrior1.defense * damage; // calcula a defesa considerando a defesa do guerreiro 2
            warrior1.health -= reduced_damage; //aplica o dano a vida do guerreiro 2
        if(warrior1.health < 0){ //garante que o guerreiro não fique com a vida negativa
            warrior1.health = 0;
        }
        std::cout << warrior2.name << " atacou " << warrior1.name
          << " causando " << reduced_damage << " de dano"
          << " (vida de " << warrior1.name << ": " << warrior1.health << "/" << warrior1.max_life << ")\n";
        }else{
            warrior1.health -= damage; //aplica o dano a vida do guerreiro 2
            
            if(warrior1.health < 0){ //garante que o guerreiro não fique com a vida negativa
                warrior1.health = 0;
            }
            std::cout << warrior2.name << " atacou " << warrior1.name
            << " causando " << damage << " de dano"
            << " (vida de " << warrior1.name << ": " << warrior1.health << "/" << warrior2.max_life << ")\n";   
        }
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
        
        apply_action(actionw, actionw2, w, w2);
        status_warriors();
    }
    std::cout << "\n===== Combate encerrado =====\n";
    if(w.is_alive()){
        std::cout << "O vencedor foi o guerreiro: " << w.name << "\n";
    }else{
        std::cout << "O vencedor foi o guerreiro: " << w2.name << "\n";
    }
    
}