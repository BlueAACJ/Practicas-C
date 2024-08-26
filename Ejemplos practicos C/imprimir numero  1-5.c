/*
 * Impresión de Números Menores a 5
 * Este programa imprime los números del 0 al 9 en la consola, pero solo muestra
 * aquellos que son menores que 5. Utiliza un bucle 'for' para iterar y una instrucción
 * 'if' para determinar cuáles números imprimir.
 */
#include <stdio.h>
#include <cs50.h>

int main (void)
{
    for (int i = 0 ; i < 10 ; i ++ )
    {
        if ( i < 5 )
        {
            printf ("%d\n", i );
        }
    }

    return 0;
}
