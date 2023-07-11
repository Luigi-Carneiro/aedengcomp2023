#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex2.h"

void inicializar(TABELA tabela){
    for (int i = 0; i < N; i++)
        tabela[i] = NULL;
}

int chave(int codigo){
    return (codigo % N);
}

int inserir(TABELA tabela, PACIENTE paciente){
    int i = chave(paciente.codigo);
    ELEMENTO *anterior = NULL;
    ELEMENTO *e = tabela[i];
    while(e != NULL){
        if (e->paciente.codigo == paciente.codigo)
            return 0;
        anterior = e;
        e = e->proximo;
    }
    if(e == NULL){
        e = malloc(sizeof(PACIENTE));
        e->paciente = paciente;
        e->proximo = NULL;
        if(anterior == NULL)
            tabela[i] = e;
        else
            anterior->proximo = e;
    }
    return 1;
}

void printHash(TABELA tabela){
    printf("\n");
    for (int i = 0; i < N; i++){
        if (tabela[i] != NULL){
            printf("\nPaciente %d:\nNome: %s\nCPF: %s\nIdade: %d\n", i+1, tabela[i]->paciente.nome, tabela[i]->paciente.cpf, tabela[i]->paciente.idade);
        }
        else
            printf("\nPaciente %d: \nNULL\n", i+1);
    }
}

void tiraHash(TABELA tabela, int cod){
    int i = chave(cod);
    ELEMENTO *e = tabela[i];
    ELEMENTO *anterior = NULL;
    while(e != NULL && e->paciente.codigo != cod){
        anterior = e;
        e = e->proximo;
    }
    if (e == NULL){
        return;
    }
    else if(anterior!= NULL){
        anterior->proximo = e->proximo;
        free(e);
    }
    else{
        tabela[i] = e->proximo;
        free(e);
    }
}