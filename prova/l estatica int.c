#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int valor;
    int proximo;
} NO;

typedef struct{
    NO elementos[MAX];
    int primeiro;
    int ultimo;
    int tamanho;
} LISTA;

void criarLista(LISTA *lista){
    lista->primeiro = -1;
    lista->ultimo = 0;
    lista->tamanho = 0;

    for (int i = 0; i < MAX - 1; i++){
        lista->elementos[i].proximo = i + 1;
    }

    lista->elementos[MAX - 1].proximo = -1;
}

void inserirElemento(LISTA *lista, int valor){
    if (lista->ultimo != -1){
        int posicao = lista->ultimo;
        lista->ultimo = lista->elementos[posicao].proximo;
        lista->elementos[posicao].valor = valor;

        if (lista->primeiro == -1){
            lista->primeiro = posicao;
            lista->elementos[posicao].proximo = -1;
        }
        else{
            int atual = lista->primeiro;
            int anterior = -1;

            while (atual != -1 && lista->elementos[atual].valor < valor){
                anterior = atual;
                atual = lista->elementos[atual].proximo;
            }

            if (anterior == -1){
                lista->elementos[posicao].proximo = lista->primeiro;
                lista->primeiro = posicao;
            }
            else{
                lista->elementos[posicao].proximo = lista->elementos[anterior].proximo;
                lista->elementos[anterior].proximo = posicao;
            }
        }

        lista->tamanho++;
    }
    else{
        printf("Lista esta cheia. Não e possivel inserir o elemento.\n");
    }
}

int QuantidadeElementos(LISTA *lista){
    return lista->tamanho;
}

int buscarElemento(LISTA *lista, int valor){
    int atual = lista->primeiro;

    while (atual != -1){
        if (lista->elementos[atual].valor == valor){
            return atual;
        }
        atual = lista->elementos[atual].proximo;
    }

    return -1;
}

int BuscaBinariaRecursiva(LISTA *lista, int valor, int inicio, int fim){
    if (inicio > fim){
        return -1
    }

    int meio = (inicio + fim) / 2;
    int atual = lista->primeiro;

    for (int i = 0; i < meio; i++){
        atual = lista->elementos[atual].proximo;
    }

    if (lista->elementos[atual].valor == valor){
        return atual;
    }
    else if (lista->elementos[atual].valor < valor){
        return BuscaBinariaRecursiva(lista, valor, meio + 1, fim);
    }
    else{
        return BuscaBinariaRecursiva(lista, valor, inicio, meio - 1);
    }
}

void excluirElemento(LISTA *lista, int valor){
    int atual = lista->primeiro;
    int anterior = -1;

    while (atual != -1 && lista->elementos[atual].valor != valor){
        anterior = atual;
        atual = lista->elementos[atual].proximo;
    }

    if (atual != -1){
        if (anterior == -1){
            lista->primeiro = lista->elementos[atual].proximo;
        }
        else{
            lista->elementos[anterior].proximo = lista->elementos[atual].proximo;
        }

        lista->elementos[atual].proximo = lista->ultimo;
        lista->ultimo = atual;
        lista->tamanho--;

    }
    else{
        printf("Elemento nao encontrado.\n");
    }
}

void imprimirLista(LISTA *lista){
    printf("Lista: ");
    int atual = lista->primeiro;

    while (atual != -1){
        printf("%d ", lista->elementos[atual].valor);
        atual = lista->elementos[atual].proximo;
    }

    printf("\n");
}

int main(){
    LISTA lista;
    criarLista(&lista);

    inserirElemento(&lista, 5);
    inserirElemento(&lista, 10);
    inserirElemento(&lista, 15);

    imprimirLista(&lista);

    int posicao = buscarElemento(&lista, 10);
    if (posicao != -1){
        printf("Elemento encontrado na posicao %d\n", posicao);
    }
    else{
        printf("Elemento nao encontrado na lista\n");
    }

    excluirElemento(&lista, 10);

    imprimirLista(&lista);

    printf("Quantidade de elementos: %d\n", QuantidadeElementos(&lista));

    return 0;
}