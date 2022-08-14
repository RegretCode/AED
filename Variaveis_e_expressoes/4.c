#include <stdio.h>

/* 4. Leia um numero real e imprima o resultado do quadrado desse numero.*/

int main(){
    float numeroReal;
    printf("Digite um numero real: \n");
    scanf("%f", &numeroReal);
    numeroReal =(numeroReal*numeroReal);
    printf("%.2f", numeroReal);
}