#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
/*variables globales*/
char mensage,validacion[50];
int i,m,opcion;
void num(int x,int y);
void main(){
	int j,x,suma;
	inicioo:
		clrscr();
	/*      12345678901234567890123456789012345678901234567890123456789012345678901234567890*/
	textcolor(WHITE+BLINK);x=0;suma=0;
	cprintf("===========================BIENVENIDO ESTIMADO USUARIO==========================");
	textcolor(WHITE);
	gotoxy(1,2);cprintf("Los numeros multiplos de 5 son :");getch();
	for(j=1;j<101;j++){
		if(j%5==0){
			gotoxy(1,3+x);cprintf(" [%02d]",j);
			x++;
			suma+=j;
		}
		delay(100);
	}
	printf("\n");
	cprintf("La suma de los numeros es : %d",suma);
	fall:
	printf("\n");system("pause");clrscr();
	gotoxy(25,2);cprintf("DESEA VOLVER USAR EL PROGRAMA");
	gotoxy(25,3);cprintf("1-Si                     2-No");
	gotoxy(25,4);cprintf("            >>: ");num(1,0);
	switch(opcion){
		case 1:
			goto inicioo;
		case 2:
			clrscr();
			printf("saliendo");
			for(i=0;i<5;i++){
				printf(".");
				sleep(1);
			}
			return 0;
		default: 
			goto fall;
	}
}


void num(int x,int y){/*x controla el limite de caracteres max que puede ingresar el usuario*/
/*y contrala la cantidad con la que se puede presionar enter*/
	inicio2:
	for(i=0;i<=50;i++)	{
	validacion[i]=' ';	}
	i=0; m=0;
	while(mensage=getch())		{
	if(mensage==13 && i>y)	{
   		validacion[i]='\0';
		break;
	}
	else if(mensage==8)	{
	if(i>0){
		i--; 
		printf("\b \b");
	}
	}
	else {
	if(mensage> 47 && mensage<58 && i<x){/*solo numeros*/
		printf("%c",mensage);
		validacion[i]=mensage;	
		i++; 		
	}
	}
	}
	opcion=atoi(validacion);
	if(i<1){
		goto inicio2;
	}
}

