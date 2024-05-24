#include <stdio.h>
#include <string.h>

void abertura(){
	printf("***************************\n");
	printf("*      Jogo de Forca      *\n");
	printf("***************************\n\n");
}

void chuta(char chutes[26], int* tentativas){//ponteiro guardar endereços de memória
	char chute;
	scanf(" %c", &chute);

	chutes[(*tentativas)] = chute;

	(*tentativas)++;
}

// Essa função não foi discutida no último vídeo
int jachutou(char letra, char chutes[26], int tentativas) {
    int achou = 0, j =0;
    for(j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {//letra e a palavra secreta
            achou = 1;
            break;
        }
    }

    return achou;
}



// Essa função não foi discutida no último vídeo
void desenhaForca(char palavraSecreta[20], char chutes[26], int tentativas)  {

    printf("Voce ja deu %d chutes\n", tentativas);
    int i = 0;
    for(i = 0; i < strlen(palavraSecreta); i++) {

        if(jachutou(palavraSecreta[i], chutes, tentativas)) {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

// Essa função não foi discutida no último vídeo
//void escolhePalavra() {//qual variavel vai ser devolvidA
 //   sprintf(palavrasecreta, "MELANCIA");
//}



int main(){

	char palavraSecreta[20];
	sprintf(palavraSecreta, "MELANCIA");

	int acertou = 0;
	int enforcou = 0;
	int i, j;

	char chutes[26];
	int tentativas = 0;

	//printf("%d %d\n", &chutes[0], chutes); //array é um ponteiro que aponta pra 1° posição
	//printf("%d %d %d\n", &chutes[0], &chutes[1], &chutes[2]); // char = 1 byte -> pula de 1 byte, se fosse int ia pular de 4 byte, seq

	abertura();
	//escolhePalavra();

	do{

		//printf("Você já deu %d chutes\n", tentativas);

		/*for (i = 0; i < strlen(palavraSecreta); i++){

			// se a letra já foi chutada?
			/*int achou = 0;

			for(j = 0; j < tentativas; j++){
				if(chutes[j] == palavraSecreta[i]){
					achou = 1;
					break;
				}
			} -> dentro do jachutou

			int achou = jachutou(palavraSecreta[i], chutes, tentativas);

			if(achou){
				printf("%c", palavraSecreta[i]);
			} else{
				printf("_ ");
			}
			
		}*/ //-> dentro da desenhaForca()
		printf("\n");

		desenhaForca(palavraSecreta, chutes, tentativas);

		chuta(chutes, &tentativas);

		//tentativas++; mudei para a funcao chuta

	} while (!acertou && !enforcou);

}

/*
Ela recebe três parâmetros: o arquivo, quantos bytes 
ela deve andar (para a esquerda ou para a direita) 
e da onde ela deve começar a andar (do começo do 
arquivo, da posição corrente, ou do final). Vamos 
posicioná-la então "0 bytes" a partir do começo do arquivo:

Repare que SEEK_SET é uma constante. Poderíamos usar 
também as SEEK_CUR para andar a partir do ponto atual, 
ou mesmo SEEK_END, para andar a partir do fim do 
arquivo. Com o ponteiro posicionado na posição que 
queremos, basta agora escrevermos a variável qtd, 
usando o fprintf(). A máquina não pensará duas vezes 
e escreverá por cima do que está naquela posição:


Podemos verificar também se o ponteiro atual do
arquivo está apontando para o fim. Para isso, basta usar 
a função feof(). Ele pode ser bastante útil quando queremos
ler o arquivo inteiro até o fim. Por exemplo, se quisermos 
ler caractere a caractere do arquivo e imprimí-lo, precisamos 
repetir isso enquanto não chegarmos ao fim do arquivo.

Por enquanto, a única função de leitura que vimos até então 
é a fscanf(). Ela é importante quando queremos ler caracteres 
ASCII e strings. Mas, muitas vezes precisamos ler um byte, um 
char, ou mesmo uma struct (que aprenderemos no próximo jogo). 
Nesses casos, precisamos ler e escrever dados de maneira "mais 
bruta". A função fgetc(), por exemplo, lê apenas o próximo char.

FILE* f;
char c;

f = fopen("arquivo.txt", "r");
while(!feof(f)) {
    c = fgetc(f);    
    printf("Char %c\n", c);
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;


int letraexiste(char letra) {

    for(int j = 0; j < strlen(palavrasecreta); j++) {
        if(letra == palavrasecreta[j]) {
            return 1;
        }
    }

    return 0;
}

int chuteserrados() {
    int erros = 0;

    for(int i = 0; i < chutesdados; i++) {

        if(!letraexiste(chutes[i])) {
            erros++;
        }
    }

    return erros;
}

int enforcou() {
    return chuteserrados() >= 5;
}

int ganhou() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }

    return 1;
}


void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    if(letraexiste(chute)) {
        printf("Você acertou: a palavra tem a letra %c\n\n", chute);
    } else {
        printf("\nVocê errou: a palavra NÃO tem a letra %c\n\n", chute);
    }

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca() {

    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void escolhepalavra() {
    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}


void adicionapalavra() {
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);

    if(quer == 'S') {
        char novapalavra[TAMANHO_PALAVRA];

        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf("%s", novapalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");
        if(f == 0) {
            printf("Banco de dados de palavras não disponível\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);

    }

}

int main() {

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());

    if(ganhou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adicionapalavra();
}
*/