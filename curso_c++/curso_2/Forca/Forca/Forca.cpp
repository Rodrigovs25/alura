#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "nao_acertou.hpp"
#include "letra_existe.hpp"
#include "nao_enforcou.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "salva_arquivo.hpp"
#include "adiciona_palavra.hpp"

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

int main(int argc, char const *argv[]){

    imprime_cabecalho();

    le_arquivo();
    sorteia_palavra();

    while(nao_acertou() && nao_enforcou()){

        imprime_erros();

        imprime_palavra();

        chuta();
    }

    cout << "Fim de Jogo" << endl;
    cout << "Palavra secreta: " << palavra_secreta << endl;

    if(nao_acertou()){
        cout << "Voce perdeu!" << endl;
    }
    else {
        cout << "Voce Ganhou" << endl;

        cout << "Deseja adicionar uma nova palavra ao banco? (S/N):";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        } 
    }
    
    //cin.get()

    return 0;
}

//g++ jogo_da_forca.cpp -std=c++11
//./a.out

//windows mingw32-make forca

//g++ *.cpp -o forca.out -> compilar todos os arquivos .cpp

//ctrl + d -> selecionar todos juntos

// extern: variavel existe em algum lugar, n precisar define ela aqui

// #pragma once // evitar os includes duplicados, o arquivo só deve ser incluido uma vez

//g++ -c adiciona_palavra.cpp -> o -c mandar o compilador só compilar o arquivo, gerar o .o (codigo objeto)

//cat nome_arquivo -> ler o arquivo no terminal

//g++ -c *.cpp -> gerar os objetos de todos os objetos(unidade de tradução)

//g++ *.o -o forca.out -> linkar,juntar todos os arquivos e jogar no .out

//https://faculty.cs.niu.edu/~mcmahon/CS241/Notes/build.html

/*
"F"
"D"
"G"
*/