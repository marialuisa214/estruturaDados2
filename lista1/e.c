#include <stdio.h>
void novaCoordenada(int *x, int *y, int direcao) {
    if (direcao == 1) {
        *y += 1;
    } else if (direcao == 2) {
        *y -= 1;
    } else if (direcao == 3) {
        *x += 1;
    } else {
        *x -= 1;
    }
    return;
}

int main() {
    int linha, coluna;
    scanf("%d %d", &coluna, &linha);

    int ax = 1, ay = 1;
    int bx = coluna, by = linha;

    int qtdMovimentos;
    scanf("%d", &qtdMovimentos);

    int aDirecao, bDirecao;

    int i = 1;
    // printf("Posicao PA (%d,%d) no passo %d\n", ax, ay, i);
    // printf("Posicao Pb (%d,%d) no passo %d\n\n", bx, by, i);
    while (i <= qtdMovimentos) {
        scanf("%d %d", &aDirecao, &bDirecao);

        novaCoordenada(&ax, &ay, aDirecao);
        novaCoordenada(&bx, &by, bDirecao);

        // printf("Posicao PA (%d,%d) no passo %d\n", ax, ay, i);
        // printf("Posicao Pb (%d,%d) no passo %d\n\n", bx, by, i);

        if (ax == bx && ay == by) {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", ax, by,
                   i);
            return 0;
        } else if (0 >= ax || ax > coluna || 0 >= ay || ay > linha) {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", ax, ay, i);
            return 0;
        } else if (0 >= bx || bx > coluna || 0 >= by || by > linha) {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", bx, by, i);
            return 0;
        }

        i++;
    }
    printf("Nao se encontraram\n");
}