#include <iostream>
#include "warrior.hpp"
#include "dado.hpp"
#include "arena.hpp"

int main() {
    Warrior w(100,"Conan", 100, 0.2, 0.4, 0.2);
    Warrior w2(100,"Ares", 100, 0.5, 0.5, 0.1);

    Arena coliseum;
    coliseum.add_warrior(w);
    coliseum.add_warrior(w2);

    //coliseum.status_warriors();

    //std::cout << "Nome: " << w.name << "\n";
    //std::cout << "Vida: " << w.health << "/" << w.max_life << "\n";
    //std::cout << "Ataque: " << w.attack << "\n";
    //std::cout << "Defesa: " << w.defense << "\n";
    //std::cout << "Cura: " << w.healing << "\n";

    w.actions_probabilities(4, 3, 3); // alterar se quiser (aqui conan ta agressivo)
    w2.actions_probabilities(2, 3, 5);

    /*while(w.is_alive() and w2.is_alive()){
        std::string actionw = w.get_action();
        std::string actionw2 = w2.get_action();

        std::cout << "Acao sorteada [" << "]: " << actionw << "\n";
        std::cout << "Acao sorteada [" << "]: " << actionw2 << "\n";
        
        coliseum.apply_action(actionw, w.attack, w, w2);
        coliseum.apply_action(actionw2, w2.attack, w2, w);
        coliseum.clear_unused_defenses(w, w2, actionw, actionw2); 
    }
    if(w.is_alive()){
        std::cout << "O vencedor foi o guerreiro: " << w.name << "\n";
    }else{
        std::cout << "O vencedor foi o guerreiro: " << w2.name << "\n";
    }*/

    coliseum.figth();
    return 0;
}
