#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *vetor;
    int tamanho;
    int capacidademax;

} LISTA;

void criarLista(LISTA *lista, int capacidademax){
    lista->vetor = (int *)malloc(capacidademax * sizeof(int));
    lista->tamanho = 0;
    lista->capacidademax = capacidademax;
}

void inserirDesordenado(LISTA *lista, int valor){
    if (lista->tamanho < lista->capacidademax){
        lista->vetor[lista->tamanho] = valor;
        lista->tamanho++;
    }
    else{
        printf("Lista cheia\n");
    }
}

void inserirOrdenado(LISTA *lista, int valor){
    if (lista->tamanho < lista->capacidademax){
        int i = lista->tamanho - 1;

        while (i >= 0 && lista->vetor[i] > valor){
            lista->vetor[i + 1] = lista->vetor[i];
            i--;
        }
        lista->vetor[i + 1] = valor;
        lista->tamanho++;
    }
    else{
        printf("Lista cheia.\n");
    }
}

int QuantidadeElementos(LISTA *lista){
    return lista->tamanho;
}

int BuscaSequencial(LISTA *lista, int valor){
    for (int i = 0; i < lista->tamanho; i++){
        if (lista->vetor[i] == valor){
            return i;
        }
    }
    return -1;
}

int BuscaBinaria(LISTA *lista, int valor){
    int inicio = 0;
    int fim = lista->tamanho - 1;

    while (inicio <= fim){
        int meio = (inicio + fim) / 2;

        if (lista->vetor[meio] == valor){
            return meio;
        }
        else if (lista->vetor[meio] < valor){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }

    return -1;
}

int BuscaBinariaRec(LISTA *lista, int valor, int inicio, int fim){

    int meio = (inicio + fim) / 2;

    if (fim < inicio){
        return -1;
    }
    else if (lista->vetor[meio] == valor){
        return meio;
    }
    else if (lista->vetor[meio] < valor){
        BuscaBinariaRec(lista, valor, meio + 1, fim);
    }
    else{
        BuscaBinariaRec(lista, valor, inicio, meio - 1);
    }
}

void excluirElementoPosicao(LISTA *lista, int posicao){
    if (posicao >= 0 && posicao < lista->tamanho){
        for (int i = posicao; i < lista->tamanho - 1; i++){
            lista->vetor[i] = lista->vetor[i + 1];
        }
        lista->tamanho--;
    }
    else{
        printf("Posição inválida.\n");
    }
}

void excluirElementoValor(LISTA *lista, int valor){
    int posicao = BuscaSequencial(lista, valor);
    if (posicao != -1){
        excluirElementoPosicao(lista, posicao);
    }
    else{
        printf("Elemento não encontrado.\n");
    }
}

void imprimirLista(LISTA *lista){
    printf("LISTA: ");
    for (int i = 0; i < lista->tamanho; i++){
        printf("%d ", lista->vetor[i]);
    }
    printf("\n");
}

int main(){
    LISTA lista;
    criarLista(&lista, 10);

    inserirDesordenado(&lista, 5);
    inserirDesordenado(&lista, 10);
    inserirDesordenado(&lista, 15);
    inserirOrdenado(&lista, 12);
    inserirOrdenado(&lista, 13);

    imprimirLista(&lista);

    int posicao = BuscaBinariaRec(&lista, 12, 0, 5);
    if (posicao != -1){
        printf("Elemento encontrado na posicao %d\n", posicao);
    }
    else{
        printf("Elemento nao encontrado na lista\n");
    }

    excluirElementoValor(&lista, 10);

    printf("[Apos exclusao] ");
    imprimirLista(&lista);

    printf("Quantidade de elementos: %d\n", QuantidadeElementos(&lista));

    return 0;
}