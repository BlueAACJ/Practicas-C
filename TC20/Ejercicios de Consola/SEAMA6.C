#include<stdio.h>
#include<conio.h>
void main(void){
char *ciudades[]={"managua","esteli","leon","masaya"};
char **p,*q;
clrscr();
p=ciudades;
p++;
q=ciudades[2];
q++;
printf("%s %5s \n",ciudades[2],*p++);
printf("%c %c %c\n",ciudades[3][4],*q,**p);
getch();
}