#include <stdio.h> //escrever na tela
#include <stdlib.h> // abs, rand
#include <time.h> // time

//#define NUM_TENTAIVA 5 //constante

int main(){

	//imprime cabeçalho do jogo
	printf("**************************************\n");
	printf("Bem vindo ao nosso jogo de adivinhacao\n");
	printf("**************************************\n");

	srand(time(NULL)); // numeros randomicos, mudar a semente

	int n1 = rand()%100; // resto da divisao numero entre 0 e 99

	//variável que guardar o número 
	int numeroSecreto = n1;
	//printf("O numero %d eh o secreto\n", numeroSecreto); //imprime variavel
	int chute;
	//printf("chute %d\n", chute); //lixo do programa, valores padraos
	//int ganhou = 0;
	int tentativas = 1; //int tenataivas = 0 e tente+1
	int pontos = 1000;

	int nivel;
	printf("Qual o nivel de dificuldade?\n");
	printf("(1) Facil (2) Medio (3) Dificil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);

	int numeroTentativas;
	/*if (nivel == 1){
		numeroTentativas = 20;
	}
	else if (nivel == 2){
		numeroTentativas = 15;
	}
	else {
		numeroTentativas = 6;
	}*/

	switch(nivel){ //parecido com if, nao para a execucao dos outros case
		case 1:
			numeroTentativas = 20;
			break; // o break evitar a execucao das outras linhas
		case 2:
			numeroTentativas = 15;
			break;
		default:
			numeroTentativas = 6;
			break;
	}

	//int i;
	//for(i = 0; i < NUM_TENTAIVA; i++){
	//while(ganhou == 0){
	while(1){//loops infinitos
		//printf("Tentativa %d de %d\n", i+1, NUM_TENTAIVA);
		printf("Tentativa %d\n", tentativas);
		printf("Qual eh o seu chute? ");
		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);

		if(chute < 0){
			printf("Voce nao pode chutar numeros negativos\n");
			//i--;
			continue; // vai para a proxima iteracao, nao executar o resto do programa
		}

		
		int acertou = (numeroSecreto == chute); //0 se eh falso e 1 se for verdadeiro
		int maior = chute > numeroSecreto;
		//int menor = chute < numeroSecreto; 

		if(acertou){ // o que esta dentro dos () resulta em 1, booleano
			printf("Parabens! Voce acertou!\n");
			printf("Jogue de novo, voce eh um bom jogador\n");
			break; // break para a execução do loop
			//ganhou == 1; //funciona como o break
		}
		
		//int maior = chute > numeroSecreto; //dentro desse escopo(else)(chaves) o maior existe
		//declarar a variavel no maior escopo possivel
		else if(maior){
			printf("Seu chute foi maior que o numero secreto\n");
		}
		//int menor = chute < numeroSecreto;
		else {//if (menor){
			printf("Seu chute foi menor que o numero secreto\n");
		}
		//printf("Voce errou!\n");
		//printf("Mas nao desanime, tente de novo\n");
		tentativas += 1; //tentativas++;
		int pontosPerdidos = abs(chute - numeroSecreto)/2.0;
		if (pontosPerdidos < 0){ // digitar numeros menores que o numeroSecreto dar a pontuacao positiva
			pontosPerdidos *= (-1); 
		} 
		pontos -= pontosPerdidos;// funcao modulo absoluto da stdlib
	}
	

	printf("Fim de jogo!\n");
	printf("Voce acertou em %d tentativas\n", tentativas);
	printf("Total de pontos: %d\n", pontos);

}

/*#include <stdio.h>

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	
	printf("%d\n", (x*y));
}*/

/*
int chute = 0;
int numerosecreto = 42;
int acertou = chute == numerosecreto; // comparações
if(acertou) {
    printf("Parabéns! Você acertou!\n");
} else {
    if(chute > numerosecreto) {
        printf("Seu chute foi maior do que o número secreto!\n");
    } 
    if(chute < numerosecreto) {
        printf("Seu chute foi menor do que o número secreto!\n");
    }
}
*/

/*
while(1){

		printf("Tentativa %d\n", tentativas);
		printf("Qual eh o seu chute? ");
		
		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);

		int acertou = (numeroSecreto == chute);
		int maior = chute > numeroSecreto;
		
		if(chute < 0){
			printf("Voce nao pode chutar numeros negativos\n");
			continue; 
		}

		if(acertou){ 
			printf("Parabens! Voce acertou!\n");
			printf("Jogue de novo, voce eh um bom jogador\n");
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
*/