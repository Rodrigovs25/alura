#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(){

	printf("\n\n");
	printf("			 _   |~  _								\n");
	printf("			[_]--'--[_]		Bem vindo ao		\n");
	printf("			|'|""`""|'|		 Jogo de adivinhacao!	\n");
	printf("			| | /^\\ | | 							\n");// \\ para imprimir a barra
	printf("			|_|_|I|_|_|								\n");
	printf("\n\n");

	srand(time(NULL));
	
	int numeroSecreto = rand()%100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;

	int acertou = 0;

	int nivel;
	printf("Qual o nivel de dificuldade?\n");
	printf("(1) Facil (2) Medio (3) Dificil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);

	int numeroTentativas;

	switch(nivel){
		case 1:
			numeroTentativas = 20;
			break;

		case 2:
			numeroTentativas = 15;
			break;

		default:
			numeroTentativas = 6;
			break;

	}
	

	int i;
	for(i = 1; i <= numeroTentativas; i++){

		printf("Tentativa %d\n", tentativas);
		printf("Qual eh o seu chute? ");
		
		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);

		acertou = (numeroSecreto == chute);
		int maior = chute > numeroSecreto;
		
		if(chute < 0){
			printf("Voce nao pode chutar numeros negativos\n");
			continue; 
		}

		if(acertou){ 
			break;
		}
		
		else if(maior){
			printf("Seu chute foi maior que o numero secreto\n");
		}

		else{ 
			printf("Seu chute foi menor que o numero secreto\n");
		}

		tentativas++;

		double pontosPerdidos = abs(chute - numeroSecreto)/ (double)2;
		pontos -= pontosPerdidos;

	}

	printf("Fim de jogo!\n");

	if (acertou){
		printf("Voce ganhou!\n");

		printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
		printf("Voce acertou em %d tentativas\n", tentativas);
		
		printf("Total de pontos: %.1f\n", pontos);
	} else {

		printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

		printf("Voce perdeu! Tente de novo!\n");
	}

}