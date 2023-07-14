#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"

void inicializar(TABELA tabela){
    for (int i = 0; i < M; i++){
        tabela[i] = NULL;
    }
}

int chavelinear(int valor, int i){
    return ((valor + i) % M);
}

int chavequadratica1(int valor, int i){
    return ((valor + (i*i)) % M);
}

int chavequadratica2(int valor, int i){
    return ((valor + (2*i) + (i*i)) % M);
}

int chavedupla(int valor, int i){
    int h1 = (valor % M);
    int h2 = (7 - (valor % 7));
    return (h1 + i * h2);
}

int inserirlinear(TABELA tabela, int valor, int *cont){
    int  j = 0, i = chavelinear(valor, j);
    while(tabela[i] != NULL){
        (*cont)++;
        if (tabela[i]->valor == valor)
            return 0;
        j++;
        i = chavelinear(valor, j);
    }
    if(tabela[i] == NULL){
        tabela[i] = malloc(sizeof(CODIGO));
        (tabela[i]->valor) = valor;
    }
    else{
        i++;
        while(tabela[i] != NULL){
            i++;
        }
        tabela[i] = malloc(sizeof(CODIGO));
        (tabela[i]->valor) = valor;
    }
    return 1;
}

int inserirquadratica1(TABELA tabela, int valor, int *cont){
    int  j = 0, i = chavequadratica1(valor, j);
    while(tabela[i] != NULL){
        (*cont)++;
        if (tabela[i]->valor == valor)
            return 0;
        j++;
        i = chavequadratica1(valor, j);
    }
    if(tabela[i] == NULL){
        tabela[i] = malloc(sizeof(CODIGO));
        (tabela[i]->valor) = valor;
    }
    else{
        i++;
        while(tabela[i] != NULL){
            i++;
        }
        tabela[i] = malloc(sizeof(CODIGO));
        (tabela[i]->valor) = valor;
    }
    return 1;
}

int inserirquadratica2(TABELA tabela, int valor, int *cont){
    int  j = 0, i = chavequadratica2(valor, j);
    while(tabela[i] != NULL){
        (*cont)++;
        if (tabela[i]->valor == valor)
            return 0;
        j++;
        i = chavequadratica2(valor, j);
    }
    if(tabela[i] == NULL){
        tabela[i] = malloc(sizeof(CODIGO));
        (tabela[i]->valor) = valor;
    }
    else{
        i++;
        while(tabela[i] != NULL){
            i++;
        }
        tabela[i] = malloc(sizeof(CODIGO));
        (tabela[i]->valor) = valor;
    }
    return 1;
}

int inserirdupla(TABELA tabela, int valor, int *cont){
    int  aux = 0, j = 0, i = chavedupla(valor, j);
    while(tabela[i] != NULL){
        (*cont)++;
        if (tabela[i]->valor == valor)
            return 0;
        j++;
        i = chavedupla(valor, j);
    }
    if(tabela[i] == NULL){
        tabela[i] = malloc(sizeof(CODIGO));
        (tabela[i]->valor) = valor;
    }
    else{
        i++;
        while(tabela[i] != NULL){
            i++;
        }
        tabela[i] = malloc(sizeof(CODIGO));
        (tabela[i]->valor) = valor;
    }
    return 1;
}

void printHash(TABELA tabela){
    printf("\n");
    for (int i = 0; i < M; i++){
        if (tabela[i] != NULL){
            printf("Posicao %d: %d\n", i, tabela[i]->valor);
        }
        else
            printf("Posicao %d: NULL\n", i);
    }
}


