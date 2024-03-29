#include <stdio.h>
#include <stdlib.h>

typedef struct instrucao {
    int cod;
    char comando[16];
} instrucao;

void concatena(instrucao vetor[], int inicio, int meio, int fim) {
    int tamanho = fim - inicio + 1;
    instrucao temp[tamanho];

    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= fim) {
        if (vetor[i].cod <= vetor[j].cod) {
            temp[k++] = vetor[i++];
        } else {
            temp[k++] = vetor[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = vetor[i++];
    }

    while (j <= fim) {
        temp[k++] = vetor[j++];
    }

    for (int m = 0; m < tamanho; m++) {
        vetor[inicio + m] = temp[m];
    }
}

void mergeSort(instrucao vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        concatena(vetor, inicio, meio, fim);
    }
}

int buscaBinaria(instrucao vetorInstrucao[], int qtaInstrucao, int codProcura) {
    int inicio = 0;
    int fim = qtaInstrucao - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetorInstrucao[meio].cod == codProcura) {
            return meio;
        } else if (vetorInstrucao[meio].cod < codProcura) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; 
}

int main() {
    int qtaInstrucao;
    scanf("%d", &qtaInstrucao);

    instrucao vetorInstrucao[qtaInstrucao];

    for (int i = 0; i < qtaInstrucao; i++) {
        scanf("%d %s", &vetorInstrucao[i].cod, vetorInstrucao[i].comando);
    }

    mergeSort(vetorInstrucao, 0, qtaInstrucao - 1);

    int codProcura;
    while (scanf("%d", &codProcura) != EOF) {
        int indice = buscaBinaria(vetorInstrucao, qtaInstrucao, codProcura);
        if (indice != -1) {
            printf("%s\n", vetorInstrucao[indice].comando);
        } else {
            puts("undefined");
        }
    }
    return 0;
    
}
