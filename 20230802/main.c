#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(){
    ARVORE a;
    int numeros[15] = {1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8};
    inicializar(&a);
    for(int i = 0; i < 15; i++)
        cria_no(&a, numeros[i]);   
    printf("\no numero de termos da arvore eh: %d\n", conta_no(a.raiz));
    busca_no(a.raiz, 10);
    busca_no(a.raiz, 14);
    busca_no(a.raiz, 24);
    printf("\npercorrendo a arvore em pre-ordem:\n");
    print_pre_ordem(a.raiz);
    printf("\n\npercorrendo a arvore em in-ordem:\n");
    print_in_ordem(a.raiz);
    printf("\n\npercorrendo a arvore em pos-ordem:\n");
    print_pos_ordem(a.raiz);
    printf("eu sou a raiz %d", a.raiz->num);
}