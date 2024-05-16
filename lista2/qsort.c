#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Aluno contendo ano e nota
typedef struct {
    int ano;
    int nota;
} PessoaQEstuda;

// Função de comparação personalizada para ordenar por ano e depois por nota
int compararAlunos(const void *a, const void *b) {
    // Converte os ponteiros genéricos de void para ponteiros de Aluno
    const Aluno *alunoA = (const Aluno *)a;
    const Aluno *alunoB = (const Aluno *)b;

    // Primeiro, compara os anos
    if (alunoA->ano != alunoB->ano) {
        return alunoA->ano - alunoB->ano; // Ordena por ano crescente
    } else {
        return alunoB->nota - alunoA->nota; // Ordena por nota decrescente se os
                                            // anos forem iguais
    }
}

int main() {
    // Vetor de alunos
    Aluno alunos[] = {
        {2022, 80}, {2020, 90}, {2022, 70}, {2021, 85}, {2020, 75}};
    int n = sizeof(alunos) / sizeof(alunos[0]);

    // Ordena o vetor de alunos usando qsort com a função de comparação
    // personalizada
    qsort(alunos, n, sizeof(Aluno), compararAlunos);

    // Imprime o vetor de alunos ordenado
    printf("Alunos ordenados por ano e depois por nota:\n");
    for (int i = 0; i < n; i++) {
        printf("Ano: %d, Nota: %d\n", alunos[i].ano, alunos[i].nota);
    }

    return 0;
}
