#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

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

Lista organizarA(Lista lista){
    Lista novaLista;
    inicializar(&novaLista);

    int atual = lista.primeiro;
    while (atual != -1){
        inserir(&novaLista, lista.lista[atual].elemento);
        atual = lista.lista[atual].proximo;
    }

    if (novaLista.quantidade > 1){
        int primeiro = novaLista.primeiro;
        novaLista.primeiro = novaLista.lista[primeiro].proximo;
        novaLista.lista[primeiro].proximo = -1;
        novaLista.lista[novaLista.ultimo].proximo = primeiro;
        novaLista.ultimo = primeiro;
    }

    return novaLista;
}

Lista organizarB(Lista lista){
    Lista novaLista;
    inicializar(&novaLista);

    for(int i = lista.quantidade - 1; i >= 0; i--){
        inserir(&novaLista, lista.lista[i].elemento);
    }
    return novaLista;
}
