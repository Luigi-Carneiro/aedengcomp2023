#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

LISTA* criarLista() {
    LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
    lista->inicio = NULL;
    return lista;
}

void inserir(LISTA* lista, int base, int expoente) {
    NO* novoNo = (NO*)malloc(sizeof(NO));
    novoNo->base = base;
    novoNo->expoente = expoente;

    if (lista->inicio == NULL || expoente > lista->inicio->expoente) {
        novoNo->prox = lista->inicio;
        lista->inicio = novoNo;
    } else {
        NO* atual = lista->inicio;
        while (atual->prox != NULL && expoente < atual->prox->expoente) {
            atual = atual->prox;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
    }
}

LISTA* somap(LISTA* p1, LISTA* p2) {
    LISTA* resultado = criarLista();
    NO* poli1 = p1->inicio;
    NO* poli2 = p2->inicio;

    while (poli1 != NULL && poli2 != NULL) {
        if (poli1->expoente > poli2->expoente) {
            inserir(resultado, poli1->base, poli1->expoente);
            poli1 = poli1->prox;
        } else if (poli2->expoente > poli1->expoente) {
            inserir(resultado, poli2->base, poli2->expoente);
            poli2 = poli2->prox;
        } else {
            int coeficienteSoma = poli1->base + poli2->base;
            if (coeficienteSoma != 0) {
                inserir(resultado, coeficienteSoma, poli1->expoente);
            }
            poli1 = poli1->prox;
            poli2 = poli2->prox;
        }
    }

    while (poli1 != NULL) {
        inserir(resultado, poli1->base, poli1->expoente);
        poli1 = poli1->prox;
    }

    while (poli2 != NULL) {
        inserir(resultado, poli2->base, poli2->expoente);
        poli2 = poli2->prox;
    }

    return resultado;
}

void print(LISTA* lista) {
    NO* atual = lista->inicio;
    while (atual != NULL) {
        printf("%dx^%d ", atual->base, atual->expoente);
        if (atual->prox != NULL) {
            printf("+ ");
        }
        atual = atual->prox;
    }
    printf("\n");
}
