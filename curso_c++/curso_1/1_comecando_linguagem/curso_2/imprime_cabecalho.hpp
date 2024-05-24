#pragma once

#include <iostream>

//dica se fizer sentido
namespace Forca{
    inline void imprime_cabecalho(){ // colar as intruçoes aonde a função é chamada para evitar abrir um outro espaço na memoria para compilar
        std::cout << "*******************" << std::endl;
        std::cout << "***Jogo da Forca***" << std::endl;
        std::cout << "*******************" << std::endl;
        std::cout << std::endl;
    }
}

