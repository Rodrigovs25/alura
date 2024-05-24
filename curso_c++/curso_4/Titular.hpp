#pragma once
#include <string>
#include "Pessoa.hpp"
#include "Cpf.hpp"
#include "Autenticavel.hpp"

class Titular : public Pessoa, public Autenticavel //herança multipla
{
    public:
        Titular(Cpf cpf, std::string nome, std::string senha);
};

