#pragma once
#include <string>
#include "Cpf.hpp"

class Pessoa
{
    protected:
        std::string nome;
        Cpf cpf;
    public:
        Pessoa(Cpf cpf, std::string nome);

    private:
        void verificaTamanhoDoNome();
};

