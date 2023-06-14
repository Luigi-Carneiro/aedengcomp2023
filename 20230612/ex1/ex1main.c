#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

#define size 10

int main(){
    NO *head = NULL;
    NO *listaK;
    for (int i = 0; i < size; i++){
        head = inserir(head);
    }
    print(head);
    ordenar(head, &listaK);
    print(listaK);
    return 0;
}