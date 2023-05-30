#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"

int main()
{
    LISTA *pvet, *pordem;
    int n, *iseq;
    printf("qual o tamanho do vetor que deseja criar?\n");
    scanf("%d", &n);
    pvet = criar(n);
    inserir(pvet);
    printar(pvet);
    printf("que numero voce deseja buscar nesse vetor?\n");
    int busca, aux;
    scanf("%d", &busca);
    aux = buscaseq(pvet, busca, iseq);
    if (aux > 0)
        printf("este valor esta em %d\n", aux);
    else
        printf("este valor nao esta no vetor\n");
    pordem = criar(30);
    inserirord(pordem);
    printar(pordem);
    printf("que numero voce deseja buscar nesse vetor?\n");
    int buscaord, auxseq, auxseqord, auxbin, auxbinrec, *iseqord = 0, *ibin = 0, *ibinrec = 0;
    *iseq = 0;
    scanf("%d", &buscaord);

    auxseq = buscaseq(pordem, buscaord, iseq);
    if (auxseq > 0)
        printf("este valor esta em %d segundo a busca sequencial e levou %d ciclos para chegar ao resultado\n", auxseq, *iseq);

    auxseqord = buscaseqord(pordem, buscaord, iseqord);
    if (auxseqord > 0)
        printf("este valor esta em %d segundo a busca sequencial ordenada e levou %d ciclos para chegar ao resultado\n", auxseqord, *iseqord);

    auxbin = buscabin(pordem, buscaord, ibin);
    if (auxbin > 0)
        printf("este valor esta em %d segundo a busca binaria interativa e levou %d ciclos para chegar ao resultado\n", auxbin, *ibin);

    auxbinrec = buscabinrec(pordem, buscaord, 0, pvet->n-1, ibinrec);

    if (auxbinrec > 0)
        printf("este valor esta em %d segundo a busca binaria recursiva e levou %d ciclos para chegar ao resultado\n", auxbinrec, *ibinrec);

    int maior, menor, soma, mult;
    maior = achamaior(pvet);
    menor = achamenor(pvet);
    soma = calcsoma(pvet);
    mult = calcmult(pvet);
}