#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    FILA fila;
    inicializar(&fila);
    DADOS Avioes[3] = {{14, "LATAM"}, {27, "GOL"}, {79, "AZUL"}};
    for (int i = 0; i < 3; i++)
        inserirElemento(&fila, Avioes[i]);

    printFila(&fila);
    primeiroElemento(&fila);
    decolagem(&fila);
    printFila(&fila);
    primeiroElemento(&fila);
    decolagem(&fila);
    decolagem(&fila);
    printFila(&fila);
}
