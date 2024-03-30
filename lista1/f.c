#include <stdio.h>
#include <stdlib.h>
int xmic, ymic;
int xBandido = 0, yBandido = 0;
int minutos = 0;

void invadiu() {
    if (abs(ymic - yBandido) <= 1 && abs(xmic - xBandido) <= 1) {
        minutos += 1;
    }
}

void novaCoordenada(int direcao) {
    if (direcao == 1) {
        yBandido += 1;
    } else if (direcao == 2) {
        yBandido -= 1;
    } else if (direcao == 3) {
        xBandido += 1;
    } else {
        xBandido -= 1;
    }
}

int main() {
    int linhas, colunas;
    scanf("%d  %d", &linhas, &colunas);
    scanf("%d  %d", &xmic, &ymic);

    int passeio;
    scanf("%d", &passeio);

    int direcao;
    while (passeio > 0) {
        scanf("%d", &direcao);
        novaCoordenada(direcao);
        invadiu();
        // printf("%d %d, %d\n", xBandido, yBandido, minutos );

        passeio--;
    }

    printf("%d\n", minutos);
}
