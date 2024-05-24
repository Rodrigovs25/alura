#pragma once
#include "Cpf.hpp"
#include <string>
#include "Pessoa.hpp"

class Funcionario : public Pessoa //funcionario herda da pessoa, tem os atributos de pessoa
{
    private:
        float salario;
        //std::string nome; //returna esse nome na função recuperar nome, nao é bom
    public:
        Funcionario(Cpf cpf, std::string nome, float salario);
        std::string recuperarNome() const;
        virtual float bonificacao() const = 0; // puramente virtual
        float recuperaSalario() const;
};

