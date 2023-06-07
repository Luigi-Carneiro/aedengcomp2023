#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

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

    printf("lista intercalada: ");
    Lista intercalada = intercalar(&lista, &copia);
    print(intercalada);

    printf("lista concatenada: ");
    concatenar(&lista, &copia);
    print(lista);
    return 0;
}