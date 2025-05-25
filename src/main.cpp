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

    w.actions_probabilities(4, 3, 3); // alterar se quiser (aqui conan ta agressivo)
    w2.actions_probabilities(2, 3, 5);

    coliseum.figth();
    return 0;
}
