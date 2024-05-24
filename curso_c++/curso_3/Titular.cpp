#include "Titular.hpp"
#include <iostream>


Titular::Titular(Cpf cpf, std::string nome) : cpf(cpf), nome(nome)
{
    verificaTamanhoDoNome();
}

std::string Titular::recuperarNomeTitular(){
    return nome;
}

void Titular::verificaTamanhoDoNome(){
    if(nome.size() < 5){
        std::cout << "Nome curto" << std::endl;
        exit(1);
    }
}