#include <stdio.h>
#include <stdlib.h>
#include "prova.h"

int main(){
    DEQUE deque1, deque2, resultante;
    inicializar(&deque1);
    inicializar(&deque2);
    inicializar(&resultante);
    int numeros1[4] = {7, 5, 3, 1};
    int numeros2[4] = {8, 6, 4, 2};
    for(int i = 0; i < 4; i++){
        inserir(&deque1, numeros1[i]);
    }
    for(int i = 0; i < 4; i++){
        inserir(&deque2, numeros2[i]);
    }
    printf("Deque 1: ");
    exibe(deque1);
    printf("Deque 2: ");
    exibe(deque2);
    intercalar(&deque1, &deque2, &resultante);
        printf("Resultante: ");
    exibe(resultante);
}
