/*
 * Tabla de Multiplicar
 * Este programa solicita al usuario que ingrese un número entero y luego imprime la tabla de multiplicar
 * de ese número del 0 al 12. Utiliza un bucle 'for' para iterar a través de los valores del 0 al 12 y
 * muestra el resultado de la multiplicación de cada valor por el número ingresado en la consola.
 */
#include <stdio.h>
#include <cs50.h>
int main(void )
{
    int a = get_int ("Ingrese un numero entero y sera multiplicado del 0 al 12 :");
    for (int i=0; i<13 ; i++)
    {
        printf ("%d * %d = %d\n", a ,i, a*i);
    }
    
    return 0 ;
}
