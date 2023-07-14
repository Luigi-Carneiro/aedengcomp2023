#include <stdio.h>
#include <stdlib.h>
#include "prova.h"

void inicializar(DEQUE *turma){
    turma->cabeca = malloc(sizeof(ELEMENTO));
    turma->cabeca->proximo = turma->cabeca;
    turma->cabeca->anterior = turma->cabeca;
    turma->tamanho = 0;
}

void inserir(DEQUE *turma, int novo){
    ELEMENTO *aux;
    aux = malloc (sizeof(ELEMENTO));
    aux->numeros = novo;
    aux->proximo = turma->cabeca->proximo;
    aux->anterior = turma->cabeca;
    aux->proximo->anterior = aux;
    turma->cabeca->proximo = aux;
    turma->tamanho++;
}

void intercalar(DEQUE *pilha1, DEQUE *pilha2, DEQUE *resultante){
    int i = 0;

    while (pilha1->cabeca->proximo != pilha1->cabeca){
        if(i % 2 == 0){

            ELEMENTO *aux1;
            aux1 = malloc (sizeof(ELEMENTO));
            aux1->numeros = pilha1->cabeca->proximo->numeros;
            aux1->proximo = resultante->cabeca;
            aux1->anterior = resultante->cabeca->anterior;
            resultante->cabeca->anterior = aux1;
            aux1->anterior->proximo = aux1;
            resultante->tamanho++;
            ELEMENTO *topo1 = pilha1->cabeca->proximo;
            pilha1->cabeca->proximo = topo1->proximo;
            pilha1->tamanho--;
            free(topo1);
        }
        else if(i % 2 != 0){
                ELEMENTO *aux2;
                aux2 = malloc (sizeof(ELEMENTO));
                aux2->numeros = pilha2->cabeca->proximo->numeros;
                aux2->proximo = resultante->cabeca;
                aux2->anterior = resultante->cabeca->anterior;
                resultante->cabeca->anterior = aux2;
                aux2->anterior->proximo = aux2;
                resultante->tamanho++;
                free(pilha2->cabeca->proximo);
                pilha2->cabeca->proximo = pilha2->cabeca->proximo->proximo;
                pilha2->tamanho--;
                ELEMENTO *topo2 = pilha2->cabeca->proximo;
                pilha2->cabeca->proximo = topo2->proximo;
                pilha2->tamanho--;
                free(topo2);
        }
        i++;
    }
}

void exibe(DEQUE deque){
    ELEMENTO *atual = deque.cabeca->anterior;
    while(atual != deque.cabeca){
        printf("%d ", atual->numeros);
        atual = atual->anterior;
    }
    printf("\n");
}