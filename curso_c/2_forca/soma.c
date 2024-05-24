#include <stdio.h>

void soma(int* num, int a, int b){
	*num = a + b;
}

int main(int argc, char const *argv[])
{
	
	int a = 5, b = 2, num;
	soma(&num, a, b);
	printf("%d\n", num);

	return 0;
}