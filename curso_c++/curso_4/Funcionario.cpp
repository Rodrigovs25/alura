#include "Funcionario.hpp"
#include <iostream>

Funcionario::Funcionario(Cpf cpf, std::string nome, float salario)
    : Pessoa(cpf, nome), 
    salario(salario)
{
    //std::cout << "Construtor de funcionario" << std::endl; //executa 1º o contrutor de pessoa antes para criar o funcionario
}

std::string Funcionario::recuperarNome() const{
    return nome;
    //return Pessoa::nome; //retorna nome da classe base, this-> é opcional
}

float Funcionario::recuperaSalario() const{
    return salario;
}