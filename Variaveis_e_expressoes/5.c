#include <stdio.h>

/* 5. Leia um numero real e imprima a quinta parte deste numero.*/

int main(){
    float numeroReal, quintaParte;
    printf("Digite um numero real: \n");
    scanf("%f", &numeroReal);
    quintaParte = numeroReal * 1/5;
    printf("A quinta parte do numero informado eh: %f", quintaParte);
}