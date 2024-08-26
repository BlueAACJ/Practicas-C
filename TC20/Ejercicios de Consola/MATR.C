#include<conio.h>
#include<stdio.h>
#define T 50
void main(void)
{
 int cant=0,i,n,j,k,suma=0,suma1=0,tam,M[T][T];

 clrscr();
 printf("Introduzca el tama¤o de la matriz: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   {
	 printf(" Introduzca el elemento M[%d][%d]",i,j);
	  scanf("%d",&M[i][j]);
   }

 for(i=0;i<n;i++)
 {
  printf("\n");
  for(j=0;j<n;j++)
   {
	 printf("\t%d",M[i][j]);
   }
  }
 fflush(stdin);
/* for(i=0;i<n;i++)*/
  for(j=0;j<n;j++)
   for(k=0;k<n;k++)
	 {
	   suma+=M[j][k];
	   if((j>=1 && j<n-1) && (k>=1 && k<n-1))
		 suma1+=M[j][k];
	 }
	cant = suma-suma1;
	printf("\n\nSuma De Los Bordes: %d , y Suma Interior: %d",cant,suma1);
  getch();

/*
 if (cant<3)
					{
						printf("De el Precio Unitario: ");
						scanf("%f", PrecioUnit);
						TotalProduct = PrecioUnit * cant;
						TotalVent = TotalVent + TotalProduct;
						printf(cant,"\t\t",PrecioUnit,"\t\t",TotalProduct);
					}*/
				}