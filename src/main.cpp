#include <iostream>
#include "warrior.hpp"
#include "dado.hpp"
#include "arena.hpp"

int main() {
    Warrior w(100,"Conan", 100, 25, 15, 10);
    Warrior w2(100,"Ares", 100, 25, 15, 10);

    Arena arena;
    arena.add_warrior(w);
    arena.add_warrior(w2);

    arena.print_warriors();

    std::cout << "Nome: " << w.name << "\n";
    std::cout << "Vida: " << w.health << "/" << w.max_life << "\n";
    std::cout << "Ataque: " << w.attack << "\n";
    std::cout << "Defesa: " << w.defense << "\n";
    std::cout << "Cura: " << w.healing << "\n";

    w.actions_probabilities(60, 30, 10); // alterar se quiser (aqui conan ta agressivo)

    for (int i = 0; i < 10; ++i) { //só pra teste
        std::string action = Dado::sort_action(w.action_probs);
        std::cout << "Acao sorteada [" << i + 1 << "]: " << action << "\n";
    }


    return 0;
}
