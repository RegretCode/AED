#include <stdio.h>

/* 7. Leia uma temperatura em graus Fahrenheit e apresente-a convertida em graus Celsius.
A formula de conversao e: C = 5.0 ∗ (F − 32.0)/9.0, sendo C a temperatura em Celsius
e F a temperatura em Fahrenheit.*/

int main(){
    float tempC, tempF;
    printf("Digite a temperatura em Fahrenheit para conversao em Celcius: \n");
    scanf("%f", &tempF);
    tempC = 5 * (tempF - 32)/9;
    printf("Temperatura em Celcius: %.2f", tempC);
}