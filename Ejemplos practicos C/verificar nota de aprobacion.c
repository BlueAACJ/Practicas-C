/*
 * Evaluación de Aprobación
 * Este programa solicita al usuario que ingrese una calificación numérica. Luego evalúa la calificación
 * para determinar si el usuario ha aprobado o reprobado. Si la calificación es menor que 60, el programa
 * imprime "reprobado"; de lo contrario, imprime "aprobado".
 */
#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int nota=0;

    nota = get_int("ingrese su nota\n");

    if ( nota < 60 )
    {
        printf("reprobado \n");
    }
    else
    {
        printf("aprobado\n");
    }

    return 0;
}