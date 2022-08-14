#include <stdio.h>

/*14. Leia um angulo em graus e apresente-o convertido em radianos. A formula de conversao e: R = G ∗ π/180, sendo G o angulo em graus e R em radianos e π = 3.14.*/

int main(){
    float g, r;
    printf("Digite o angulo em graus que deseja converter em radianos: \n");
    scanf("%f", &g);
    r = g * (3.14/180);
    printf("Conversao para radianos: %.2f", r);
}