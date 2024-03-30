#include <stdio.h>
#include <stdlib.h>


typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// apagar
// void imprime_rec(celula *le) {
//     if (le->prox == NULL) {
//         printf("NULL\n");
//         return;
//     }
//     printf("%d -> ", le->prox->dado);
//     imprime_rec(le->prox);
// }

void insere_inicio(celula *le, int x) {
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->dado = x;
    nova->prox = le->prox;
    le->prox = nova;
}

void insere_antes(celula *le, int x, int y){
    if(le->prox == NULL || le->prox->dado == y ){
        celula *nova;
        nova = malloc (sizeof (celula));
        nova->dado = x;
        nova->prox = le->prox;
        le->prox = nova;
    }else{
        insere_antes(le->prox, x, y);
    }

}


// int main(){
//     celula *lista = malloc(sizeof(celula)); 
//     lista->prox = NULL;
//     celula cabecita;
//     cabecita.prox = lista;

//     // Inserindo valores na lista encadeada
//     insere_inicio(lista, 3);
//     insere_inicio(lista, 2);
//     insere_inicio(lista, 1);
//     insere_antes(lista, 6, 2);
//     insere_antes(lista, 10, 9);
    

//     imprime_rec(&cabecita);
// }