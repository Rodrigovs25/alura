#include <stdio.h>

void calcula(int* c){// vai vim um endereço de memoria de um int
	printf("calcula: %d %d\n", 		*c, &c); // endereço de c da funcao
	(*c)++; // c guarda o enderço de memoria e *c acessa o conteudo do endereço
	printf("calcula: %d %d\n", *c, c); // endereço passada para função
}


int main(int argc, char const *argv[]) // modifique a variavel original
{
	int c = 10;
	printf("main: %d %d\n", c, &c);
	calcula(&c); //& pega o endereço de uma variavel, passa o endereço de memoria
	printf("main: %d %d\n", c, &c);

    int* ponteiro;

    // ponteiro apontando para o mesmo endereco de c
    ponteiro = &c;

    // imprime o endereco da variavel c
    printf("%d %d\n", ponteiro, &c);

    // imprime o conteúdo da variavel c
    printf("%d %d\n", *ponteiro, c);

	return 0;
}	