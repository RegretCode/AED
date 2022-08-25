#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* 23. Escreva um programa que receba dois structs do tipo dma, cada um representando uma
data valida, e calcule o numero de dias que decorreram entre as duas datas.*/

struct dma
{
	int dia;
	int mes;
	int ano;
};


int main()
{
	struct dma data1, data2;
	//primeira data
	data1.dia = 4;
	data1.mes = 10;
	data1.ano = 1999;
	//segunda data
	data2.dia = 15;
	data2.mes = 10;
	data2.ano = 1999;

	int dataEstruturada1 = (data1.dia)+(30*data1.mes)+(365*data1.ano);
	int dataEstruturada2 = (data2.dia)+(30*data2.mes)+(365*data2.ano);

	printf("Numero de dias que decorreram entre as duas datas: %d dias\n", abs(dataEstruturada1-dataEstruturada2));
	system("pause");
}