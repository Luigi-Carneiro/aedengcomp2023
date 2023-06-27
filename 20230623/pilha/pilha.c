#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializar(PILHA *pilha){
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

int inserirElemento(PILHA *pilha, DADOS novo){
    ELEMENTO *i;
    i = malloc(sizeof(ELEMENTO));
    if (i == NULL)
        return 0;
    
    i->aviao = novo;
    i->proximo = pilha->topo;
    pilha->topo = i;
    pilha->tamanho++;
}

void printPilha(PILHA *pilha){
    tamanhoPilha(*pilha);
    if (pilha->topo == NULL)
        printf("a pilha esta vazia");

    else{
        ELEMENTO *atual = pilha->topo;
        printf("Avioes no pilha:\n", pilha->tamanho);
        while (atual != NULL){
            printf("%s, %d\n", atual->aviao.nome, atual->aviao.identificador);
            atual = atual->proximo;
        }
    }
}

void tamanhoPilha(PILHA pilha){
    printf("a pilha tem %d avioes\n", pilha.tamanho);
}

void liberaAviao(PILHA *pilha, int pos)
{
    if (pilha->topo == NULL)
    printf("o hangar esta vazio");
    PILHA temp;
    inicializar(&temp);
    for (int j = 0; j < pos; j++){
        inserirElemento(&temp, pilha->topo->aviao);
        pop(pilha);
    }
    pop(&temp);
    for (int k = 0; k < pos - 1; k++){
        inserirElemento(pilha, temp.topo->aviao);
        pop(&temp);
    }
}

void pop(PILHA *pilha){
    free(pilha->topo);
    pilha->topo = pilha->topo->proximo;
    pilha->tamanho--;
}