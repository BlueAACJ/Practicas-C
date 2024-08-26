#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*variables globales*/
char mensage,validacion[50];
int i,m,opcion;
void num(int x,int y);
void main(){
	typedef char cadena[100];/*propia variable*/
	cadena materias[20]={"Matematica","Ingles","Lenguaje de programacion","Conceptos de lenguaje","Fisica","Hokague","Musica","Koreano","Redacción","Educacion fisica","Ciencias Naturales","Dibujo ","Religion ","Frances ","Lengua y literatura","Quimica ","Geometria Analitica","Historia ","Taller electrico ","Sociologia"};/*las materias*/
	int nota[20],j,x;
	inicioo:
		clrscr();
	/*      12345678901234567890123456789012345678901234567890123456789012345678901234567890*/
	textcolor(WHITE+BLINK);
	cprintf("===========================BIENVENIDO ESTIMADO USUARIO==========================");
	printf("\nIngrese las 20 notas correxpondiente a cada clase");
	for(j=0;j<20;j++){
		gotoxy(1,4+j);printf("%s >>:",materias[j]); num(3,0);
		if(opcion<0 || opcion>100){
			j--;
			for(x=0;x<3;x++){
				printf("\b \b");
			}
		}else{
			nota[j]=opcion;
		}
	}
	printf("\n");system("pause");clrscr();
	
	printf("========================INFORMACION GENERAL DE LAS NOTAS========================");
	for(i=0;i<20;i++){
		textcolor(WHITE);
		gotoxy(1,4+i);cprintf("%s >>: %d  -> ",materias[i],nota[i]); 
		if(nota[i]>59){
			textcolor(GREEN);cprintf("Aprovado");
		}else{
			textcolor(RED);cprintf("Reprovado");
		}
	}
	textcolor(WHITE);
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
