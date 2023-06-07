#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

#define MAX 100

int main(){
    ListaAlunos lista;
    inicializar(&lista);

    Aluno aluno;

    for (int i = 0; i < MAX; i++){
        printf("insira matricula, nome e idade do aluno %d separados por uma barra de espaco\n", i+1);
        scanf("%d %s %d", &aluno.matricula, &aluno.nome, &aluno.idade);
        inserir(&lista, aluno);
    }

    print(&lista);
    vaziacheia(&lista);

    int antigaMatricula, novaMatricula;
    printf("insira que matricula deseja mudar e seu novo valor\n");
    scanf("%d %d", &antigaMatricula, &novaMatricula);

    alterarMatricula(&lista, antigaMatricula, novaMatricula);

    printf("\n[Lista apos alteracao]\n");
    print(&lista);

    liberar(&lista);

    return 0;
}