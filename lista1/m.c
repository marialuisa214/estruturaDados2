#include <stdio.h>
// #include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x) {
    le = le->prox;
    while (le != NULL) {
        if(le->dado == x){
            return le;
        }
        le = le->prox;

    }
    return NULL;
}

celula *busca_rec(celula *le, int x) {
    if(le->prox == NULL){
        return NULL;
    }
    else if (le->prox->dado == x) {
        return le->prox;
    }
    return busca_rec(le->prox, x);
    
}
