#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "teste.h"

int main()
{
    printf("Luigi Antonaccio Barroco Rocha Carneiro\nExercicio de codigo 025\n");
    time_t now;

    time(&now);

    printf("Data e hora de entrega %s", ctime(&now));

    LISTA lista;
    criarLista(&lista, 10);
    for(int i = 0; i < lista.capacidademax; i++){
        int valor = rand() %4;
        inserirOrdenado(&lista, valor);
    }
    imprimirLista(&lista);
    Contador(&lista, 2);
    return 0;
}