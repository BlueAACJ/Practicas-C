#include<stdio.h>
#include<conio.h>
void main(){
 char *ciudades[]={"managua","esteli","leon","masaya"};
 char **p,*q;
 clrscr();
 p=ciudades;
 p++;
 q=ciudades[2];
 q++;
 printf("%s %c\n",q,*p++);
 printf("%c %c %c\n",ciudades[3][4],*q,**p++);
 getch();
}