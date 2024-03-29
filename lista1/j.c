#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void imprime (celula *le){
    le = le->prox;
    while(le != NULL){
        printf("%d -> ", le->dado);
        le = le->prox;
    }
    printf("NULL\n");
}

void imprime_rec (celula *le){
    if (le->prox == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);
}

// void inserirElemento(celula **lista, int valor) {
//     celula *novoElemento = (celula *)malloc(sizeof(celula));

//     novoElemento->dado = valor;
//     novoElemento->prox = *lista;
//     *lista = novoElemento;
// }

// int main(){
//     celula *lista = NULL;
//     celula cabecita;

//     // Inserindo valores na lista encadeada
//     inserirElemento(&lista, 3);
//     inserirElemento(&lista, 2);
//     inserirElemento(&lista, 1);
//     cabecita.prox = lista;

//     imprime(&cabecita);

// }