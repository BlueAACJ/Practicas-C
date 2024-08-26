/*
 * Dibujo de un Cuadrado de Numerales
 * Este programa solicita al usuario que introduzca un número entre 0 y 23 para determinar
 * la altura del cuadrado. Luego, utiliza este número para dibujar un cuadrado de '#' en la consola,
 * donde cada línea del cuadrado contiene el número de numerales correspondiente a la altura del cuadrado.
 */

#include <stdio.h>
#include <cs50.h>

int main ()
{
    int linea, espacios, altura, numerales ;

    do
    {
        altura  = get_int("Introduzaca un número entre 0 y 23 para dibujar el cuadrado: ");
    }
    while (altura < 0 || altura > 23);

    for (linea = 0; linea < altura; linea++)
    {
        for (numerales = 0; numerales < altura; numerales++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
