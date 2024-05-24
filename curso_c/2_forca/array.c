#include <stdio.h>

int soma(int nums[], int a){
	int i = 0, soma = 0;
	for(i = 0; i < a; i++){
		soma += nums[i];
	}
	return soma;
}


int main(int argc, char const *argv[])
{
	int nums[3];
	nums[0] = 10;
	nums[1] = 20;
	nums[2] = 30;

	int total = soma(nums, 3);
	printf("%d\n", total);
	
	return 0;
}