#include <stdio.h>

/* 1. Escreva um trecho de codigo para fazer a criacao dos novos tipos de dados conforme 
solicitado abaixo:
• Horario: composto de hora, minutos e segundos. 
• Data: composto de dia, mes e ano. 
• Compromisso: composto de uma data, horario e texto que descreve o compromisso.*/

typedef struct horario{
	int horas, minutos, segundos;
};

typedef struct data{
	int dia, mes, ano;
};

typedef struct compromisso{
	struct data essaData;
	struct horario esseHorario;
	char descricao[100];	
};

