#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void inicializar(DEQUE *turma){
    turma->cabeca = malloc(sizeof(ELEMENTO));
    turma->cabeca->proximo = turma->cabeca;
    turma->cabeca->anterior = turma->cabeca;
    turma->tamanho = 0;
}

void inserirInicio(DEQUE *turma, DADOS novo){
    ELEMENTO *aux;
    aux = malloc (sizeof(ELEMENTO));
    aux->aluno = novo;
    aux->proximo = turma->cabeca->proximo;
    aux->anterior = turma->cabeca;
    turma->cabeca->proximo = aux;
    aux->proximo->anterior = aux;
    turma->tamanho++;
}

void inserirFim(DEQUE *turma, DADOS novo){
    ELEMENTO *aux;
    aux = malloc (sizeof(ELEMENTO));
    aux->aluno = novo;
    aux->proximo = turma->cabeca;
    aux->anterior = turma->cabeca->anterior;
    turma->cabeca->anterior = aux;
    aux->anterior->proximo = aux;
    turma->tamanho++;
}

void exibe(DEQUE turma, char ordem, int pos){
    ELEMENTO *atual = turma.cabeca->proximo;
    int j = 0;
    if(ordem == 'd'){
        ELEMENTO *atual = turma.cabeca->proximo;
        printf("\nfila a partir da posicao %d na ordem direta\n", pos);
        while(atual != turma.cabeca){
            if(j < pos)
                atual = atual->proximo;
            
            else{
                printf("%s\n", atual->aluno.nome);
                atual = atual->proximo;
            }
            j++;
        }
    }
    else if(ordem == 'i'){
        ELEMENTO *atual = turma.cabeca->anterior;
        printf("\nfila a partir da posicao %d na ordem inversa\n", pos);
        while(atual != turma.cabeca){
            if(j < turma.tamanho - pos - 1)
                atual = atual->anterior;
            
            else{
                printf("%s\n", atual->aluno.nome);
                atual = atual->anterior;
            }
            j++;
        }
    }
    else
        printf("comando desconhecido");
}

//Tarantula
//Canopus
//Sirius
//Tardigrado
//Astra
//Exeggutor