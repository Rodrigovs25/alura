#include <stdio.h>

int main(){
	
	int a = 3;
	int b = 2;
	//conversao, casting
	double pontos = a / (double)b;
	printf("%f\n", pontos);

	double pi = 3.1415;
	int piConvertido = (int)pi;//o piConvertido perdeu a parte fracionaria

	printf("%f %d\n", pi, piConvertido);

}