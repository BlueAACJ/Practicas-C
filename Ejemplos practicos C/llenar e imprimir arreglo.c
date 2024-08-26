/*
 * Entrada y Salida de Valores en un Arreglo
 * Este programa crea un arreglo de 5 enteros y solicita al usuario que ingrese 5 números para llenar el arreglo.
 * Luego, imprime los números ingresados en la consola. Utiliza dos bucles 'for': uno para la entrada de datos
 * y otro para la salida.
 */
#include <stdio.h>
#include <cs50.h>

int main ()
{
    int array1[5];

    for(int i = 0; i < 5; i++)
    {
        array1[i] = get_int ("ingresa un numero:");
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", array1[i]);
    }
    return 0;
}
