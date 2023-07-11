#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex1.h"

void inicializar(TABELA tabela){

    for (int i = 0; i < N; i++){
        tabela[i] = NULL;
    }
}

int chave(int codigo){
    return (codigo % N);
}

int inserir(TABELA tabela, PACIENTE paciente){
    int i = chave(paciente.codigo);
    while(tabela[i] != NULL && tabela[i]->disponivel != 0){
        if (tabela[i]->codigo == paciente.codigo)
            return 0;
        i = (i + 1) / N;
    }
    if(tabela[i] == NULL){
        tabela[i] = malloc(sizeof(PACIENTE));
        *(tabela[i]) = paciente;
        tabela[i]->disponivel = 1;
    }
    else{
        i++;
        while(tabela[i] != NULL){
            i++;
        }
        tabela[i] = malloc(sizeof(PACIENTE));
        *(tabela[i]) = paciente;
        tabela[i]->disponivel = 1;
    }
    return 1;
}

void printHash(TABELA tabela){
    printf("\n");
    for (int i = 0; i < N; i++){
        if (tabela[i] != NULL){
            printf("\nPaciente %d:\nNome: %s\nCPF: %s\nIdade: %d\n", i+1, tabela[i]->nome, tabela[i]->cpf, tabela[i]->idade);
        }
        else
            printf("\nPaciente %d: \nNULL\n", i+1);
    }
}

void tiraHash(TABELA tabela, int cod){
    int i = chave(cod);
    if (tabela[i] != NULL && tabela[i]->codigo == cod && tabela[i]->disponivel == 1){
        tabela[i]->disponivel = 0;
        free(tabela[i]);
        tabela[i] = NULL;
    }
}