/*Este programa calcula el mayor de los elementos
  de un arreglo y dice en que posicion se encuentra
  y lo cambia por el primer elemento */


#include<conio.h>
#include<stdio.h>

void main (void)
{
	int elemen,i, posicion;
	float elementos[100],mayor;
	clrscr();
	printf("Cantidad de Elementos:\n\n ");
			scanf("%d",&elemen);
	for (i=0;i<elemen;i++)
	{
		printf("Digite el Elemento: ");
		scanf("%f",&elementos[i]);
   	}
	mayor=elementos[0];
	posicion = 0;
	for (i=1;i<=elemen;i++)
	{
	   if (elementos[i] > mayor)
	   {
		 mayor = elementos[i];
		 posicion = i;
	   }
	}
	   printf("Elemento Mayor: %f",mayor);
	   printf("\n\nLa posicion es: %d",posicion+1);
	   getch();
}
