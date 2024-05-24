#pragma once // o arquivo nao ser incluido na unidade de tradução, definição, atributos
#include <string>
#include "Titular.hpp"

//na class tudo por padrao é privado
//no struct tudo por padrao é público
//somente dentro dessa classe que é acessível os atributos, na implementação

class Conta{

    private:
        //static na classe: nao é referente ao objeto, de a toda a classe em si, global para os objetos
        //inicialização tem de estar na implementação
        //propriedade da classe
        static int numeroDeContas; 
    public:
        static int recuperarNumeroDeContas();
    private:
        std::string numeroConta;//member m_...
        Titular titular;
        float saldo;

    public:
        //Conta(); //construtor padrão, Conta() = delete; -> deletar o construtor 
        Conta(std::string numeroConta, Titular titular); // modifiquei o construtor padrao
        ~Conta(); //destrutor, objeto deixar de existe
        void sacar(float valorASacar);
        void depositar(float valorADepositar);
        // void definirNomeTitular(std::string nome);//método setter
        // void definirNumeroConta(std::string numero);// com a conta criada a unica que pode ser mudada é o saldo
        // void definirCpfTitular(std::string cpf);

        float recuperarSaldo()const;///método getter
        std::string recuperarNumeroConta();
        // std::string recuperarNCpfTitular();
        // std::string recuperarNomeTitular();

    //private:
        //método que só melhora o código interno, melhor privado, serve para verificar algo do próprio código
        //void verificaTamanhoDoNome();

};