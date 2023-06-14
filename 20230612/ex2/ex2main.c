#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

int main() {
    LISTA* p1 = criarLista();
    LISTA* p2 = criarLista();

    inserir(p1, 5, 4);
    inserir(p1, -7, 2);
    inserir(p1, 3, 0);

    inserir(p2, 2, 2);
    inserir(p2, 4, 1);
    inserir(p2, 3, 0);

    printf("P1: ");
    print(p1);

    printf("P2: ");
    print(p2);

    LISTA* soma = somap(p1, p2);
    printf("Soma: ");
    print(soma);

    return 0;
}
