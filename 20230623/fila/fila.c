#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializar(FILA *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

int inserirElemento(FILA *fila, DADOS novo){
    ELEMENTO *i;
    i = malloc(sizeof(ELEMENTO));
    if (i == NULL)
        return 0;

    i->aviao = novo;
    i->proximo = NULL;
    if(fila->primeiro == NULL)
        fila->primeiro = i;

    else
        fila->ultimo->proximo = i;

    fila->ultimo = i;
    fila->tamanho++;
    return 1;
}

void tamanhoFila(FILA fila){
    printf("a fila tem %d avioes\n", fila.tamanho);
}

int decolagem(FILA *fila){
    if (fila->primeiro == NULL)
        return 0;
    ELEMENTO *primeiro = fila->primeiro;
    printf("o aviao %s de codigo %d decolou\n", primeiro->aviao.nome, primeiro->aviao.identificador);
    fila->primeiro = fila->primeiro->proximo;
    free(primeiro);
    fila->tamanho--;
    return 1;
}

int printFila(FILA *fila){
    tamanhoFila(*fila);
    if (fila->primeiro == NULL){
        printf("a fila esta vazia\n");
        return 0;
    }
    ELEMENTO *atual = fila->primeiro;
    printf("avioes na fila:\n");
    while(atual != NULL){
        printf("%s, %d\n", atual->aviao.nome, atual->aviao.identificador);
        atual = atual->proximo;
    }
}

int primeiroElemento(FILA *fila){
    if (fila->primeiro == NULL){
        printf("a fila esta vazia\n");
        return 0;
    }
    ELEMENTO *atual = fila->primeiro;
    printf("o primeiro aviao da fila eh o %s de codigo %d\n", atual->aviao.nome, atual->aviao.identificador);
}