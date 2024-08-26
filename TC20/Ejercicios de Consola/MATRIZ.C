/* En una matriz bidimencional halle la suma de las columnas*/

#include <stdio.h>
#include <conio.h>


void main (void)
{
   int i,j,filas,suma,columnas,matriz[100][100];

	clrscr();
	printf("Filas: ");
	scanf("%d",&filas);

	printf("Columnas: ");
	scanf("%d",&columnas);

	for (i=0;i<filas;i++)
		for (j=0;j<columnas;j++)
		{
		printf("Elemento (%d,%d): ",i,j);
		scanf("%d",&matriz[i][j]);
		}

	for (j=0;j<columnas;j++)
	{
		suma=0;
	for (i=0;i<filas;i++)
	{
	   suma+=matriz[i][j];

	}
	printf("La suma es: %d\n",suma);
	}

   getch();
}