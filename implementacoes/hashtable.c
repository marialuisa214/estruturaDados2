#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct no {
    int key; // inteiro de 3 digitos
    // char nome[10];     // valor real
    struct no *proxNo; // no -> proxNo ->  ...
} no;

typedef struct tabelaHash {
    int tamanho;
    no **tabela;
} tabelaHash;

tabelaHash *criaHash(int tamanho) {
    tabelaHash *novaHash = malloc(sizeof(tabelaHash) * tamanho);
    novaHash->tamanho = tamanho;
    novaHash->tabela = (no **)malloc(
        sizeof(no *) * tamanho); // tabela de verdade, aloco os  | no | no | no
                                 // | * tamanho que é passado
    for (int i = 0; i < tamanho; i++) {
        novaHash->tabela[i] = NULL;
    }
    return novaHash;
}

void insereHash(tabelaHash *hash, int value) {
    int posicao = value % hash->tamanho;
    printf("%resto: d\n", posicao);

    if (hash->tabela[posicao] == NULL) {
        hash->tabela[posicao] = (no *)malloc(sizeof(no));
        hash->tabela[posicao]->key = value;
        hash->tabela[posicao]->proxNo = NULL;

    } else {
        no *cabeca = hash->tabela[posicao];
        while (cabeca->proxNo != NULL) {
            cabeca = cabeca->proxNo;
        }

        no *novoNo = malloc(sizeof(no));
        novoNo->key = value;
        novoNo->proxNo = NULL;
        cabeca->proxNo = novoNo;
    }
}

void imprimeHash(tabelaHash *hash) {
    for (int i = 0; i < hash->tamanho; i++) {
        printf("Índice %d: ", i);
        no *temp = hash->tabela[i];
        if (temp == NULL) {
            printf("NULL\n");
        } else {
            while (temp != NULL) {
                printf("%d -> ", temp->key);
                temp = temp->proxNo;
            }
            printf("NULL\n");
        }
    }
}

int main() {

    tabelaHash *hash = criaHash(SIZE);

    int valorNovoNo;
    while (scanf("%d", &valorNovoNo) != EOF) {
        insereHash(hash, valorNovoNo);
    }

    imprimeHash(hash);
}