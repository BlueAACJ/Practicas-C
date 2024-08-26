/*
 * Validación del Número de Niños por Familia
 * Este programa solicita al usuario que ingrese el número de niños por familia. 
 * Luego verifica si el número ingresado es exactamente 2. Si el número no es 2,
 * el programa imprime "eso es incorrecto". De lo contrario, imprime "eso es correcto".
 */
#include<stdio.h>
#include<cs50.h>
int main(void )
{

    int niño = get_int ("ingrese el numero de niños por familia ");

    if (niño  != 2 )
    {
        printf("eso es incorrecto\n ");
    }
    else
    {
        printf ("eso es correcto \n");
    }

    return 0 ;
}
