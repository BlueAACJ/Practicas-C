#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
/*--prototipos------*/
char *f(char a[]);


void main(){
 char cadena[]="casa";
 char a, *b;
 clrscr();
 b=f(cadena); /* punto de llamado de la funcion , uso funcion */
 printf("%s",b);
 getch();

}  -
/*los arreglos se pueden tratar como punteros, y los punteros
como arreglos */
/* regla , toda variable de tipo parametro, o declarada
dentro de las llaves de la funcion, son consideradas locales*/
/*definiendo la funcion f,
esta funcion imprime la cadena que recibe como parametro
caracter a caracter en lineas separadas*/


char *f(char a[] ){
int i;
	for(i=0;i<strlen(a);i++){
	   printf("%c\n",a[i]);
	}
	return a;
}