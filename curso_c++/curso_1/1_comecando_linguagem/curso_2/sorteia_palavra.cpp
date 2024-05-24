#include <vector>
#include "sorteia_palavra.hpp"
#include "le_arquivo.hpp"

std::string Forca::sorteia_palavra(){
    std::vector<std::string> palavras = le_arquivo();

    srand(time(NULL));
    int indice = rand() % palavras.size();

    return palavras[indice];
}