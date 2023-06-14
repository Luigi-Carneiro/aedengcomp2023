#ifndef ex1_h
#define ex1_h

typedef struct NO{
    int valor;
    struct NO *proximo;
    struct NO *anterior;

} NO;

typedef struct Lista{
    NO *inicio;

} LISTA;

NO *inserir(NO *head);
void print(NO *NO);
void ordenar(NO* listaL, NO** listaK);

#endif