#include <iostream>
#include <fstream>
#include "salva_arquivo.hpp"

void Forca::salva_arquivo(std::vector<std::string>& nova_lista){
    std::ofstream arquivo;//escrever no arquivo
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){
        arquivo << nova_lista.size() << std::endl;
        for(std::string palavra : nova_lista){
            arquivo << palavra << std::endl;
        }
        arquivo.close();
    }
    else{
        std::cout << "Nao foi possivel acessar o arquivo" << std::endl;
        exit(0);//parar a execucção do programa
    }
}
