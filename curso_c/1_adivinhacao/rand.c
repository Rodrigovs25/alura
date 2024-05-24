#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	//srand(time(NULL));

	int segundos = time(0);
	srand(segundos);
	
	int n1 = rand();
	int n2 = rand();

	printf("%d %d \n", n1, n2);

}