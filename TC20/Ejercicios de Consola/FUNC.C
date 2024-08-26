#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void f(char a[]);  /*declaracion de prototipo */
void  main(){
char cadena[]="cadena";
char a,*b;
clrscr();
f(cadena); /*llamar a la funcion o usar la funcion */
getch();
}

/*los arreglos se pueden manipular
como punteros y viceversa
*/
   /* definicion de la funcion */
/*esta funcion recibe una cadena de caracteres
y las imprime caracter a caracter */
void f(char a[]){
int i;
   for(i=0;i< strlen(a);i++){
	  printf("%c\n",*(a+i));
   }
}

/*tipo nombre(lista valores){

 return ....
} */