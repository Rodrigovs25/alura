#pragma once
#include <string>
#include "Titular.hpp"

class Conta
{
private:
    static int numeroDeContas;

public:
    static int recuperaNumeroDeContas();

private:
    std::string numero;
    Titular titular;

protected:
    float saldo;
    /* 1 = conta corrente e 2 = conta poupança*/
    //short int tipoConta;

public:
    Conta(std::string numero, Titular titular);
    virtual ~Conta(); //classe derivada pode adicionar um destrutor, pode ser extendidda
    void sacar(float valorASacar); // pode ser definido nessa base ou nas filhas
    void depositar(float valorADepositar);
    float recuperaSaldo() const;
    virtual float taxaDeSaque() const = 0; // nao tem implementação no conta.cpp (metodo = 0) e sim nas classes derivadas
    // metodo puramente virtual ou metodo abstrato
    // outras classe extendem a classe conta, herdem para gerar a classe concreta, a classe derivada precisa implementar o metodo taxaDeSaque
};
