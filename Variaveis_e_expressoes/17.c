#include <stdio.h>

/*17. Leia um valor de comprimento em centımetros e apresente-o convertido em polegadas.
A formula de conversao e: P = C/2,54 , sendo C o comprimento em centımetros e P o comprimento em polegadas.
.*/

int main(){
    float c, p;
    printf("Digite o valor em centimetros que deseja converter em polegadas: \n");
    scanf("%f", &c);
    p = c/2.54;
    printf("Convertido em centimetros: %.2f", p);
}