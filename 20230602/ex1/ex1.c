#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ex1.h"

void inicializar(ListaAlunos *lista){
    lista->inicio = NULL;
    lista->quantidade = 0;
}

void liberar(ListaAlunos *lista){
    No *atual = lista->inicio;

    while (atual != NULL){
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    lista->quantidade = 0;
}

int tamanho(ListaAlunos *lista){
    int tam = 0;
    No *i = lista->inicio;

    while (i != NULL){
        tam++;
        i = i->proximo;
    }

    return tam;
}

void vaziacheia(ListaAlunos *lista){
    No *i = lista->inicio;

    if (i == NULL){
        printf("\na lista esta vazia.");
        return;
    }

    int cont = 0;
    while (i != NULL){
        cont++;
        i = i->proximo;
    }

    if (cont >= lista->quantidade)
        printf("\na lista esta cheia.");
    else
        printf("\na lista não esta cheia.\n ");
}

void inserir(ListaAlunos *lista, Aluno aluno){
    No *novo = (No *)malloc(sizeof(No));


    novo->aluno = aluno;
    novo->proximo = NULL;

    if (lista->inicio == NULL || lista->inicio->aluno.matricula > aluno.matricula){
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    else{
        No *atual = lista->inicio;
        while (atual->proximo != NULL && atual->aluno.matricula < aluno.matricula)
            atual = atual->proximo;
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
}

void print(ListaAlunos *lista){
    No *atual = lista->inicio;

    while (atual != NULL){
        printf("matricula: %d\n nome: %s\n idade: %d \n\n", atual->aluno.matricula, atual->aluno.nome, atual->aluno.idade);
        atual = atual->proximo;
    }
}

void excluir(ListaAlunos *lista, int mat){
    No *atual = lista->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->aluno.matricula < mat){
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL && atual->aluno.matricula == mat){
        if (anterior == NULL)
            lista->inicio = atual->proximo;
        else
            anterior->proximo = atual->proximo;
        free(atual);
        lista->quantidade--;
    }
}

void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula){
    No *atual = lista->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->aluno.matricula != matriculaAntiga){
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL && atual->aluno.matricula == matriculaAntiga){
        if (anterior == NULL){
            lista->inicio = atual->proximo;
        }

        else{
            anterior->proximo = atual->proximo;
        }
        No *novo = (No *)malloc(sizeof(No));

        novo->aluno.matricula = novaMatricula;
        strcpy(novo->aluno.nome, atual->aluno.nome);
        novo->aluno.idade = atual->aluno.idade;
        atual = lista->inicio;
        anterior = NULL;
        while (atual != NULL && atual->aluno.matricula < novaMatricula){
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL){

            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }

        else{
            novo->proximo = atual;
            anterior->proximo = novo;
        }
    }
}