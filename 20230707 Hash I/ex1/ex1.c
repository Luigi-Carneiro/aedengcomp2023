#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex1.h"

void inicializar(TABELA tabela){
    for (int i = 0; i < N; i++)
        tabela[i] = NULL;
}

int chave(int codigo){
    return (codigo % N);
}

int inserir(TABELA tabela, PACIENTE paciente){
    int i = chave(paciente.codigo);
    while(tabela[i] != NULL){
        if (tabela[i]->codigo == paciente.codigo)
            return 0;
        i = (i + 1) / N;
    }
    if(tabela[i] == NULL){
        tabela[i] = malloc(sizeof(PACIENTE));
        *(tabela[i]) = paciente;
    }
    else{
        i++;
        while(tabela[i] != NULL){
            i++;
        }
        tabela[i] = malloc(sizeof(PACIENTE));
        *(tabela[i]) = paciente;
    }
    return 1;
}

void printHash(TABELA tabela){
    printf("\n");
    for (int i = 0; i < N; i++){
        if (tabela[i] != NULL){
            printf("\n");
            printf("Paciente %d:\nNome: %s\nCPF: %s\nIdade: %d\n", i+1, tabela[i]->nome, tabela[i]->cpf, tabela[i]->idade);
        }
        else
            printf("PACIENTE %d: \nNULL", i);
    }
}