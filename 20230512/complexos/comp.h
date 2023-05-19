struct complexo{
    float real;
    float imaginario;
};
typedef struct complexo Comp;
Comp * criar(float real, float imaginario);
void somar(Comp *num1, Comp *num2);
void subtrair(Comp *num1, Comp *num2);
void multiplicar(Comp *num1, Comp *num2);
void dividir(Comp *num1, Comp *num2);
void liberar(Comp *pnum1, Comp *pnum2);
