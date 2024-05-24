#pragma once
#include <string>

class Cpf
{
    private:
        std::string numero;
    public:
        //explicit Cpf(std::string numero);
        explicit Cpf(std::string numero);
        Cpf(const Cpf& cpf); // evitar copias
        std::string recuperaNumero() const;
};
