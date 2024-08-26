#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void main()
{
  char cadena[]="managua";
  char *p,*q;
  p=cadena;
  q=cadena;
  clrscr();
  printf("%c",*p);
  p++;
  printf("%c\n",*p);
  p=p+2;
  printf("%c %c %c",*p,p[0],*(cadena+1));
  p=q;

  q=malloc(sizeof(char)*10);
  strcpy(q,cadena);
  printf("%s %s",q,cadena);
  getch();
}