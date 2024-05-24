#pragma once
#include "Conta.hpp"

class ContaPoupanca final : public Conta // classe final: nao pode ser extendido, o final ou destrutor virtual resolve o problema do vazamento de memoria
{
    public:
        ContaPoupanca(std::string numero, Titular titular);
        //void sacar(float valorASacar) override; // como n vai herdar nao precisa de virtual, tempo de execução
        //~ContaPoupanca();
        float taxaDeSaque() const override;
};
