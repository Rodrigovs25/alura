#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[]){

    cout << "* ******************************** *" << endl;
    cout << "  Bem vindo ao jogo da adivinhação  " << endl;
    cout << "* ******************************** *" << endl;

    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    if (dificuldade == 'F'){
        numero_de_tentativas = 15;
    }
    else if (dificuldade == 'M'){
        numero_de_tentativas = 10;
    }
    else {
        numero_de_tentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100; //variavel constante, n muda durante o programa
    //cout << "O número secreto é " << NUMERO_SECRETO << ". Não conte para ninguém!" << endl;
    

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){//while (nao_acertou){
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual é o chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos -= pontos_perdidos;

        cout << "O valor do chute é: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou){
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior){
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else {
            cout << "Seu chute foi menor que número secreto!" << endl;
        }

    }

    // cout << "Fim de jogo!" << endl;
    // cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
    // cout.precision(2); // precisao de duas casas decimais notacao cientifica
    // cout << fixed; // modificado de saida, virgula fixa no final do numero
    // cout << "Sua pontuação foi de " << pontos << endl;

    cout << "Fim de Jogo" << endl;
    if (nao_acertou){
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
    }
    return 0;
}

//g++ jogo_da_acibinha.cpp
//./a.out

//g++ jogo_da_acibinha.cpp -o main
//./main

//g++ jogo_da_acibinha.cpp -o main.out
//./main.out
