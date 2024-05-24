#include "Gerente.hpp"

Gerente::Gerente(Cpf cpf, std::string nome, float salario, std::string senha): 
    Funcionario(cpf, nome, salario), Autenticavel(senha)
{
}

float Gerente::bonificacao() const{ // para acessar o salario o usa o protected no salario ou um Getter
    return recuperaSalario() * 0.5;
}