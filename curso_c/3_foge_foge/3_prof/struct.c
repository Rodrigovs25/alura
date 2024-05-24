#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;


int acabou() {
    POSICAO pos;

    int perdeu = !encontramapa(&m, &pos, HEROI);
    int ganhou = !encontramapa(&m, &pos, FANTASMA);

    return ganhou || perdeu;

}

int ehdirecao(char direcao) {
    return
        direcao == ESQUERDA || 
        direcao == CIMA ||
        direcao == BAIXO ||
        direcao == DIREITA;
}

void move(char direcao) {

	if(!ehdirecao(direcao)){
		return;
	}

	int proximo_x = heroi.x;
	int proximo_y = heroi.y;

	switch(direcao) {
		case ESQUERDA:
			proximo_y--;
			break;
		case CIMA:
			proximo_x--;
			break;
		case BAIXO:
			proximo_x++;
			break;
		case DIREITA:
			proximo_y++;
			break;
	}
	
	if(!podeandar(&m, HEROI, proximo_x, proximo_y)){ // limites do mapas
		return;
	}

	andarMapa(&m, heroi.x, heroi.y, proximo_x, proximo_y);
	
	//Atualiza a posicao no mapa	
	heroi.x = proximo_x;
    heroi.y = proximo_y;

}

void fantasmas() {
    MAPA copia;

    copiamapa(&copia, &m);

   	int i, j;
    for(i = 0; i < copia.linhas; i++) {
        for(j = 0; j < copia.colunas; j++) {
            if(copia.matriz[i][j] == FANTASMA) {

                int xdestino;
                int ydestino;

                int encontrou = praondefantasmavai(i, j, &xdestino, &ydestino);

                if(encontrou) {
                    andarMapa(&m, i, j, xdestino, ydestino);
                }
            }
        }
    }

    liberamapa(&copia);
}

int praondefantasmavai(int xatual, int yatual, 
    int* xdestino, int* ydestino) {

    int opcoes[4][2] = { 
        { xatual   , yatual+1 }, 
        { xatual+1 , yatual   },  
        { xatual   , yatual-1 }, 
        { xatual-1 , yatual   }
    };

    srand(time(0));
    int i;
    for( i = 0; i < 10; i++) {
        int posicao = rand() % 4;

        if(podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }

    return 0;

}

int main() {
	
	lemapa(&m);
	encontramapa(&m, &heroi, HEROI);

	do {
		imprimemapa(&m);

		char comando;
		scanf(" %c", &comando);

		move(comando);
		fantasmas();

	} while (!acabou());

	liberamapa(&m);
}
//gcc fogefoge.c mapa.c -o fogefoge.out
//gcc struct.c mapa.c -o struct.out