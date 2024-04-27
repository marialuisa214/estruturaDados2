#include <stdio.h>

int mediana(int *vetor, int inicio, int fim) {
    int a = vetor[inicio];
    int b = vetor[(inicio + fim) / 2];
    int c = vetor[fim];

    if ((a > b && a < c) || (a < b && a > c)) {
        return inicio;
    } else if ((b > a && b < c) || (b < a && b > c)) {
        return (inicio + fim) / 2;
    } else {
        return fim;
    }
}

int separa(int *vetor, int i, int f) {
    int valorMedio = mediana(vetor, i, f);

    int aux = vetor[valorMedio];
    vetor[valorMedio] = vetor[f];
    vetor[f] = aux;

    int pivo = vetor[f];
    int j = i;

    // j elementos menores que pivo
    // k elementos maiores que pivo
    for (int k = i; k < f; k++) {
        if (vetor[k] < pivo) {
            int aux = vetor[j];
            vetor[j] = vetor[k];
            vetor[k] = aux;
            j++;
        }
    }
    int auxPivo = vetor[j];
    vetor[j] = vetor[f];
    vetor[f] = auxPivo;
    return j;
}
void quickSort(int *vetor, int inicio, int fim) {
    if (fim <= inicio) {
        return;
    }
    int j = separa(vetor, inicio, fim);
    quickSort(vetor, inicio, j - 1);
    quickSort(vetor, j + 1, fim);
}

int main() {
    int vetor[8] = {3, 5, 8, 1, 2, 4, 7, 6};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    quickSort(vetor, 0, 7);

    printf("Vetor ordenado: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", vetor[i]);
    }
}