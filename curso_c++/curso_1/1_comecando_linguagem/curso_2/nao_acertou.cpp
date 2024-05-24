#include "nao_acertou.hpp"

bool Forca::nao_acertou(std::string& palavra_secreta, const std::map<char, bool>& chutou){
    for(char letra : palavra_secreta){
        if(chutou.find(letra) == chutou.end() || !chutou.at(letra)){ //se aposição for igual ao final do vector(nao encontrou) ou se chutou na posição da letra for falso
            return true;
        }
    }
    return false;
}