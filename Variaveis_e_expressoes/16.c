#include <stdio.h>

/*16. Leia um valor de comprimento em polegadas e apresente-o convertido em centımetros.
A formula de conversao e: C = P ∗ 2, 54, sendo C o comprimento em centımetros e P o
comprimento em polegadas.*/

int main(){
    float c, p;
    printf("Digite o valor em polegadas que deseja converter em centimetros: \n");
    scanf("%f", &p);
    c = p*2.54;
    printf("Convertido em centimetros: %2.f", c);
}