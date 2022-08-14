#include <stdio.h>

/*11. Leia uma velocidade em m/s (metros por segundo) e apresente-a convertida em km/h
(quilometros por hora). A formula de conversao˜ e: K = M ∗ 3.6, sendo K a velocidade
em km/h e M em m/s.*/

int main(){
    float m, k;
    printf("Digite a velocidade em m/s para converter em km/h: \n");
    scanf("%f", &m);
    k = m*3.6;
    printf("Conversao para km/h: %2.f", k);
}