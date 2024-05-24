#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

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

bool nao_acertou(){
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}
void cabecalho(){
    cout << "*******************" << endl;
    cout << "***Jogo da Forca***" << endl;
    cout << "*******************" << endl;
    cout << endl;
}
void imprime_erros(){
    cout << "chutes errados: ";
    for(char letra : chutes_errados){
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra(){
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            cout << letra << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta(){
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[chute] = true;

    if(letra_existe(chute)){
        cout << "O chute está na palavra" << endl;
    }
    else{
        cout << "O chute não está na palavra" << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}

vector<string> le_arquivo(){
    //ler um arquivo
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){

        int quantidade_palavra;
        arquivo >> quantidade_palavra;

        
        vector<string> lista;

        for(int i=0; i<quantidade_palavra; i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            lista.push_back(palavra_lida);
        }
        cout << endl;

        arquivo.close();

        return lista;
    }
    else{
        cout << "Nao foi possivel acessar o arquivo" << endl;
        exit(0);//parar a execucção do programa
    }
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice = rand() % palavras.size();

    palavra_secreta = palavras[indice];

}

void salva_arquivo(vector<string> nova_lista){
    ofstream arquivo;//escrever no arquivo
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){
        arquivo << nova_lista.size() << endl;
        for(string palavra : nova_lista){
            arquivo << palavra << endl;
        }
        arquivo.close();
    }
    else{
        cout << "Nao foi possivel acessar o arquivo" << endl;
        exit(0);//parar a execucção do programa
    }
}

void adiciona_palavra(){
    cout << "Digite a nova palavra(maiuscula): " << endl;
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
}



int main(int argc, char const *argv[]){

    cabecalho();

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
    
    return 0;
}

//g++ jogo_da_forca.cpp -std=c++11
//./a.out

//windows mingw32-make forca

/*
"F"
"D"
"G"
*/