#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char const *argv[])
{
    PILHA pilha;
    inicializar(&pilha);
    DADOS Avioes[3] = {{14, "LATAM"}, {27, "GOL"}, {79, "AZUL"}};
    for (int i = 0; i < 3; i++)
        inserirElemento(&pilha, Avioes[i]);

    printPilha(&pilha);
    int pos;
    printf("Deseja liberar o aviao de qual posicao? ");
    scanf("%d", &pos);
    liberaAviao(&pilha, pilha.tamanho - (pos - 1));
    printPilha(&pilha);
    return 0;
}