/*
 * Dibujo de una Escalera al Estilo de Mario Bros
 * Este programa solicita al usuario un número entre 0 y 23 para determinar la altura de una escalera 
 * al estilo de Mario Bros. Luego, dibuja la escalera utilizando el carácter '#' para las peldaños y
 * espacios en blanco para el relleno, en una estructura de escalera inclinada a la derecha.
 * El código incluye correcciones para la inicialización de variables y la lógica de impresión para
 * lograr el formato correcto de la escalera.
 */
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int  i, n, j ;
    do
    {
        printf("Este programa dibujara una escalera al estilo de Mario Bros con # \n");
        n  = get_int("Introduzaca un número entre 0 y 23 para dibujar la escalera: ");
    }
    while (n < 0 || n > 23);
    // la variables i estaba mal inicializada
    for (i = 1; i < n; i++)
    {
        // debe haber un incremento en j
        for (j = 0; j < n; j++)
        {
            //las # y los espacios estaban al reves
            if(i + j >= (n - 1))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0 ;
}
