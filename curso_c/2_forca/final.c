#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;

void abertura(){
	printf("***************************\n");
	printf("*      Jogo de Forca      *\n");
	printf("***************************\n\n");
}

void chuta(){//ponteiro guardar endereços de memória
	char chute;
	scanf(" %c", &chute);

	chutes[chutesDados] = chute;

	chutesDados++;
}

int jachutou(char letra){
    int achou = 0, j =0;
    for(j = 0; j < chutesDados; j++) {
        if(chutes[j] == letra) {//letra e a palavra secreta
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaForca(){

	
	/*printf("  _______       \n");
	printf(" |/      |      \n");
	printf(" |      %c%c%c  \n", '(', '_', ')');
	printf(" |      %c%c%c  \n", '\\', '|', '/');
	printf(" |       %c     \n", '|');
	printf(" |      %c %c   \n", '/', '\\');
	printf(" |              \n");
	printf("_|___           \n");

	printf("\n\n");*/

	int erros = chutesErrados();

	printf("  _______       \n");
	printf(" |/      |      \n");
	printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
	    (erros>=1?'_':' '), (erros>=1?')':' '));
	printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), 
	    (erros>=2?'|':' '), (erros>=3?'/': ' '));
	printf(" |       %c     \n", (erros>=2?'|':' '));
	printf(" |      %c %c   \n", (erros>=4?'/':' '), 
	    (erros>=4?'\\':' '));
	printf(" |              \n");
	printf("_|___           \n");
	printf("\n\n");

    // duas \\ para evitar o barra n 

    //printf("Voce ja deu %d chutes\n", chutesDados);
    int i = 0;
    for(i = 0; i < strlen(palavraSecreta); i++) {

        if(jachutou(palavraSecreta[i])) {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void adicionaPalavra(){
	printf("Deseja adiciona uma palavra? (S/N)\n");
	char quer;
	char novaPalavra[TAMANHO_PALAVRA];

	scanf(" %c", &quer);

	if (quer == 'S'){
		printf("Qual e a palavra? \n");
		scanf("%s", &novaPalavra);

		FILE* f;
		f = fopen("palavras.txt", "r+");// r+ leitura e escrita


        if(f == NULL){
	    	printf("Falha no arquivo\n");
	    	exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);// apontar para a linha anterior, no caso a 1°
        // SEEK_SET -> apontar, voltou para o incio, começo
        fprintf(f, "%d", qtd);


        fseek(f, 0, SEEK_END);// final do arquivo, final
		fprintf(f, "\n%s", novaPalavra);

		fclose(f);
	}
}

void escolhePalavra(){//qual variavel vai ser devolvidA
    //sprintf(palavraSecreta, "MELANCIA");

	FILE* f;
    f = fopen("palavras.txt", "r");//r = ler, w = white, a = escrecer no final

    if(f == NULL){
    	printf("Falha no arquivo\n");
    	exit(1);
    }

    int qtdPalavras;
    fscanf(f, "%d", &qtdPalavras);

    srand(time(NULL));
    int num = rand() % qtdPalavras;

    int i;
    for (i = 0; i <= num; i++){
    	fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

int chutesErrados(){
	int i, j, erros = 0;
	for(i = 0; i < chutesDados; i++){
		int existe = 0;
		for(j = 0; j < strlen(palavraSecreta); j++){
			if(chutes[i] == palavraSecreta[j]){
				existe = 1;
				break;
			}
		}
		if(!existe) erros++;
	}

	return erros;
}

int enforcou(){
	
	return chutesErrados() >= 5;// se for verdade returnar 1
}

int acertou(){
	int i;
	for (i = 0; i < strlen(palavraSecreta); ++i){// verificando se ja chutou letra por letra
		if(!jachutou(palavraSecreta[i])){
			return 0;
		}
	}
	return 1;
}

int main(){

	/* // variaveis globais, tirar os ponteiros, pode ser acessao por tudo o codigo
	char palavraSecreta[TAMANHO_PALAVRA];
	char chutes[26];
	int chutesDados = 0;
	*/
	//int acertou = 0; tem função
	//int enforcou = 0; tem a funcao

	escolhePalavra();
	
	abertura();

	do{

		desenhaForca();
		chuta(chutes);

	} while (!acertou() && !enforcou());

	//adicionaPalavra();

	if(acertou()) {
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
	    printf("A palavra era **%s**\n\n", palavraSecreta);

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
}

