#include <stdio.h>
#include <stdlib.h>
#include "funcb.h"

int main(){
    TABELA Tabela;
    int valores[11] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    inicializar(Tabela);
    for (int i = 0; i < 11; i++)
        inserir(Tabela, valores[i]);

    printHash(Tabela);
    return 0;
}