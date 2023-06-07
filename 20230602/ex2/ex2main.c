#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

#define N 10

int main(){
    Lista lista;
    inicializar(&lista);
    inserir(&lista, 1);
    inserir(&lista, 2);
    inserir(&lista, 3);
    printf("Lista: ");
    print(lista);
    Lista copia;
    inicializar(&copia);
    copiarLista(&lista, &copia);
    printf("Copia: ");
    print(copia);

    Lista A;
    A = organizarA(lista);
    printf("Letra a): ");
    print(A);
    Lista B;
    B = organizarB(copia);
    printf("Letra b): ");
    print(B);
    return 0;
}