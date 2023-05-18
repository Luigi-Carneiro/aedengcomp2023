#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Comp.h"

int main(){
    Comp *pnum1, *pnum2;
    float real, imaginario;

    printf("digite um numero complexo\n");
    scanf("%f %f", &real, &imaginario);
    pnum1 = criar(real, imaginario);

    printf("digite outro numero complexo\n");
    scanf("%f %f", &real, &imaginario);
    pnum2 = criar(real, imaginario);

    somar(pnum1, pnum2);
    subtrair(pnum1, pnum2);
    multiplicar(pnum1, pnum2);
    dividir(pnum1, pnum2);
    liberar(pnum1, pnum2);
}