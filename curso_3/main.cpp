#include <iostream>
#include <string>
#include "Conta.hpp"
#include "Titular.hpp"
#include "cpf.hpp"

using namespace std;

//struct e class -> formato do objeto

void exibeSaldo(Conta& conta){// const não muda o valor, vai dar erro, const Conta&
    //o compilador não sabe se o método modifcar os atributos do objeto, por isso a mensagem de erro
    //o const da criação do método do hpp mostra que o método não modificar
    cout << "O saldo da conta é: " << conta.recuperarSaldo() << endl;
}

int main(int argc, char const *argv[])
{
    //construtor de string, usar string no Cpf sem o explicit
    Titular titular(Cpf("123.456.789-10"), "Rodrigo");
    Conta umaConta("123456", titular); // melhor maneira para declarar evitarf copias
    //umaConta.definirNomeTitular("Rodrigo");
    // umaConta.numeroConta = "123456";
    // umaConta.cpfTitular = "123.456.789-10";
    // umaConta.nomeTitular = "Rodrigo";
    // umaConta.saldo = 100;

    umaConta.depositar(500.0);
    umaConta.sacar(200.0);

    cout << "Uma conta:" << umaConta.recuperarSaldo() << " Nome: " << titular.recuperarNomeTitular() << endl;

    exibeSaldo(umaConta);
    
    //variavel temporario, objeto temporario, otimização melhor
    Conta umaOutraConta("654321", Titular(Cpf("098.765.432-10"), "Viana"));

    umaOutraConta.depositar(300.0);
    umaOutraConta.sacar(50.0);

    //cout << "Uma conta:" << umaOutraConta.recuperarSaldo() << " Nome: " << umaOutraConta.recuperarNomeTitular() << endl;

    Titular titular3(Cpf("098.765.432-10"), "Souza");
    Conta maisUmaConta("654321", titular3);

    maisUmaConta.depositar(500.0);
    maisUmaConta.sacar(50.0);

    //cout << "Uma conta:" << maisUmaConta.recuperarSaldo() << " Nome: " << maisUmaConta.recuperarNomeTitular() << endl;

    //operador de resolução de nome, essa função pertence a classe e não ao objeto específico
    cout <<"Número de contas: " << Conta::recuperarNumeroDeContas() << endl;
    

    return 0;
}


//del -> deletar linhas
//crtl + / -> barras as linhas