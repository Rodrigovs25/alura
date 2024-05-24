#include <vector>
#include <string>
#include "sorteia_palavra.hpp"
#include "le_arquivo.hpp"

extern std::string palavra_secreta;

void sorteia_palavra(){
    std::vector<std::string> palavras = le_arquivo();

    srand(time(NULL));
    int indice = rand() % palavras.size();

    palavra_secreta = palavras[indice];

}