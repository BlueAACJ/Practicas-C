	# include <stdio.h>
	# include <conio.h>
	# include <ctype.h>
	# include <stdlib.h>

	void main(main)
	{
		int cant, i, Producto;
		float PrecioUnit, TotalDesc, TotalVent, TotalProduct;

		clrscr();
		TotalVent = 0;
		printf("\t\tIntroduzca Cuantos Productos de Diferentes Marca LLeva:");
		scanf("%d",&Producto);
		for (i=0;i<=Producto;i++)
			{
				printf("Cuantas Cantidades del Producto %d hay:", i+1);
				scanf("%d",&cant);
				if (cant<3)
					{
						printf("De el Precio Unitario: ");
						scanf("%f", &PrecioUnit);
						TotalProduct = PrecioUnit * cant;
						TotalVent = TotalVent + TotalProduct;
						printf("%d\t\t\t%f\t\t\t%f\n",cant,PrecioUnit,TotalProduct);
						getch();
					}

			}
	}



