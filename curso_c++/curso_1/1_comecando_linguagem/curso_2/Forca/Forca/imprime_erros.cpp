#include <iostream>
#include <vector>
#include "imprime_erros.hpp"

extern std::vector<char> chutes_errados;

void imprime_erros(){
    std::cout << "chutes errados: ";
    for(char letra : chutes_errados){
        std::cout << letra << " ";
    }
    std::cout << std::endl;
}