#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ex3.h"

#define N 10

int main()
{
    ListaLigada lista;
    inicializar(&lista);

    int L;

    for (int i = 0; i < N; i++)
    {
        L = rand() %20;
        scanf("%d", &L);
        inserirFim(&lista, L);
    }

    printf("lista original: ");
    print(lista.inicio);

    ListaLigada copia;
    inicializar(&copia);

    printf("copia: ");
    copia = copiarListaLigada(&lista);
    print(copia.inicio);

    printf("lista intercalada: ");
    ListaLigada *intercalada = intercalar(&lista, &copia);
    print(intercalada);

    printf("lista concatenada: ");
    ListaLigada *concatenada = concatenar(&lista, &copia);
    print(concatenada);

    liberar(intercalada);
    liberar(concatenada);

    return 0;
}