/*
 * Comparación de Dos Arreglos
 * Este programa solicita al usuario que ingrese el tamaño de dos arreglos y luego solicita los elementos
 * de cada uno. Después, compara los elementos correspondientes de los dos arreglos para determinar si son
 * iguales o no. Imprime un mensaje indicando si los arreglos son iguales o diferentes.
 */
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main()
{
    int n = get_int("ingrese el tamaño del arreglo ");
    int i,j, x;
    int ar1[n], ar2[n];

    printf("arreglo A \n");

    for(i = 0; i < n; i++)
    {
        ar1[i] = get_int ("digite el elemento %d: ", i);

    }
    printf("arreglo B \n");

    for(i = 0; i < n; i++)
    {
        ar2[i] = get_int ("digite el elemento %d: ", i);

    }

    for(i = 0; i < n; i++)
    {
        if (ar1 [i] == ar2[i] )
        {

            j = 0;
        }
        else
        {
            x = 1;
        }
    }

    if(x == 1)
    {
        printf("Los arreglos no son iguales \n");
    }
    else if(j == 0)
    {
        printf("Los arreglos son iguales \n");
    }
    return 0;
}
