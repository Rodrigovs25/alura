#include <iostream>
#include <string>
#include "Conta.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "Funcionario.hpp"
#include "Caixa.hpp"
#include "Gerente.hpp"
#include "ContaPoupanca.hpp"
#include "ContaCorrente.hpp"
#include "Autenticavel.hpp"

using namespace std;

void ExibeSaldo(const Conta& conta) // se limita ao tipo, nao executa o metodo transeferePara que é de corrente
{
    cout << "O saldo da conta é: " << conta.recuperaSaldo() << endl;
}

void realizaSaque(Conta& conta){ // desse modo quanto conta ou contapoupanca podem acessar, tem de ser por referencia para o virtual funciona
    conta.sacar(200); //o linker vai procurar o sacar do conta e nao do poupanca, tempo de compilação, mas deve ser no de execução
} //metodo vai ser chamado a partir do objeto

void fazLogin(Autenticavel& alguem, string senha){
    if(alguem.autentica(senha)){
        cout << "Login realizado com sucesso" << endl;
    } else {
        cout << "Senha invalida" << endl;
    }
}

int main()
{
    Titular titular(Cpf("123.456.789-10"), "Rodrigo", "umasenha");
    
    ContaPoupanca umaConta("123456", titular);
    //ContaPoupanca* umaConta = new ContaPoupanca("123456", titular);
    //Conta* umaConta = new ContaPoupanca("123456", titular); //funciona chamar o sacar da poupanca
    //umaConta->sacar(0);
    //delete umaConta; //mas o delete deletar apenas o conta e o contaPoupanca se a criação for Conta*, vazamento de memoria
    //o virtual do detrutor resolve o problema
    umaConta.depositar(500);
    realizaSaque(umaConta);

    ExibeSaldo(umaConta);

    Titular outro(Cpf("098.765.432-10"), "Rodrigo Viana", "outrasenha");
    ContaCorrente umaOutraConta("654321", titular);
    umaOutraConta.depositar(300);

    ContaCorrente outraContaCorrente("546321", titular);

    umaOutraConta.transferePara(outraContaCorrente, 250);

    ExibeSaldo(umaOutraConta);
    ExibeSaldo(outraContaCorrente);

    cout << "Número de contas: " << Conta::recuperaNumeroDeContas() << endl;

    Gerente funcionario(Cpf("123.456.789-10"), "Viana Rodrigo", 12); // Funcionario é um tipo abstrato, nao pode ser intaciado

    cout << "Nome do Funcionario: " << funcionario.recuperarNome() << endl;

    return 0;
}
