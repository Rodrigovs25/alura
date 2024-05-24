#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int numeros[20][10];
	srand(time(NULL));

	int i, j;
	for(i = 0; i < 20; i++){
		for(j = 0; j < 10; j++){
			numeros[i][j] = rand()%20;
		}
	}

	for(i = 0; i < 20; i++){
		for(j = 0; j < 10; j++){
			printf("%d ", numeros[i][j]);
		}
		printf("\n");
	}


	return 0;
}