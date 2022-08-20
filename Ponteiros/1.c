#include <stdio.h>

/* 1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de
cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos a 
modificacao. */

int main(){
    int i = 10;
    float r = 0.5;
    char c = 'A';

    int *pI = &i;
    float * pR = &r;
    char *pC = &c;

    printf("Antes da modificacao\n");
    printf("%d\n", *pI);
    printf("%f\n", *pR);
    printf("%c\n", *pC);

    *pI = 20;
    *pR = 0.8;
    *pC = 'B';

    printf("Apos a modificacao\n");
    printf("%d\n %f\n %c", *pI, *pR, *pC);


}