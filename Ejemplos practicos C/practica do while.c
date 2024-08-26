// 21/08/2021
/*
 * Solicitud de un Número Positivo
 * Este programa solicita al usuario que ingrese un número positivo. Utiliza un bucle 'do-while'
 * para seguir solicitando la entrada hasta que el usuario ingrese un número mayor que 0.
 * Una vez que se ingresa un número positivo, el programa termina.
 */
#include <stdio.h>
#include <cs50.h>

int main()
{
    int n = 0 ;
    do
    {
        n = get_int("por favor escriba un numero positivo ");

    }
    while (n <= 0);

    return 0;
}