#pragma once
#include <string>
#include "cpf.hpp"

class Titular
{
    public:
        Cpf cpf; //const &
    private:
        std::string nome;
    public:
        Titular(Cpf cpf, std::string nome);//const &
        std::string recuperarNomeTitular();
    private:
        void verificaTamanhoDoNome();
};

