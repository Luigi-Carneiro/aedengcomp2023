#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED

typedef struct{
    int *vetor;
    int tamanho;
    int capacidademax;

} LISTA;

void criarLista(LISTA *lista, int capacidademax);
void inserirOrdenado(LISTA *lista, int valor);
void imprimirLista(LISTA *lista);
void Contador(LISTA *lista, int desejado);

#endif