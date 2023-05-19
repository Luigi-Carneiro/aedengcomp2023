#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Comp.h"
Comp * criar(float real, float imaginario){
    Comp *num;
    num = malloc(sizeof(Comp));
    num->real = real;
    num->imaginario = imaginario;
    return num;
}

void somar(Comp *num1, Comp *num2){
    printf("o resultado dessa soma eh %.2f + %.2fi\n", num1->real + num2->real, num1->imaginario + num2->imaginario);
}


void subtrair(Comp *num1, Comp *num2){

    printf("o resultado dessa subtracao eh %.2f + (%.2fi)\n", num1->real - num2->real, num1->imaginario - num2->imaginario);

}


void multiplicar(Comp *num1, Comp *num2){
    if ((num1->imaginario > 0 && num2->imaginario > 0) || (num1->imaginario < 0 && num2->imaginario < 0)){
        printf("o resultado da multiplicacao entre esses numeros eh %.2f + (%.2fi)\n", num1->real*num2->real - num1->imaginario*num2->imaginario, num1->real*num2->imaginario + num2->real*num1->imaginario );
    }
    if (num1->imaginario < 0 && num2->imaginario > 0){
        printf("o resultado da multiplicacao entre esses numeros eh %.2f + (%.2fi)\n",  num1->real*num2->real - num1->imaginario*num2->imaginario, num1->real*num2->imaginario + num2->real*num1->imaginario );
    }
    if (num1->imaginario > 0 && num2->imaginario < 0){
        printf("o resultado da multiplicacao entre esses numeros eh %.2f + (%.2fi)\n",  num1->real*num2->real - num1->imaginario*num2->imaginario, num1->real*num2->imaginario + num2->real*num1->imaginario );
    }
}


void dividir(Comp *num1, Comp *num2){
    if ((num1->imaginario > 0 && num2->imaginario > 0) || (num1->imaginario < 0 && num2->imaginario < 0)){
        printf("o resultado da divisao entre esses numeros eh %.2f/%.2f + (%.2fi)/%.2f\n", num1->real*num2->real + num1->imaginario*num2->imaginario, num2->real*num2->real + num2->imaginario*num2->imaginario, -num1->real*num2->imaginario + num2->real*num1->imaginario, num2->real*num2->real + num2->imaginario*num2->imaginario);
    }
    else{
        printf("o resultado da divisao entre esses numeros eh %.2f/%.2f + (%.2fi)/%.2f\n", num1->real*num2->real + num1->imaginario*num2->imaginario, num2->real*num2->real + num2->imaginario*num2->imaginario, -num1->real*num2->imaginario + num2->real*num1->imaginario, num2->real*num2->real + num2->imaginario*num2->imaginario);
    }
}

void liberar(Comp *pnum1, Comp *pnum2){
    free(pnum1);
    free(pnum2);
}
