#include <iostream>
#include <fstream>
#include "le_arquivo.hpp"

std::vector<std::string> Forca::le_arquivo(){
    //ler um arquivo
    std::ifstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){

        int quantidade_palavra;
        arquivo >> quantidade_palavra;

        
        std::vector<std::string> lista;

        for(int i=0; i<quantidade_palavra; i++){
            std::string palavra_lida;
            arquivo >> palavra_lida;
            lista.push_back(palavra_lida);
        }
        std::cout << std::endl;

        arquivo.close();

        return lista;
    }
    else{
        std::cout << "Nao foi possivel acessar o arquivo" << std::endl;
        exit(0);//parar a execucção do programa
    }
}