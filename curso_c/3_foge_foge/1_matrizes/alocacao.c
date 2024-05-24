#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	
	int linhas = 5;
	int colunas = 10;

	int** matriz = malloc(sizeof(int*) * linhas);
	int i;
	for(i < 0; i < linhas; i++){
		matriz[i] = malloc(sizeof(int) * colunas);
	}

	for(i < 0; i < linhas; i++){
		free(matriz[i]);
	}
	free(matriz);

	return 0;
}