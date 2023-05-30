#include <stdio.h>
#include <stdlib.h>
#include "alunos.h"

int main(){
    int n;

    printf("insira o numero de alunos na turma\n");
    scanf("%d", &n);
    TURMA *turma = alocarTurma(n);
    inserirTurma(turma);

    int cod;
    printf("insira o codigo de um aluno que deseja buscar\n");
    scanf("%d", &cod);

    int auxseq = buscaseq(turma, cod);
    int auxbin = buscabinrec(turma, cod, 0, turma->quantidade - 1);
    if(auxseq > 0 && auxbin > 0)
        printAluno(turma, auxseq - 1);
    if(auxseq > 0)
        printf("o aluno esta na posicao %d segundo a busca sequencial\n", auxseq);
    if(auxbin > 0)
        printf("o aluno esta na posicao %d segundo a busca binaria\n", auxbin);
    printf("\n\n");
    printTurma(turma);
    liberarTurma(turma);
    return 0;
}