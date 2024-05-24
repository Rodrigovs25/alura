#include "Conta.hpp"
#include <iostream>
//implementação, métodos

//2 maneiras de escrever os construtores
//existe um passo a mais, custa mais
// Conta::Conta(std::string numeroConta, std::string nomeTitular, std::string cpfTitular){ 
//     this->numeroConta = numeroConta;
//     this->nomeTitular = nomeTitular;
//     this->cpfTitular = cpfTitular;
//     this->saldo = 0;
// }

//inicialização da variável que não é especificar do objeto
int Conta::numeroDeContas = 0;

//lista de inicialização, código mais rápido
Conta::Conta(std::string numeroConta, Titular titular) : 
    numeroConta(numeroConta), 
    titular(titular),
    saldo(0)
{
    numeroDeContas++; //incrementar a cada conta diferente
}

Conta::~Conta(){
    numeroDeContas--;
}

void Conta::sacar(float valorASacar){
    if(valorASacar < 0){
            std::cout << "Não pode sacar valor negativo" << std::endl;
            return;
        }

        if(valorASacar > saldo){
            std::cout << "Saldo insuficiente" << std::endl;
            return;
        }
        saldo -= valorASacar;
}

void Conta::depositar(float valorADepositar){
    if(valorADepositar < 0){
            std::cout << "Não pode depositar valor negativo" << std::endl;
            return;
        }
        saldo += valorADepositar;
}

// void Conta::definirNomeTitular(std::string nome){
//     nomeTitular = nome;
// }

// void Conta::definirNumeroConta(std::string numero){
//     numeroConta = numero;
// }
        
// void Conta::definirCpfTitular(std::string cpf){
//     cpfTitular = cpf;
// }

float Conta::recuperarSaldo()const{
    return saldo;
}

std::string Conta::recuperarNumeroConta(){
    return numeroConta;
}
    
// std::string Conta::recuperarNCpfTitular(){
//     return cpfTitular;
// }

// std::string Conta::recuperarNomeTitular(){
//     return nomeTitular;
// }

int Conta::recuperarNumeroDeContas(){
    return numeroDeContas;
}

// void Conta::verificaTamanhoDoNome(){
//     if(nomeTitular.size() < 5){
//         std::cout << "Nome curto" << std::endl;
//         exit(1);
//     }
// }