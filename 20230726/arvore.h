#ifndef arvore_h
#define arvore_h

typedef struct aux{
    int num;
    struct aux* esquerda;
    struct aux* direita;
}NO;

typedef struct{
    NO* raiz;
}ARVORE;

void inicializar(ARVORE *a);
NO* inserir_no(NO *raiz, NO *novo);
void adiciona_no(ARVORE *a, NO *novo);
void cria_no(ARVORE *a, int numero);
void busca_no(NO *raiz, int valor);
int conta_no(NO *raiz);
void print_pre_ordem(NO *raiz);
void print_in_ordem(NO *raiz);
void print_pos_ordem(NO *raiz);

#endif