#include <stdio.h>
#include <stdlib.h>

//[linha][coluna], matriz // string termina com \0, então tem que ler o \0
//char mapa[5][10+1];
char** mapa; 
int linhas;
int colunas;

void alocaMapa(){
	mapa = malloc(sizeof(char*) * linhas);
	int i;
	for(i = 0; i < linhas; i++){
		mapa[i] = malloc(sizeof(char) * (colunas+1));// tem o barra \0
	}
}

void leMapa(){

	FILE* arq;
	arq = fopen("mapa.txt", "r");

	if(arq == NULL){
		printf("Erro na leitura do arquivo\n");
		exit(1);
	}

	fscanf(arq, "%d %d", &linhas, &colunas);
	//printf("linhas %d colunas %d\n", linhas, colunas);

	alocaMapa();
	int i;
	for(i = 0; i < linhas; i++){ //1 dimensao da matriz devolve um array
		fscanf(arq, "%s", mapa[i]); // ler a primeira dimensao so a linha
	}
	fclose(arq);
}

void liberaMapa(){
	int i;
	for (i = 0; i < linhas; i++){
		free(mapa[i]);
	}
	free(mapa);
}

int main(int argc, char const *argv[]){

	//mapa[0][0] = '|';
	//mapa[4][9] = '|';

	//printf("%c %c\n", mapa[0][0], mapa[4][9]);

	leMapa();
	///////////
	/*
	//sizeof(devolve qts bytes e necessario)
	char* c = malloc(sizeof(char)); //1 byte malloc(1)
	int* v = malloc(sizeof(int)); // memory allocation, 4 bytes inteiro
	int* z = malloc(sizeof(int) * 50); // aaray de 50 posicoes
	*v = 10;
	z[0] = 5;
	z[1] = 9;
	printf("Int alloc %d\n", *v);
	printf("Vetor alloc %d, %d\n", z[0], z[1]);
	free(v); //desaloca
	
	

	int i;
	// alocando espaço para as linhas,
	// que guardam ponteiro de inteiro.
	int** matriz = malloc(sizeof(int*) * linhas);

	// agora, para cada linha, alocamos
	// espaço para um array com 10 ("colunas") posições.
	for(int i = 0; i < linhas; i++) {
	    matriz[i] = malloc(sizeof(int) * colunas);
	}

	//desaloca matriz
	for(i = 0; i < linhas; i++){
		free(matriz[i]);
	}
	free(matriz);

	*/
	//////////

	int i;
	for(i = 0; i < linhas; i++){
		printf("%s\n", mapa[i]); // ler a primeira dimensao so a linha
	}

	liberaMapa();

	return 0;
}