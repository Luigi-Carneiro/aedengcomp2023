#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ex3.h"

void inicializar(ListaLigada *lista)
{
    lista->inicio = NULL;
    lista->quantidade = 0;
}

void inserirFim(ListaLigada *lista, int elemento)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->elemento = elemento;
    novo->proximo = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        No *atual = lista->inicio;

        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }

    lista->quantidade++;
}

void print(No *inicio)
{
    No *atual = inicio;

    while (atual != NULL)
    {
        printf("%d", atual->elemento);
        atual = atual->proximo;
    }

    printf("\n");
}

void liberar(No *inicio)
{
    No *atual = inicio;

    while (atual != NULL)
    {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

ListaLigada copiarListaLigada(ListaLigada *lista)
{
    ListaLigada novaLista;
    inicializarLista(&novaLista);

    No *atual = lista->inicio;
    while (atual != NULL)
    {
        inserirFimLista(&novaLista, atual->elemento);
        atual = atual->proximo;
    }

    return novaLista;
}

ListaLigada *intercalar(ListaLigada *lista, ListaLigada *copia){
    ListaLigada *ListaIntercalada = (ListaLigada *)malloc(sizeof(ListaLigada));
    ListaIntercalada->inicio = malloc(sizeof(No));

    ListaIntercalada->inicio = lista->inicio;
    ListaIntercalada->inicio->proximo = copia->inicio;

    printf("%d", copia->inicio);

    int i = 0;
    while (lista->inicio->proximo != NULL)
    {
        i++;

        if (i % 2 == 0)
        {
            ListaIntercalada->inicio->proximo = copia->inicio->proximo;
            printf("%d\n", copia->inicio->proximo);
        }
        else
        {
            ListaIntercalada->inicio->proximo = lista->inicio->proximo;
            printf("%d\n", lista->inicio->proximo);

        }
        
    }

    return ListaIntercalada;
}

ListaLigada *concatenar(ListaLigada *lista, ListaLigada *copia){

ListaLigada* concatenada = malloc(sizeof(ListaLigada));

if(lista==NULL){
return copia;
}

if(copia==NULL){
return lista;
}

if(lista!=NULL && copia!=NULL){
while(lista!=NULL){
concatenada = lista;
lista = lista->inicio;
}
concatenada->inicio = copia;
}

return concatenada;
}