/*
 * Contador y Modificador de Caracteres en la Cadena de Entrada
 * Este programa toma un argumento de línea de comandos, que debe ser una cadena de caracteres.
 * Primero, verifica si se ha pasado exactamente un argumento. Luego, calcula y muestra la longitud
 * de la cadena de caracteres. Finalmente, imprime cada carácter de la cadena con un valor incrementado
 * en una constante definida (N) en su representación ASCII.
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define N 1
int main (int strrv, char **strg)
{

    if (strrv != 2)
    {
        printf ("error\n ");
        return 1;
    }

    string cadena = strg [1];

    int long_ = strlen (cadena);

    printf ("numero de caracteres es: %d \n ", long_);

    for (int i = 0; i < long_; i++ )
    {
        printf("%c ", (cadena[i] + N))  ;
    }

    return 0;
}
