#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long vetor[n];
    long soma = 0;
    for (int i = 0; i < n; i++) {
        scanf("%ld", &vetor[i]);
        soma += vetor[i];
    }
    long media = soma / n;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (vetor[i] > media) {
            vetor[j++] = vetor[i];
        }
    }
    if (j != 0) {
        printf("%ld", vetor[0]);
        for (int g = 1; g < j; g++) {
            printf(" %ld", vetor[g]);
        }
        printf("\n");
    } else {
        printf("0\n");
    }
}