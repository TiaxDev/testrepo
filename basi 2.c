/*
	Name:
	Copyright: /
	Author: Mattia Tanzini
	Date: 
	Description:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_BASE 36

void main(){
	int base, n, conta, tot, pot, esp, last, err;
	tot = pot = esp = 0;
	char numero[50], n1[50];
	char lastc;
	do{
		fflush(stdin);
		err = 0;
		printf("Inserisci numero da convertire: \n");
		gets(numero);
		printf("Inserisci base iniziale: \n");
		scanf("%d", &base);
		if(numero[0]=='-'){
			printf("Errore nel numero.\n");
			err = 1;
		}
		
		else if(base<=0 || base>MAX_BASE){
			printf("Errore nella base.\n");
			err = 1;
		}
	}while(err);
	strupr(numero);
	strcpy(n1, numero);
	last = strlen(n1) -1;
	for(conta=0; numero[conta]!='\0'; conta++){
		numero[conta] = n1[last-conta];
		if(numero[conta]>='A' && numero[conta]<='Z')
			n = numero[conta]-55;
		else if(numero[conta]>='0' && numero[conta]<='9')
			n = numero[conta]-48;
		if(n>=base){
			if(base>10){
				lastc = 54+base; 
				printf("Errore, le cifre devono essere comprese tra 0 e %c\n",  lastc);
			}
			else
				printf("Errore, le cifre devono essere comprese tra 0 e %d", base-1);
			system("PAUSE");
		}
		pot = pow(base, esp);
		esp++;
		tot += n*pot;
	}
	printf("Numero convertito in base 10: %d\n", tot);
	
	getch();
}

