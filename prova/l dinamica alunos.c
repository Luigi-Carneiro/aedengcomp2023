#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char nome[50];
    int idade;
    int nfilhos;
} ALUNO;

typedef struct No{
    ALUNO aluno;
    struct No *proximo;
} NO;

typedef struct{
    NO *primeiro;
    int tamanho;
} LISTA;

void criarLista(LISTA *lista){
    lista->primeiro = NULL;
    lista->tamanho = 0;
}

void inserirElemento(LISTA *lista, ALUNO aluno){
    NO *novoElemento = (NO *)malloc(sizeof(NO));
    novoElemento->aluno = aluno;
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

int QuantidadeElementos(LISTA *lista){
    return lista->tamanho;
}

int buscarElemento(LISTA *lista, int codigo){
    NO *atual = lista->primeiro;
    int posicaoAtual = 0;

    while (atual != NULL){
        if (atual->aluno.codigo == codigo){
            return posicaoAtual;
        }

        atual = atual->proximo;
        posicaoAtual++;
    }

    return -1;
}

void excluirElemento(LISTA *lista, int codigo){
    if (lista->primeiro == NULL){
        printf("Lista vazia\n");
        return;
    }

    NO *atual = lista->primeiro;
    NO *anterior = NULL;

    while (atual != NULL && atual->aluno.codigo != codigo){
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL){
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
        printf("Aluno não encontrado\n");
    }
}

void imprimirLista(LISTA *lista){
    printf("Lista de Alunos:\n");
    NO *atual = lista->primeiro;

    while (atual != NULL){
        ALUNO aluno = atual->aluno;
        printf("Código: %d, Nome: %s, Idade: %d, Número de Filhos: %d\n",
               aluno.codigo, aluno.nome, aluno.idade, aluno.nfilhos);

        atual = atual->proximo;
    }

    printf("\n");
}

int main(){
    LISTA lista;
    criarLista(&lista);

    ALUNO aluno1 = {1, "João Silva", 20, 0};
    ALUNO aluno2 = {2, "Maria Santos", 22, 1};

    inserirElemento(&lista, aluno1);
    inserirElemento(&lista, aluno2);

    imprimirLista(&lista);

    int posicao = buscarElemento(&lista, 2);
    if (posicao != -1){
        printf("Aluno com código 2 encontrado na posição %d\n", posicao);
    }
    else{
        printf("Aluno com código 2 não encontrado na lista\n");
    }

    excluirElemento(&lista, 2);

    imprimirLista(&lista);

    printf("Quantidade de alunos: %d\n", QuantidadeElementos(&lista));

    return 0;
}