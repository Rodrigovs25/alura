#include <iostream>
#include <string>
#include <vector>
#include "adiciona_palavra.hpp"
#include "le_arquivo.hpp"
#include "salva_arquivo.hpp"

void Forca::adiciona_palavra(){
    std::cout << "Digite a nova palavra(maiuscula): " << std::endl;
    std::string nova_palavra;
    std::cin >> nova_palavra;

    std::vector<std::string> lista_palavras = Forca::le_arquivo();
    lista_palavras.push_back(nova_palavra);

    Forca::salva_arquivo(lista_palavras);
}