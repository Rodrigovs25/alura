#include "letra_existe.hpp"

bool Forca::letra_existe(char chute, std::string& palavra_secreta){
    // for (int i = 0; i < palavra_secreta.size(); i++){
    //     if(chute == palavra_secreta[i]){
    //         return true;
    //     }
    // } ctrl + / -> barra e desbarra
    for(char letra : palavra_secreta){//c++11, outra forma de fazer o for
        if(chute == letra){
            return true;
        }
    }
    return false;
}
