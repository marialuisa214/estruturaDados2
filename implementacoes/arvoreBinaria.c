#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int valor;
    struct NO *noEsquerda;
    struct NO *noDireita;
} NO;

NO *insereNo(NO *arvore, int valorNovoNo) {
    if (arvore == NULL) {
        NO *novoNo;
        novoNo = malloc(sizeof(NO));
        novoNo->valor = valorNovoNo;
        novoNo->noDireita = NULL;
        novoNo->noEsquerda = NULL;
        return novoNo;
    }
    if (arvore->valor < valorNovoNo) {
        arvore->noDireita = insereNo(arvore->noDireita, valorNovoNo);
    } else {
        arvore->noEsquerda = insereNo(arvore->noEsquerda, valorNovoNo);
    }
    return arvore;
}

int buscaNo(NO *arvore, int valorBusca) {
    if (arvore == NULL) {
        return 0;
    } else if (arvore->valor == valorBusca) {
        return 1;
    } else {
        if (arvore->valor < valorBusca) {
            return buscaNo(arvore->noDireita, valorBusca);
        } else {
            return buscaNo(arvore->noEsquerda, valorBusca);
        }
    }
}
// Aplicar remocao com WHILE (prof.)
//  NO *removeNO(NO *arvore, NO valorRemocao) {
//      NO *p = arvore;
//      NO *q = arvore

// }

// CHAT GPT REMOCAO
NO *encontraMinimo(NO *raiz) {
    while (raiz->noEsquerda != NULL) {
        raiz = raiz->noEsquerda;
    }
    return raiz;
}

NO *removeNo(NO *raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->noEsquerda = removeNo(raiz->noEsquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->noDireita = removeNo(raiz->noDireita, valor);
    } else {
        if (raiz->noEsquerda == NULL) {
            NO *temp = raiz->noDireita;
            free(raiz);
            return temp;
        } else if (raiz->noDireita == NULL) {
            NO *temp = raiz->noEsquerda;
            free(raiz);
            return temp;
        }

        NO *temp = encontraMinimo(raiz->noDireita);
        raiz->valor = temp->valor;
        raiz->noDireita = removeNo(raiz->noDireita, temp->valor);
    }

    return raiz;
}

void imprimeArvore(NO *arvore) {
    if (arvore != NULL) {
        imprimeArvore(arvore->noEsquerda);
        printf("%d ", arvore->valor);
        imprimeArvore(arvore->noDireita);
    }
}

int main() {
    NO *arvore = NULL;
    arvore = insereNo(arvore, 7);
    arvore = insereNo(arvore, 2);
    arvore = insereNo(arvore, 12);
    arvore = insereNo(arvore, 0);
    arvore = insereNo(arvore, 4);
    arvore = insereNo(arvore, 8);
    arvore = insereNo(arvore, 3);
    arvore = insereNo(arvore, 5);
    arvore = insereNo(arvore, 9);
    arvore = insereNo(arvore, 15);

    printf("Árvore em ordem: \n");
    imprimeArvore(arvore);
    printf("\n");

    int valorRemover = 7;
    arvore = removeNo(arvore, valorRemover);

    printf("Árvore depois da remoção do nó com valor %d:\n", valorRemover);
    imprimeArvore(arvore);
    printf("\n");

    return 0;
}