#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    ARVORE a;
    int numeros[7] = {24, 10, 32, 5, 12, 29, 35};
    inicializar(&a);
    for(int i = 0; i < 7; i++)
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
}