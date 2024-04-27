#include <stdio.h>
#include <stdlib.h>

typedef struct semente {
    int cod;
    int nota;
} semente;

int compara(semente a, semente b) {
    if (a.nota == b.nota) {
        return a.cod < b.cod;
    } else {
        return a.nota < b.nota;
    }
}

int mediana(semente *vetor, int inicio, int fim) {
    semente a = vetor[inicio];
    semente b = vetor[(inicio + fim) / 2];
    semente c = vetor[fim];

    if ((compara(b, a) && !compara(c, a)) || (compara(a, b) && compara(c, a))) {
        return inicio;
    } else if ((compara(a, b) && !compara(c, b)) ||
               (compara(b, a) && compara(c, b))) {
        return (inicio + fim) / 2;
    } else {
        return fim;
    }
}

int medianaCodigo(semente *vetor, int inicio, int fim) {
    semente a = vetor[inicio];
    semente b = vetor[(inicio + fim) / 2];
    semente c = vetor[fim];

    if ((a.cod > b.cod && a.cod < c.cod) || (a.cod < b.cod && a.cod > c.cod)) {
        return inicio;
    } else if ((b.cod > a.cod && b.cod < c.cod) ||
               (b.cod < a.cod && b.cod > c.cod)) {
        return (inicio + fim) / 2;
    } else {
        return fim;
    }
}

int separa(semente *vetor, int i, int f) {
    int valorMedio = mediana(vetor, i, f);

    semente aux = vetor[valorMedio];
    vetor[valorMedio] = vetor[f];
    vetor[f] = aux;

    semente pivo = vetor[f];
    int j = i;

    // j elementos menores que pivo
    // k elementos maiores que pivo
    for (int k = i; k < f; k++) {
        if (compara(vetor[k], pivo)) {
            semente aux = vetor[j];
            vetor[j] = vetor[k];
            vetor[k] = aux;
            j++;
        }
    }
    semente auxPivo = vetor[j];
    vetor[j] = vetor[f];
    vetor[f] = auxPivo;
    return j;
}

int separaCodigo(semente *vetor, int i, int f) {
    int valorMedio = medianaCodigo(vetor, i, f);

    semente aux = vetor[valorMedio];
    vetor[valorMedio] = vetor[f];
    vetor[f] = aux;

    semente pivo = vetor[f];
    int j = i;

    // j elementos menores que pivo
    // k elementos maiores que pivo
    for (int k = i; k < f; k++) {
        if (vetor[k].cod < pivo.cod) {
            semente aux = vetor[j];
            vetor[j] = vetor[k];
            vetor[k] = aux;
            j++;
        }
    }
    semente auxPivo = vetor[j];
    vetor[j] = vetor[f];
    vetor[f] = auxPivo;
    return j;
}

void quickSelection(semente *vetor, int inicio, int fim, int k) {
    if (fim <= inicio) {
        return;
    }
    int j = separa(vetor, inicio, fim);
    if (j == k) {
        return;
    }
    if (j > k) {
        quickSelection(vetor, inicio, j - 1, k);
    } else {
        quickSelection(vetor, j + 1, fim, k);
    }
}

void quickSort(semente *vetor, int inicio, int fim) {
    if (fim <= inicio) {
        return;
    }
    int j = separaCodigo(vetor, inicio, fim);
    quickSort(vetor, j + 1, fim);
    quickSort(vetor, inicio, j - 1);
}

int main() {
    int k;
    scanf("%d", &k);
    semente *vetor = malloc(1e7 * sizeof(semente));

    int i = 0;
    while ((scanf("%d %d", &vetor[i].cod, &vetor[i].nota)) != EOF) {
        i++;
    }

    quickSelection(vetor, 0, i - 1, k);
    quickSort(vetor, 0, k - 1);

    for (int j = 0; j < k; j++) {
        printf("%d %d\n", vetor[j].cod, vetor[j].nota);
    }

    return 0;
}