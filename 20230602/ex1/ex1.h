#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    int matricula;
    char nome[20];
    int idade;

} Aluno;

typedef struct No {
    Aluno aluno;
    struct No *proximo;

} No;

typedef struct ListaAunos{
    No *inicio;
    int quantidade;

} ListaAlunos;

int tamanho(ListaAlunos *lista);
void inicializar(ListaAlunos *lista);
void print(ListaAlunos *lista);
void vaziacheia(ListaAlunos *lista);
void inserir(ListaAlunos *lista, Aluno aluno);
void excluir(ListaAlunos *lista, int mat);
void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula);
void liberar(ListaAlunos *lista);