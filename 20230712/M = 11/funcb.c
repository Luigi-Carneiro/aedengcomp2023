#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcb.h"

void inicializar(TABELA tabela){
    for (int i = 0; i < M; i++)
        tabela[i] = NULL;
}

int chave(int num){
    return (((num * 2) + 5) % M);
}

int inserir(TABELA tabela, int num){
    int i = chave(num);
    ELEMENTO *anterior = NULL;
    ELEMENTO *e = tabela[i];
    while(e != NULL){
        if (e->numero == num)
            return 0;
        anterior = e;
        e = e->proximo;
    }
    if(e == NULL){
        e = malloc(sizeof(ELEMENTO));
        e->numero = num;
        e->proximo = NULL;
        if(anterior == NULL)
            tabela[i] = e;
        else
            anterior->proximo = e;
    }
    return 1;
}

void printHash(TABELA tabela){
    ELEMENTO *e;
    printf("\nTabela para M = 11:\n\n");
    for(int i = 0; i < M; i++){
        if (tabela[i] != NULL){
            e = tabela[i];
            printf("Posicao %d: ", i);
            while(e != NULL){
                printf("%d -> ", e->numero);
                e = e->proximo;
            }
            printf("NULL\n");
        }
            else
                printf("Posicao %d: NULL\n", i);
    }
}

