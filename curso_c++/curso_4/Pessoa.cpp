#include <iostream>
#include "Pessoa.hpp"

Pessoa::Pessoa(Cpf cpf, std::string nome): cpf(cpf), nome(nome)
{
    //std::cout << "Construtor de pessoa" << std::endl;
    verificaTamanhoDoNome();
}

void Pessoa::verificaTamanhoDoNome()
{
    if (nome.size() < 5) {
        std::cout << "Nome muito curto" << std::endl;
        exit(1);
    }
}