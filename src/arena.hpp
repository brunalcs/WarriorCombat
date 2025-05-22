#ifndef ARENA_HPP
#define ARENA_HPP

#include <vector>
#include "warrior.hpp"

class Arena{
private:
    std::vector<Warrior> warriors;
    int count_rounds;

public:
    Arena(/* args */);
    void add_warrior(const Warrior& warrior);

    void apply_action(std::string action, int value, Warrior& warrior1, Warrior& warrior2);

    void status_warriors() const;
};

#endif
