#include <stdio.h>

typedef struct PessoaQEstuda {
    double nota;
    int posicaoIndividual;
    int numCandidato;
} PessoaQEstuda;

int compara(PessoaQEstuda a, PessoaQEstuda b) {
    if (a.nota == b.nota) {
        if (a.numCandidato == b.numCandidato)
            return a.posicaoIndividual > b.posicaoIndividual;
        return a.numCandidato > b.numCandidato;
    } else {
        return a.nota < b.nota;
    }
}

int mediana(PessoaQEstuda *vetor, int inicio, int fim) {
    PessoaQEstuda a = vetor[inicio];
    PessoaQEstuda b = vetor[(inicio + fim) / 2];
    PessoaQEstuda c = vetor[fim];

    if ((compara(b, a) && !compara(c, a)) || (compara(a, b) && compara(c, a))) {
        return inicio;
    } else if ((compara(a, b) && !compara(c, b)) ||
               (compara(b, a) && compara(c, b))) {
        return (inicio + fim) / 2;
    } else {
        return fim;
    }
}
int separa(PessoaQEstuda *vetor, int i, int f) {
    int valorMedio = mediana(vetor, i, f);

    PessoaQEstuda aux = vetor[valorMedio];
    vetor[valorMedio] = vetor[f];
    vetor[f] = aux;

    PessoaQEstuda pivo = vetor[f];
    int j = i;

    // j elementos menores que pivo
    // k elementos maiores que pivo
    for (int k = i; k < f; k++) {
        if (compara(vetor[k], pivo)) {
            PessoaQEstuda aux = vetor[j];
            vetor[j] = vetor[k];
            vetor[k] = aux;
            j++;
        }
    }
    PessoaQEstuda auxPivo = vetor[j];
    vetor[j] = vetor[f];
    vetor[f] = auxPivo;
    return j;
}
void quickSort(PessoaQEstuda *vetor, int inicio, int fim) {
    if (fim <= inicio) {
        return;
    }
    int j = separa(vetor, inicio, fim);
    quickSort(vetor, j + 1, fim);
    quickSort(vetor, inicio, j - 1);
}

int main() {
    int casosDeTeste;
    scanf("%d", &casosDeTeste);
    while (casosDeTeste != 0) {
        int m;
        int n;
        scanf("%d %d", &m, &n);
        int tamanho = n * m;
        if (tamanho == 0) {
            printf("\n");
            casosDeTeste--;
            continue;
        }
        PessoaQEstuda vetor[tamanho];
        int i = 1;
        int posicaoNota = 1;
        int numeroCandidato = 1;
        for (int j = 0; j < tamanho; j++) {
            if (posicaoNota > n) {
                posicaoNota = 1;
                numeroCandidato++;
            }

            scanf("%lf", &vetor[j].nota);
            vetor[j].posicaoIndividual = posicaoNota;
            posicaoNota++;
            vetor[j].numCandidato = numeroCandidato;

            // printf("nota: %f, posicaoNota:%d  numCandidato: %d\n",
            //        vetor[j].nota, vetor[j].posicaoIndividual,
            //        vetor[j].numCandidato);
        }

        quickSort(vetor, 0, tamanho - 1);

        printf("%d,%d", vetor[tamanho - 1].numCandidato,
               vetor[tamanho - 1].posicaoIndividual);
        for (int i = tamanho - 2; i >= 0; i--) {
            printf(" %d,%d", vetor[i].numCandidato, vetor[i].posicaoIndividual);
        }
        printf("\n");

        casosDeTeste--;
    }
}