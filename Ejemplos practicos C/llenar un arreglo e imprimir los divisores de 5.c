/*
 * Impresión de Múltiplos de 5 en un Arreglo
 * Este programa crea un arreglo de 100 enteros e inicializa cada elemento con su índice (0 a 99).
 * Luego, recorre el arreglo y imprime los números que son múltiplos de 5.
 * Utiliza un bucle 'for' para inicializar el arreglo y otro para filtrar e imprimir los múltiplos de 5.
 */
#include <stdio.h>
#include <cs50.h>

int main ()
{
    int array1[100];

    for(int i = 0; i < 100; i++)
    {
        array1[i] = i;
    }

    for (int i = 0; i < 100; i++)
    {
        if (array1[i] %5 == 0)
        {
        printf("%d \n", array1[i]);
        }
    }
    return 0;
}
