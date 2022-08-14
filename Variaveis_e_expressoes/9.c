#include <stdio.h>

/*9. Leia uma temperatura em graus Celsius e apresente-a convertida em graus Kelvin. A
formula de conversao e: K = C + 273.15, sendo C a temperatura em Celsius e K a
temperatura em Kelvin.*/

int main(){
    float tempC, tempK;
    printf("Digite a temperatura em Celcius para conversao em Kelvin: \n");
    scanf("%f", &tempC);
    tempK = tempC + 273.15;
    printf("Temperatura em Kelvin: %.2f", tempK);
}