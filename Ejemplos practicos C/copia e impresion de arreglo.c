/*
 * Copiar y Mostrar un Arreglo
 * Este programa toma un número entero como argumento de línea de comandos
 * para determinar el tamaño de un arreglo. Luego, solicita al usuario que ingrese
 * los valores del arreglo original, crea una copia del mismo, y finalmente muestra
 * ambos arreglos en la consola.
 */
#include<stdio.h>
#include<cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int k = atoi(argv[1]);

    int original[k];
    int copia[k];

    for (int i = 0; i < k; i++)
    {
        original[i] = get_int("ingrese el valor[%i] del arreglo: ",i+1);
    }

    printf("Original [ ");
    for (int i = 0; i < k; i++)
    {
        printf(" %i", original[i]);

        copia[i] = original[i];
    }
    printf("  ]\n");

    printf("Copia [ ");
    for (int i = 0; i < k; i++)
    {
        printf(" %i", copia[i]);
    }
    printf("  ]\n");
    return 0;

}