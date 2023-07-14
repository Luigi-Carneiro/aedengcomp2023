#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(){
    int cont = 0;
    TABELA Tabelalinear, Tabelaquadratica1, Tabelaquadratica2, Tabeladupla;
    int Valores[6] = {365, 112, 180, 213, 13, 27};

    inicializar(Tabelalinear);
    inicializar(Tabelaquadratica1);
    inicializar(Tabelaquadratica2);
    inicializar(Tabeladupla);

    for (int i = 0; i < 6; i++)
        inserirlinear(Tabelalinear, Valores[i], &cont);
    
    printf("\n\n-----Sondagem linear-----\n");
    printHash(Tabelalinear);
    printf("numero de colisoes: %d", cont);
    cont = 0;

    for (int i = 0; i < 6; i++)
        inserirquadratica1(Tabelaquadratica1, Valores[i], &cont);

    printf("\n\n-----Sondagem quadratica 1-----\n");
    printHash(Tabelaquadratica1);
    printf("numero de colisoes: %d", cont);
    cont = 0;

    for (int i = 0; i < 6; i++)
        inserirquadratica2(Tabelaquadratica2, Valores[i], &cont);

    printf("\n\n-----Sondagem quadratica 2-----\n");
    printHash(Tabelaquadratica2);
    printf("numero de colisoes: %d", cont);
    cont = 0;

    for (int i = 0; i < 6; i++)
        inserirdupla(Tabeladupla, Valores[i], &cont);
    
    printf("\n\n-----Sondagem dupla-----\n");
    printHash(Tabeladupla);
    printf("numero de colisoes: %d", cont);
    cont = 0;

    return 0;
}