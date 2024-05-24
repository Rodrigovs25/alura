#include <string>
#include "letra_existe.hpp"

extern std::string palavra_secreta;

bool letra_existe(char chute){
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
