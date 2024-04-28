#include <stdio.h>
#include <stdlib.h>

int *concatena(int *vetor, int *vetor2, int tamanho, int tamanho2,
               int tamanhoFinal) {
    int i = 0;
    int j = 0;
    int k = 0;

    int *vetor3 = malloc(tamanhoFinal * sizeof(int));

    while (i < tamanho && j < tamanho2) {
        if (vetor[i] < vetor2[j]) {
            vetor3[k] = vetor[i];
            i++;
        } else {
            vetor3[k] = vetor2[j];
            j++;
        }
        k++;
    }

    if (i < tamanho) {
        while (i < tamanho) {
            vetor3[k] = vetor[i];
            i++;
            k++;
        }
    } else {
        while (j < tamanho2) {
            vetor3[k] = vetor2[j];
            j++;
            k++;
        }
    }
    free(vetor);
    free(vetor2);
    return vetor3;
}

int main() {
    int i = 0;
    int tamanho;
    int tamanho2;
    int tamanhoFinal;
    scanf("%d", &tamanho);
    int *vetor = malloc(tamanho * sizeof(int));
    int j = 0;

    while (j < tamanho) {
        scanf("%d", &vetor[j]);
        j++;
    }

    while (i < 7) {
        scanf("%d", &tamanho2);
        int *vetor2 = malloc(tamanho2 * sizeof(int));

        int j = 0;
        while (j < tamanho2) {
            scanf("%d", &vetor2[j]);
            j++;
        }
        tamanhoFinal = tamanho + tamanho2;

        vetor = concatena(vetor, vetor2, tamanho, tamanho2, tamanhoFinal);
        tamanho = tamanhoFinal;

        i++;
    }

    for (int i = 0; i < tamanhoFinal; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}