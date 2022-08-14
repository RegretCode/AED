#include <stdio.h>

/*8. Leia uma temperatura em graus Kelvin e apresente-a convertida em graus Celsius. A
formula de conversao e: C = K − 273.15, sendo C a temperatura em Celsius e K a
temperatura em Kelvin.
*/

int main(){
    float tempC, tempK;
    printf("Digite a temperatura em Kelvin para conversao em Celcius: \n");
    scanf("%f", &tempK);
    tempC = tempK -273.15;
    printf("Temperatura em Celcius: %.2f", tempC);
}