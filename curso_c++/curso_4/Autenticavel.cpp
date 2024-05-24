#include "Autenticavel.hpp"

Autenticavel::Autenticavel(std::string senha) : senha(senha)
{
}

bool Autenticavel::autentica(std::string senha){
    return senha == this->senha;
}
