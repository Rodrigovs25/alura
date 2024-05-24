#include <iostream>
#include <map>
#include <vector>
#include "chuta.hpp"
#include "letra_existe.hpp"

extern std::map<char, bool> chutou; // variavel existe em algum lugar, n precisar define ela aqui
extern std::vector<char> chutes_errados;

void chuta(){
    std::cout << "Seu chute: ";
    char chute;
    std::cin >> chute;

    chutou[chute] = true;

    if(letra_existe(chute)){
        std::cout << "O chute está na palavra" << std::endl;
    }
    else{
        std::cout << "O chute não está na palavra" << std::endl;
        chutes_errados.push_back(chute);
    }
    std::cout << std::endl;
}