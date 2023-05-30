#include <stdio.h>
#include <stdlib.h>
#include "alunos.h"

TURMA *alocarTurma(int n){
    TURMA *turma = malloc(sizeof(TURMA));
    turma->quantidade = n;
    turma->alunos = malloc(n * sizeof(ALUNO));

    return turma;
}

void liberarTurma(TURMA *turma){
    free(turma->alunos);
    free(turma);

}

TURMA *inserirTurma(TURMA *turma){
    for (int i = 0; i < turma->quantidade; i++){
        printf("insira o codigo do aluno %d\n", i + 1);
        scanf("%d", &(turma->alunos[i].codigo));
        printf("insira o nome do aluno %d\n", i + 1);
        scanf("%s", turma->alunos[i].nome);
        printf("insira a idade do aluno %d\n", i + 1);
        scanf("%d", &(turma->alunos[i].idade));
        printf("insira o coeficiente do aluno %d\n", i + 1);
        scanf("%f", &(turma->alunos[i].coeficiente));
        printf("\n\n");
    }

    return turma;
}

void printAluno(TURMA *turma, int n){
    printf("DADOS DO ALUNO:\n");
    printf("codigo: %d\n", turma->alunos[n].codigo);
    printf("nome: %s\n", turma->alunos[n].nome);
    printf("idade: %d\n", turma->alunos[n].idade);
    printf("coeficiente: %.2f\n", turma->alunos[n].coeficiente);
}

int buscaseq(TURMA *turma, int cod){
    int i;
    for (i = 0; i < turma->quantidade; i++){
        if (turma->alunos[i].codigo == cod){
            return i + 1;
        }
    }

    printf("nao encontrado pela busca sequencial\n");
    return -1;
}

int buscabinrec(TURMA *turma, int cod, int primeiro, int ultimo){
    if (primeiro > ultimo){
        printf("nao encontrado pela busca binaria recursiva\n");
        return -1;
    }
    int meio = (primeiro + ultimo) / 2;
    if (turma->alunos[meio].codigo == cod){
        return meio+1;
    }
    else if (turma->alunos[meio].codigo < cod)
        return buscabinrec(turma, cod, meio + 1, ultimo);
    else
        return buscabinrec(turma, cod, primeiro, meio - 1);
}

void printTurma(TURMA *turma){
    printf("ALUNOS DA TURMA:\n");
    for (int i = 0; i < turma->quantidade; i++){
        printf("codigo aluno %d: %i\n", i+1, turma->alunos[i].codigo);
        printf("nome aluno %d: %s\n", i+1, turma->alunos[i].nome);
        printf("idade aluno %d: %d\n", i+1, turma->alunos[i].idade);
        printf("coeficiente aluno %d: %.2f\n", i+1, turma->alunos[i].coeficiente);
        printf("\n");
    }
}