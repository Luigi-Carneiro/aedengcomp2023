#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
struct lista{
    int n;
    int *vetor;
};
typedef struct lista LISTA;

LISTA * criar(int n);
void inserir(LISTA *pvet);
void liberar(LISTA *pvet);
void printar(LISTA *pvet);
int buscaseq(LISTA *pvet, int busca, int *cont);
void inserirord(LISTA *pvet);
int buscaseqord(LISTA *pvet, int busca, int *cont);
int buscabin(LISTA *pvet, int busca, int *cont);
int buscabinrec(LISTA *pvet, int busca, int primeiro, int ultimo, int *cont);
int achamaior(LISTA *pvet);
int achamaiorrec(LISTA *pvet, int maior, int i);
int achamenor(LISTA *pvet);
int achamenorrec(LISTA *pvet, int menor, int i);
int calcsoma(LISTA *pvet);
int calcsomarec(LISTA *pvet, int soma, int i);
int calcmult(LISTA *pvet);
int calcmultrec(LISTA *pvet, int mult, int i);
#endif
