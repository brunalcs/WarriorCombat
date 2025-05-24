#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include <string>
#include <map>


class Warrior{
    public:
        int max_life;
        std::string name;
        int health;
        float attack;
        float defense;
        float healing;
        int pending_defense;
        std::map<std::string, int> action_probs; //armazena as probabalidades de ação de cada indivíduo
    
        Warrior(int max_life, const std::string& name, int health, float attack, float defense, float healing);

        bool is_alive() const;

        void actions_probabilities(int attack_prob, int defend_prob, int heal_prob);

        std::string get_action() const;

        int get_attack_value() const;

        int get_healing_value() const;

        int get_defend_value() const;
};

#endif