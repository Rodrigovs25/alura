#include <stdio.h>
#include <string.h>

void abertura(){
	printf("***************************\n");
	printf("*      Jogo de Forca      *\n");
	printf("***************************\n\n");
}

int main(){

	//Arrays = vetores de 10 posicoes começa com 0
	int notas[10];

	char palavraSecreta[20], word[5];
	word[0] = 'o';
	word[1] = 'i';
	word[2] = '\0'; //o caractere \0 para a string, tipo um while, \0 é final da str
	//função que escrever uma string num array
	sprintf(palavraSecreta, "MELANCIA"); 
	//printf("%s\n", palavraSecreta);
	//printf("%s\n", word);

	int acertou = 0;
	int enforcou = 0;
	int i, j;

	char chutes[26];
	int tentativas = 0;

	abertura();

	do{// 1° executar o bloco e ver a condição
		for (i = 0; i < strlen(palavraSecreta); i++){

			int achou = 0;

			//printf("Estou vendo a letra secreta %d = %c\n", i, palavraSecreta[i]);

			for(j = 0; j < tentativas; j++){
				//printf("-> chute %d = %c\n", j, chutes[j]);
				if(chutes[j] == palavraSecreta[i]){
					//printf("---> chute correto\n");
					achou = 1;
					break;
				}
			}
			if(achou){
				printf("%c", palavraSecreta[i]);
			} else{
				printf("_ ");
			}
			
		}
		printf("\n");

		char chute;
		scanf(" %c", &chute);// o espaço ignora o ENTER no final tipo char, exe: A + ENTER -> enter está ignorado 

		/*for (i = 0; i < strlen(palavraSecreta); ++i){
			printf("Estou vendo a letra %c na posicao %d\n", palavraSecreta[i], i);
			if (palavraSecreta[i] == chute){
				printf("A posicao %d tem essa letra!\n", i);
			}
		}*/ // Impressao da palavra

		chutes[tentativas] = chute;
		tentativas++;

	} while (acertou == 0 && enforcou == 0);// ! nega a variavel boleana acerouu == 0 -> !acertou
	//while -> verifica 1° a condição e executa o bloco

}