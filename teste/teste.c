#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "teste.h"

void criarLista(LISTA *lista, int capacidademax){
    lista->vetor = (int *)malloc(capacidademax * sizeof(int));
    lista->tamanho = 0;
    lista->capacidademax = capacidademax;
}

void inserirOrdenado(LISTA *lista, int valor){
    if (lista->tamanho < lista->capacidademax){
        int i = lista->tamanho - 1;

        while (i >= 0 && lista->vetor[i] >= valor){
            lista->vetor[i + 1] = lista->vetor[i];
            i--;
        }
        lista->vetor[i + 1] = valor;
        lista->tamanho++;
    }
    else{
        printf("Lista cheia.\n");
    }
}

void imprimirLista(LISTA *lista){
    printf("LISTA: ");
    for (int i = 0; i < lista->tamanho; i++){
        printf("%d ", lista->vetor[i]);
    }
    printf("\n");
}

void Contador(LISTA *lista, int desejado){
    int cont = 0;
    for(int i = 0; i < lista->tamanho; i++){
        if (lista->vetor[i] == desejado){
            cont++;
        }
    }
    printf("o numero %d aparece %d vezes na lista", desejado, cont);
}