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
        std::map<std::string, int> action_probs; //armazena as probabalidades de ação de cada indivíduo
    
        Warrior(const std::string& name, int health, float attack, float defense, float healing);

        bool is_alive() const;

        void actions_probabilities(int attack_prob, int defend_prob, int heal_prob);
};





#endif