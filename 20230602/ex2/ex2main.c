#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ex2.h"

#define N 10

int main(){
    ListaLigada lista;
    inicializar(&lista);

    int L;

    for (int i = 0; i < N; i++){
        L = rand() % 20;
        inserirFim(&lista, L);
    }

    printf("Lista Original: ");
    print(lista.inicio);

    ListaLigada copia;
    inicializar(&copia);

    No *casoa = A_OperatorL1(lista.inicio);
    printf("caso a) ");
    print(casoa);

    No *casob = B_OperatorL1(copia.inicio);
    printf("caso b) ");
    print(casob);

    liberar(casoa);
    liberar(casob);

    return 0;
}