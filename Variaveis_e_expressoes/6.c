#include <stdio.h>

/* 6. Leia uma temperatura em graus Celsius e apresente-a convertida em graus Fahrenheit.
A formula de conversao eh: F = C∗(9.0/5.0)+32.0, sendo F a temperatura em Fahrenheit
e C a temperatura em Celsius.*/

int main(){
    float tempC, tempF;
    printf("Digite a temperatura em Celcius para conversao em Fahrenheit: \n");
    scanf("%f", &tempC);
    tempF= tempC*(1.8)+32;
    printf("Temperatura em Fahrenheit: %.2f", tempF);
}