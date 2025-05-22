#include <iostream>
#include "warrior.hpp"
#include "dado.hpp"
#include "arena.hpp"

int main() {
    Warrior w(100,"Conan", 100, 25, 15, 10);
    Warrior w2(100,"Ares", 100, 25, 15, 10);

    Arena coliseum;
    coliseum.add_warrior(w);
    coliseum.add_warrior(w2);

    coliseum.status_warriors();

    std::cout << "Nome: " << w.name << "\n";
    std::cout << "Vida: " << w.health << "/" << w.max_life << "\n";
    std::cout << "Ataque: " << w.attack << "\n";
    std::cout << "Defesa: " << w.defense << "\n";
    std::cout << "Cura: " << w.healing << "\n";

    w.actions_probabilities(4, 3, 3); // alterar se quiser (aqui conan ta agressivo)
    w2.actions_probabilities(2, 3, 5);

    while(w.is_alive() and w2.is_alive()){
        std::string actionw = Dado::sort_action(w.action_probs);
        std::string actionw2 = Dado::sort_action(w2.action_probs);

        std::cout << "Acao sorteada [" << "]: " << actionw << "\n";
        std::cout << "Acao sorteada [" << "]: " << actionw2 << "\n";
        
        coliseum.apply_action(actionw, w.attack, w, w2);
        coliseum.apply_action(actionw2, w.attack, w2, w);
    }
    if(w.is_alive()){
        std::cout << "O vencedor foi o guerreiro: " << w.name;
    }else{
        std::cout << "O vencedor foi o guerreiro: " << w2.name;
    }

    /*for (int i = 0; i < 10; ++i) { //só pra teste
        std::string action = Dado::sort_action(w.action_probs);
        std::cout << "Acao sorteada [" << i + 1 << "]: " << action << "\n";
    }*/

    return 0;
}
