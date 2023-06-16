#ifndef ex2_h
#define ex2_h

typedef struct No {
    int base;
    int expoente;
    struct No* prox;
} NO;

typedef struct {
    NO* inicio;
} LISTA;

LISTA* criarLista();
void inserir(LISTA* lista, int base, int expoente);
LISTA* somap(LISTA* p1, LISTA* p2);
void print(LISTA* lista);

#endif