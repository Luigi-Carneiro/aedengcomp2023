#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"

LISTA * criar(int n){
    LISTA *pvet;
    pvet = malloc(sizeof(LISTA));
    pvet->vetor = malloc(n * sizeof(int));
    pvet->n = n;
    return pvet;
}

void inserir(LISTA *pvet){
    for(int i = 0; i < pvet->n; i++){
        pvet->vetor[i] = rand() % 100;
    }

}

void liberar(LISTA *pvet){
    free(pvet->vetor);
    free(pvet);
}

void printar(LISTA *pvet){
    int i;
    printf ("VETOR: ");
    for(i = 0; i < pvet->n; i++){
        printf("%d ", pvet->vetor[i]);
    }
    printf("\n");
}

int buscaseq(LISTA *pvet, int busca, int *cont){
    int i;
    for (i = 0; i < pvet->n; i++){
        *cont++;
        if (pvet->vetor[i] == busca){
            return i+1;
        }
    }
    printf("nao encontrado");
    return -1;
}

void inserirord(LISTA *pvet){
    pvet->vetor[0] = rand() % 10;
    for(int i = 1; i < pvet->n; i++){
        pvet->vetor[i] = pvet->vetor[i-1] + rand() % 10;
    }

}

int buscaSequencialOrdenada(LISTA *pvet, int busca, int *cont){
    *cont = 0;
    for (int i = 0; i < pvet->n; i++){
        (*cont)++;
        if (pvet->vetor[i] >= busca){
            if (pvet->vetor[i] == busca)
                return i + 1;
            else{
                printf("nao encontrado");
                return -1;
            }
        }
    }
    printf("nao encontrado");
    return -1;
}


int buscabin(LISTA *pvet, int busca, int *cont){
    int primeiro = 0;
    int ultimo = pvet->n - 1;
    int meio = -1;
    while(primeiro <= ultimo){
        *cont++;
        meio = primeiro + (ultimo - primeiro)/2;
        if(busca == pvet->vetor[meio]){
            return meio+1;
        }
        else if(busca > pvet->vetor[meio]){
            primeiro = meio + 1;
        }
        else if(busca > pvet->vetor[meio]){
            primeiro = meio - 1;
        }
    }
    printf("nao encontrado");
    return -1;
}

int buscabinrec(LISTA *pvet, int busca, int primeiro, int ultimo, int *cont){
    *cont++;
    if (ultimo > primeiro){
        printf("nao encontrado");
        return -1;
    }
    int meio = (primeiro + ultimo)/2;
    if(busca == pvet->vetor[meio]){
        return meio+1;
    }
    if(busca < pvet->vetor[meio]){
        buscabinrec(pvet, busca, primeiro, meio - 1, cont);
    }
    else{
        buscabinrec(pvet, busca, meio + 1, ultimo, cont);
    }
}

int achamaior(LISTA *pvet){
    int i, maior = pvet->vetor[0];
    for(i = 1; i < pvet->n; i++){
        if(maior < pvet->vetor[i]){
            maior = pvet->vetor[i];
        }
    }
    return maior;
}

int achamaiorrec(LISTA *pvet, int maior, int i){
    if(maior >= pvet->vetor[i]){
        achamaiorrec(pvet, maior, i+1);
    }
    else if(maior < pvet->vetor[i]){
        maior = pvet->vetor[i];
        achamaiorrec(pvet, maior, i+1);
    }
    if(i+1 == pvet->n){
        return maior;
    }
}

int achamenor(LISTA *pvet){
    int i, menor = pvet->vetor[0];
    for(i = 1; i < pvet->n; i++){
        if(menor > pvet->vetor[i]){
            menor = pvet->vetor[i];
        }
    }
    return menor;
}

int achamenorrec(LISTA *pvet, int menor, int i){
    if(menor <= pvet->vetor[i]){
        achamaiorrec(pvet, menor, i+1);
    }
    else if(menor > pvet->vetor[i]){
        menor = pvet->vetor[i];
        achamaiorrec(pvet, menor, i+1);
    }
    if(i+1 == pvet->n){
        return menor;
    }
}

int calcsoma(LISTA *pvet){
    int i, soma = 0;
    for(i = 1; i < pvet->n; i++){
        soma += pvet->vetor[i];
    }
    return soma;
}

int calcsomarec(LISTA *pvet, int soma, int i){
    soma += pvet->vetor[i];
    if(i+1 == pvet->n){
        return soma;
    }
    somarec(pvet, soma, i+1);
}

int calcmult(LISTA *pvet){
    int i, mult = 1;
    for(i = 1; i < pvet->n; i++){
        mult += pvet->vetor[i];
    }
    return mult;
}

int calcmultrec(LISTA *pvet, int mult, int i){
    mult *= pvet->vetor[i];
    if(i+1 == pvet->n){
        return mult;
    }
    somarec(pvet, mult, i+1);
}