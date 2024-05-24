#include <stdio.h>

void potencia(int* res, int a, int b){
	*res = 1;
	int i = 0;
	for (i = 0; i < b; ++i){
		*res *= a;
	}
}

int main(int argc, char const *argv[])
{
	int res;
	potencia(&res, 10, 5);
	printf("Res: %d\n", res);

	return 0;
}