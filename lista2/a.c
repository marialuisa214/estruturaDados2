#include <stdio.h>

void concatena(int vetor[], int inicio, int fim) {
    int meio = (fim + inicio) / 2;
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    int tamanho = fim - inicio + 1;
    int aux[tamanho];

    while (i <= meio && j <= fim) {
        if (vetor[i] <= vetor[j]) {
            aux[k++] = vetor[i++];
        } else {
            aux[k++] = vetor[j++];
        }
    }

    while (i <= meio) {
        aux[k++] = vetor[i++];
    }
    while (j <= fim) {
        aux[k++] = vetor[j++];
    }

    for (int l = 0; l < tamanho; l++) {
        vetor[inicio + l] = aux[l];
    }
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio == fim) {
        return;
    }
    int meio = (fim + inicio) / 2;
    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio + 1, fim);
    concatena(vetor, inicio, fim);
}

int main() {
    int n;
    scanf("%d", &n);

    int vetor[n];
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    mergeSort(vetor, 0, tamanho - 1);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
