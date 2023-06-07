#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

void inicializar(Lista *lista){
    lista->primeiro = -1;
    lista->ultimo = -1;
    lista->quantidade = 0;
}

void inserir(Lista *lista, int elemento){
    if (lista->quantidade == MAX){
        printf("lista cheia \n");
        return;
    }
    No novo;
    novo.elemento = elemento;
    novo.proximo = -1;

    if (lista->quantidade == 0)
    {
        lista->lista[0] = novo;
        lista->primeiro = 0;
        lista->ultimo = 0;
    }
    else
    {
        lista->lista[lista->ultimo].proximo = lista->quantidade;
        lista->lista[lista->quantidade] = novo;
        lista->ultimo = lista->quantidade;
    }

    lista->quantidade++;
}

void print(Lista lista){
    int atual = lista.primeiro;
    while (atual != -1)
    {
        printf("%d ", lista.lista[atual].elemento);
        atual = lista.lista[atual].proximo;
    }
    printf("\n");
}

void copiarLista(Lista *l1, Lista *l2){
    inicializar(l2);
    int atual = l1->primeiro;
    while (atual != -1){
        inserir(l2, l1->lista[atual].elemento);
        atual = l1->lista[atual].proximo;
    }
}


Lista intercalar(Lista *lista, Lista *copia){
    Lista listaIntercalada;
    inicializar(&listaIntercalada);

    int atualL1 = lista->primeiro;
    int atualL2 = copia->primeiro;

    while (atualL1 != -1 && atualL2 != -1) {
        inserir(&listaIntercalada, lista->lista[atualL1].elemento);
        inserir(&listaIntercalada, copia->lista[atualL2].elemento);

        atualL1 = lista->lista[atualL1].proximo;
        atualL2 = copia->lista[atualL2].proximo;
    }
    while (atualL1 != -1) {
        inserir(&listaIntercalada, lista->lista[atualL1].elemento);
        atualL1 = lista->lista[atualL1].proximo;
    }

    while (atualL2 != -1) {
        inserir(&listaIntercalada, copia->lista[atualL2].elemento);
        atualL2 = copia->lista[atualL2].proximo;
    }

    return listaIntercalada;
}

void concatenar(Lista *lista, Lista *copia){
    if (copia->quantidade == 0){
        return;
    }
    if (lista->quantidade == 0){
        *lista = *copia;
        return;
    }
    lista->lista[lista->ultimo].proximo = lista->quantidade;
    int atual = copia->primeiro;
    while (atual != -1){
        inserir(lista, copia->lista[atual].elemento);
        atual = copia->lista[atual].proximo;
    }
}