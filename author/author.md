# Warrior Combat

# Objective

To engage in combat between two warriors in an arena, using attack, defense and healing actions. The combat lasts until there is a winner, who will be the last warrior alive.

# How the Program Works

The Warrior class represents each warrior individually, containing attributes such as maximum life, current health, name, attack power, defense, and healing ability. It also stores the probabilities of performing each possible action. The class provides methods to check whether the warrior is still alive, to set action probabilities, and to retrieve the values for attack, defense, healing, as well as the action chosen based on those probabilities.

The Arena class is responsible for managing the combat. It maintains a vector of participating warriors and a round counter. Its role is to apply actions between two warriors, update their status, display their current state, and control the main logic of the battle through the fight method.

Finally, the Dado class is a utility class with a method called sort_action, which takes a map of action probabilities and randomly returns one of the actions based on those values. It controls the chances of a warrior attacking, defending, or healing in each round.

# Author(s)

Bruna Lucena da Costa Souto 
brunalucena.souto@gmail.com

Natálya Gabriele Nunes de Azevedo 
nunes.natalya23@gmail.com

# Compiling and Running

To compile, simply enter the project folder and, inside the (src) folder where the main .cpp files are located, run the following command:

g++ -Wall -Werror -std=c++17 main.cpp dado.cpp arena.cpp warrior.cpp -o coliseum

# Expected Output

During the execution of the program, in each round, the action randomly chosen for each player — such as attack, defend, or heal — must be displayed, followed by a description of the effect of that action. If a warrior attacks, the program should indicate the damage dealt and the opponent’s current health after the attack. If the action is healing, it is necessary to show how much the warrior healed and what their total health is after the action. Additionally, before and after each round, the program must display the updated health status of each warrior in the format “Name: (current health / maximum health)”. At the end of the battle, the program should indicate which warrior was the winner.

