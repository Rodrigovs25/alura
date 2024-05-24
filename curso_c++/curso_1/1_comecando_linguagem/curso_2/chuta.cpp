#include <iostream>
#include "chuta.hpp"
#include "letra_existe.hpp"

void Forca::chuta(std::map<char, bool>& chutou, std::vector<char>& chutes_errados, std::string& palavra_secreta){
    std::cout << "Seu chute: ";
    char chute;
    std::cin >> chute;

    chutou[chute] = true;

    if(Forca::letra_existe(chute, palavra_secreta)){
        std::cout << "O chute está na palavra" << std::endl;
    }
    else{
        std::cout << "O chute não está na palavra" << std::endl;
        chutes_errados.push_back(chute);
        //chutes_errados->push_back(chute); //(*chutes_errados).push_back(chute);
    }
    std::cout << std::endl;
}