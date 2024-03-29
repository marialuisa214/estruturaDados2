#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int vetor[n];
    int soma = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }
    int media = soma / n;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (vetor[i] > media) {
            vetor[j++] = vetor[i];
        }
    }
    if (j != 0) {
        printf("%d", vetor[0]);
        for (int g = 1; g < j; g++) {
            printf(" %d", vetor[g]);
        }
        printf("\n");
    } else {
        printf("0\n");
    }
}