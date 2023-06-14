#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

NO *inserir(NO *head){
    NO *novoNO = (NO *)malloc(sizeof(NO));
    novoNO->valor = rand() % 100;
    novoNO->proximo = head;
    novoNO->anterior = NULL;

    if (head != NULL)
        head->anterior = novoNO;

    return novoNO;
}

void print(NO *no){
    printf("lista: ");
    while (no != NULL){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n");
}

void ordenar(NO *listaL, NO **listaK){
    while (listaL != NULL){
        NO *maior = listaL;
        NO *inicio = listaL->proximo;

        while (inicio != NULL){
            if (inicio->valor > maior->valor)
                maior = inicio;
            inicio = inicio->proximo;
        }

        if (maior->anterior != NULL)
            maior->anterior->proximo = maior->proximo;

        else
            listaL = maior->proximo;

        if (maior->proximo != NULL)
            maior->proximo->anterior = maior->anterior;

        maior->proximo = *listaK;

        if (*listaK != NULL)
            (*listaK)->anterior = maior;

        *listaK = maior;
        maior->anterior = NULL;
    }
}