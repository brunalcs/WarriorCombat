#include "dado.hpp"
#include <string>
#include <map>
#include <random>

std::string Dado::sort_action(const std::map<std::string, int>& probs){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    int r=dis(gen); //sorteia de um a 100
    int count=0; //

    for(const auto& p : probs){ //verifica em qual faixa o numero r caiu e define a ação
        count+=p.second; //guarda a chance (valor da ação)
        if(r<=count){
            return p.first; //armazena a ação 
        }
    }
    return "attack"; //retorna attack por segurança
}