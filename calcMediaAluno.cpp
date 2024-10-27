#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um aluno
typedef struct {
    char nome[50];
    float media1, media2, mediaGeral;
    int classificacao;
} Aluno;

// Função para calcular a média geral
float calcularMediaGeral(float media1, float media2) {
    return (media1 + media2) / 2;
}

// Função de comparação para ordenação (ordem decrescente)
int compararAlunos(const void *a, const void *b) {
    Aluno *alunoA = (Aluno*)a;
    Aluno *alunoB = (Aluno*)b;
    return alunoB->mediaGeral - alunoA->mediaGeral;
}

int main() {
    int numAlunos;
    printf("Digite o número de alunos: ");
    scanf("%d", &numAlunos);

    Aluno alunos[numAlunos];

    // Leitura dos dados dos alunos
    for (int i = 0; i < numAlunos; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Media da primeira disciplina: ");
        scanf("%f", &alunos[i].media1);
        printf("Media da segunda disciplina: ");
        scanf("%f", &alunos[i].media2);

        // Cálculo da média geral
        alunos[i].mediaGeral = calcularMediaGeral(alunos[i].media1, alunos[i].media2);
    }

    // Ordenação dos alunos
    qsort(alunos, numAlunos, sizeof(Aluno), compararAlunos);

    // Atribuição das classificações
    for (int i = 0; i < numAlunos; i++) {
        alunos[i].classificacao = i + 1;
    }

    // Escrita dos dados em um arquivo
    FILE *arquivo = fopen("classificacao.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Cálculo da média geral da turma
    float mediaTurma = 0;
    for (int i = 0; i < numAlunos; i++) {
        mediaTurma += alunos[i].mediaGeral;
        fprintf(arquivo, "%s\t%.2f\t%.2f\t%.2f\t%d\n", alunos[i].nome, alunos[i].media1, alunos[i].media2,
                alunos[i].mediaGeral, alunos[i].classificacao);
    }
    mediaTurma /= numAlunos;

    fprintf(arquivo, "\nMédia geral da turma: %.2f\n", mediaTurma);

    fclose(arquivo);

    printf("Dados dos alunos armazenados em classificacao.txt\n");

    return 0;
}