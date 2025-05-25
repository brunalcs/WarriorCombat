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

    void apply_action(std::string action, std::string action_w2, Warrior& warrior1, Warrior& warrior2);

    void status_warriors() const;
    
    void clear_unused_defenses (Warrior& w1, Warrior& w2, const std::string& action1, const std::string& action2);

    void figth();

    int count_alive() const;
};

#endif
