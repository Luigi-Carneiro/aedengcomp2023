#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
} NO;

typedef struct{
    NO *primeiro;
    int tamanho;
} LISTA;



void criarLista(LISTA* lista){
    lista->primeiro = NULL;
    lista->tamanho = 0;
}

void inserirElemento(LISTA* lista, int valor){
    NO *novoElemento = (NO*)malloc(sizeof(NO));
    novoElemento->valor = valor;
    novoElemento->proximo = NULL;

    if (lista->primeiro == NULL){
        lista->primeiro = novoElemento;
    } 
    else{
        NO *atual = lista->primeiro;

        while (atual->proximo != NULL){
            atual = atual->proximo;
        }

        atual->proximo = novoElemento;
    }

    lista->tamanho++;
}

int obterQuantidadeElementos(LISTA* lista){
    return lista->tamanho;
}

int buscarElemento(LISTA* lista, int valor){
    NO *atual = lista->primeiro;
    int posicaoAtual = 0;

    while (atual != NULL){
        if (atual->valor == valor){
            return posicaoAtual;
        }

        atual = atual->proximo;
        posicaoAtual++;
    }

    return -1;
}

void excluirElemento(LISTA* lista, int valor){
    if (lista->primeiro == NULL){
        printf("Lista vazia\n");
        return;
    }

    NO *atual = lista->primeiro;
    NO *anterior = NULL;

    while (atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior == NULL){
            lista->primeiro = atual->proximo;
        } 
        else{
            anterior->proximo = atual->proximo;
        }

        free(atual);
        lista->tamanho--;

    } 
    else{
        printf("Elemento nao encontrado\n");
    }
}

void imprimirLista(LISTA* lista){
    printf("Lista: ");
    NO *atual = lista->primeiro;

    while (atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
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

    printf("Quantidade de elementos: %d\n", obterQuantidadeElementos(&lista));

    return 0;
}