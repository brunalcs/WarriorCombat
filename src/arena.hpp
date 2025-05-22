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
    void print_warriors() const;
};

#endif
