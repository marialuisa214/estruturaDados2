#include <stdio.h>
// #include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// //

// void imprime_rec(celula *le) {
//     if (le->prox == NULL) {
//         printf("NULL\n");
//         return;
//     }
//     printf("%d -> ", le->prox->dado);
//     imprime_rec(le->prox);
// }

// void insere_inicio(celula *le, int x) {
//     celula *nova;
//     nova = malloc(sizeof(celula));
//     nova->dado = x;
//     nova->prox = le->prox;
//     le->prox = nova;
// }

// void insere_antes(celula *le, int x, int y) {
//     if (le->prox == NULL || le->prox->dado == y) {
//         celula *nova;
//         nova = malloc(sizeof(celula));
//         nova->dado = x;
//         nova->prox = le->prox;
//         le->prox = nova;
//     } else {
//         insere_antes(le->prox, x, y);
//     }
// }

// //

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    l1 = l1->prox;
    l2 = l2->prox;

    while (l1 != NULL && l2 != NULL) {
        if (l1->dado <= l2->dado) {
            l3->prox = l1;
            l1 = l1->prox;
        } else {
            l3->prox = l2;
            l2 = l2->prox;
        }
        l3 = l3->prox;
    }

    if (l1 != NULL) {
        l3->prox = l1;
    } else {
        l3->prox = l2;
    }
    return;
}

// int main() {
//     // celula *lista1 = malloc(sizeof(celula));
//     // lista1->prox = NULL;
//     celula cabecita1;
//     cabecita1.prox = NULL;

//     // Inserindo valores na lista encadeada
//     insere_inicio(&cabecita1, 10);
//     insere_inicio(&cabecita1, 9);
//     insere_inicio(&cabecita1, 7);
//     insere_inicio(&cabecita1, 1);

//     imprime_rec(&cabecita1);

//     // celula *lista2 = malloc(sizeof(celula));
//     // lista2->prox = NULL;
//     celula cabecita2;
//     cabecita2.prox = NULL;

//     insere_inicio(&cabecita2, 8);
//     insere_inicio(&cabecita2, 3);
//     insere_inicio(&cabecita2, 2);

//     imprime_rec(&cabecita2);

//     celula cabecita3;

//     mescla_listas(&cabecita1, &cabecita2, &cabecita3);

//     imprime_rec(&cabecita3);
// }