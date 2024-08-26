/*
 * Impresión de Números del 0 al 9
 * Este programa imprime los números del 0 al 9 en la consola. Utiliza un bucle 'for'
 * para iterar a través de los números y mostrarlos en la salida estándar.
 */
#include <stdio.h>
#include <cs50.h>

int main (void)
{
    for (int i = 0 ; i < 10 ; i ++ )
    {
        printf ("%d\n", i );
    }

    return 0;
}