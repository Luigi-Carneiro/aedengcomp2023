#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char nome[50];
    int idade;
    int nfilhos;
} Aluno;

typedef struct{
    Aluno *elementos;
    int tamanho;
    int capacidade;
} Lista;

void criarLista(Lista *lista, int capacidade){
    lista->elementos = (Aluno *)malloc(capacidade * sizeof(Aluno));
    lista->tamanho = 0;
    lista->capacidade = capacidade;
}

void inserirDesordenado(Lista *lista, Aluno aluno){
    if (lista->tamanho < lista->capacidade){
        lista->elementos[lista->tamanho] = aluno;
        lista->tamanho++;
    }
    else{
        printf("Lista cheia\n");
    }
}

void inserirOrdenado(Lista *lista, Aluno aluno){
    if (lista->tamanho < lista->capacidade){
        int i = lista->tamanho - 1;
        while (i >= 0 && lista->elementos[i].codigo > aluno.codigo){
            lista->elementos[i + 1] = lista->elementos[i];
            i--;
        }
        lista->elementos[i + 1] = aluno;
        lista->tamanho++;
    }
    else{
        printf("Lista cheia\n");
    }
}

int QuantidadeElementos(Lista *lista){
    return lista->tamanho;
}

int BuscaSequencial(Lista *lista, int codigo){
    for (int i = 0; i < lista->tamanho; i++){
        if (lista->elementos[i].codigo == codigo){
            return i;
        }
    }
    return -1;
}

int BuscaBinaria(Lista *lista, int codigo){
    int inicio = 0;
    int fim = lista->tamanho - 1;

    while (inicio <= fim){
        int meio = (inicio + fim) / 2;

        if (lista->elementos[meio].codigo == codigo){
            return meio;
        }
        else if (lista->elementos[meio].codigo < codigo){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }

    return -1;
}

void excluirElementoPosicao(Lista *lista, int posicao){
    if (posicao >= 0 && posicao < lista->tamanho){
        for (int i = posicao; i < lista->tamanho - 1; i++){
            lista->elementos[i] = lista->elementos[i + 1];
        }
        lista->tamanho--;
    }
    else{
        printf("Posição inválida.\n");
    }
}

void excluirElementoValor(Lista *lista, int codigo){
    int posicao = BuscaSequencial(lista, codigo);
    if (posicao != -1){
        excluirElementoPosicao(lista, posicao);
    }
    else{
        printf("Elemento não encontrado.\n");
    }
}

void imprimirLista(Lista *lista){
    printf("Lista de Alunos:\n");
    for (int i = 0; i < lista->tamanho; i++){
        Aluno aluno = lista->elementos[i];
        printf("Código: %d, Nome: %s, Idade: %d, Número de Filhos: %d\n",
               aluno.codigo, aluno.nome, aluno.idade, aluno.nfilhos);
    }
    printf("\n");
}

int main(){
    Lista lista;
    criarLista(&lista, 10);

    Aluno aluno1 = {1, "João Silva", 20, 0};
    Aluno aluno2 = {2, "Maria Santos", 22, 1};

    inserirDesordenado(&lista, aluno1);
    inserirDesordenado(&lista, aluno2);

    imprimirLista(&lista);

    int posicao = BuscaSequencial(&lista, 2);
    if (posicao != -1){
        printf("Aluno com código 2 encontrado na posição %d\n", posicao);
    }
    else{
        printf("Aluno com código 2 não encontrado na lista\n");
    }

    excluirElementoValor(&lista, 2);

    imprimirLista(&lista);

    printf("Quantidade de elementos: %d\n", QuantidadeElementos(&lista));

    return 0;
}