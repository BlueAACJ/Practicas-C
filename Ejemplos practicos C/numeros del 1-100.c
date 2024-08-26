/*
 * Impresión de Números del 0 al 100
 * Este programa imprime los números del 0 al 100, uno por línea, utilizando un bucle 'for'.
 * Cada número se muestra en la consola con un salto de línea después.
 */
#include<stdio.h>
#include<cs50.h>
int main(void )
{

    for (int i=0 ; i<101 ; i++)
    {
        printf (" %d\n ",i)  ;
    }
    
    return 0 ;
}
