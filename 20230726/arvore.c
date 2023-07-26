#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void inicializar(ARVORE *a){
    a->raiz = NULL;
}

NO* inserir_no(NO *raiz, NO *novo){
    if(raiz == NULL)
        return novo;
    if(raiz->num > novo->num)
        raiz->esquerda = inserir_no(raiz->esquerda, novo);
    else
        raiz->direita = inserir_no(raiz->direita, novo);
    return raiz;
}

void adiciona_no(ARVORE *a, NO *novo){
    a->raiz = inserir_no(a->raiz, novo);
}

void cria_no(ARVORE *a, int numero){
    NO *novo = malloc(sizeof(NO));
    novo->num = numero;
    novo->direita = NULL;
    novo->esquerda = NULL;
    adiciona_no(a, novo);
}

void busca_no(NO *raiz, int valor){
    if(raiz == NULL)
        printf("\no valor %d nao esta na arvore\n", valor);
    else if(raiz->num == valor)
        printf("\no valor %d pertence a arvore e esta no endereco %d da memoria\n", valor, raiz);
    else if(raiz->num > valor)
        return busca_no(raiz->esquerda, valor);
    else
        return busca_no(raiz->direita, valor);
}

int conta_no(NO *raiz){
    if(raiz == NULL)
        return 0;
    return conta_no(raiz->direita) + conta_no(raiz->esquerda) + 1;
}

void print_pre_ordem(NO *raiz){
    if(raiz == NULL)
        return;
    printf("%d ", raiz->num);
    print_pre_ordem(raiz->esquerda);
    print_pre_ordem(raiz->direita);
}

void print_in_ordem(NO *raiz){
    if(raiz == NULL)
        return;
    print_pre_ordem(raiz->esquerda);
    printf("%d ", raiz->num); 
    print_pre_ordem(raiz->direita);   
}

void print_pos_ordem(NO *raiz){
    if(raiz == NULL)
        return;
    print_pre_ordem(raiz->esquerda);
    print_pre_ordem(raiz->direita); 
    printf("%d ", raiz->num);   
}