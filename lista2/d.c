#include <stdio.h>
#include <stdlib.h>

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
void quickSelection(int *vetor, int inicio, int fim, int k) {
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
void quickSort(int *vetor, int inicio, int fim) {
    if (fim <= inicio) {
        return;
    }
    int j = separa(vetor, inicio, fim);
    quickSort(vetor, j + 1, fim);
    quickSort(vetor, inicio, j - 1);
}

int main() {
    int n, p, x;
    scanf("%d %d %d", &n, &p, &x);

    int *vetor = malloc(n * sizeof(int));

    int i = 0;
    while (i < n) {
        scanf("%d", &vetor[i]);
        i++;
    }
    //  10 produtos
    //  4 paginas - 0 1 2 3
    //  3 produtos por pagina
    // pag 4 - > 1 produto exibido

    int ultimoElemento = (p * x) + x - 1;
    if (ultimoElemento >= n) {
        ultimoElemento = n - 1;
    }
    quickSelection(vetor, 0, n - 1, (p * x));
    if (ultimoElemento != n - 1) {
        quickSelection(vetor, (p * x) + 1, n - 1, ultimoElemento);
    }

    quickSort(vetor, (p * x), ultimoElemento);

    for (int i = (p * x); i <= ultimoElemento; i++) {
        printf("%d\n", vetor[i]);
    }
}
