#include "Caixa.hpp"

Caixa::Caixa(Cpf cpf, std::string nome, float salario): Funcionario(cpf, nome, salario)
{
}

float Caixa::bonificacao() const{ // para acessar o salario o usa o protected no salario ou um Getter
    return recuperaSalario() * 0.1;
}