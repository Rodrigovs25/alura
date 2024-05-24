#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "nao_acertou.hpp"
#include "letra_existe.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "salva_arquivo.hpp"
#include "adiciona_palavra.hpp"

using namespace std;

static string palavra_secreta;
static map<char, bool> chutou;
static vector<char> chutes_errados;

int main(int argc, char const *argv[]){

    Forca::imprime_cabecalho();

    //le_arquivo(); // chamada inutil tem no sorteia palavra
    palavra_secreta = Forca::sorteia_palavra();

    while(Forca::nao_acertou(palavra_secreta, chutou) && chutes_errados.size() < 5){

        Forca::imprime_erros(chutes_errados);
        //imprime_erros(chutes_errados);

        Forca::imprime_palavra(palavra_secreta, chutou);

        Forca::chuta(chutou, chutes_errados, palavra_secreta);
    }

    cout << "Fim de Jogo" << endl;
    cout << "Palavra secreta: " << palavra_secreta << endl;

    if(Forca::nao_acertou(palavra_secreta, chutou)){
        cout << "Voce perdeu!" << endl;
    }
    else {
        cout << "Voce Ganhou" << endl;

        cout << "Deseja adicionar uma nova palavra ao banco? (S/N):";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            Forca::adiciona_palavra();
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