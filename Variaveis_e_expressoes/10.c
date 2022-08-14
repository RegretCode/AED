#include <stdio.h>

/*10. Leia uma velocidade em km/h (quilometros por hora) e apresente-a convertida em m/s ˆ
(metros por segundo). A formula de conversao e: M = K/3.6, sendo K a velocidade em
km/h e M em m/s.
*/

int main(){
    float m, k;
    printf("Digite a velocidade em km/h para converter em m/s: \n");
    scanf("%f", &k);
    m = k/3.6;
    printf("Conversao para m/s: %2.f", m);
}