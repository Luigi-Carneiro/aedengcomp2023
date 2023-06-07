#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ex3.h"

void inicializarLista(ListaLigada *lista)
{
    lista->inicio = NULL;
    lista->quantidade = 0;
}

void inserirFimLista(ListaLigada *lista, int elemento)
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

void imprimirLista(No *inicio)
{
    No *atual = inicio;

    while (atual != NULL)
    {
        printf("%d", atual->elemento);
        atual = atual->proximo;
    }

    printf("\n");
}

void liberarLista(No *inicio)
{
    No *atual = inicio;

    while (atual != NULL)
    {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

ListaLigada *copiarListaLigada(ListaLigada *lista)
{
    ListaLigada *novaLista;
    inicializarLista(novaLista);

    No *atual = lista->inicio;
    while (atual != NULL)
    {
        inserirFimLista(novaLista, atual->elemento);
        atual = atual->proximo;
    }

    return novaLista;
}

No *A_OperatorL1(No *inicio)
{
    if (inicio == NULL || inicio->proximo == NULL)
    {
        return inicio;
    }

    No *atual = inicio->proximo;
    No *novoInicio = NULL;
    No *fim = NULL;

    while (atual != NULL)
    {
        fim = atual;
        atual = atual->proximo;
    }

    fim->proximo = inicio;
    novoInicio = inicio->proximo;
    inicio->proximo = NULL;

    return novoInicio;
}

No *B_OperatorL1(No *inicio)
{
    if (inicio == NULL || inicio->proximo == NULL)
    {
        return inicio;
    }

    No *anterior = NULL;
    No *atual = inicio;
    No *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->proximo;
        atual->proximo = anterior;

        anterior = atual;
        atual = proximo;
    }

    return anterior;
}

No *intercalarLista(No *lista, No *copia)
{
    printf("oi");

    No *start = (No *)malloc(sizeof(No));

    start = lista;
    start->proximo = copia;

    int i = 0;
    while (start->proximo != NULL)
    {
        i++;

        if (i % 2 == 0)
        {
            start->proximo = copia->proximo;
        }
        else
        {
            start->proximo = lista->proximo;
        }
    }

    return start;
}