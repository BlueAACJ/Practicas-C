/*
 * Evaluación de Calificación
 * Este programa solicita al usuario que ingrese una calificación numérica entre 0 y 100.
 * Utiliza un bucle 'do-while' para asegurar que la calificación ingresada esté en el rango válido.
 * Luego, evalúa la calificación y asigna una letra de calificación basada en el rango en el que se encuentra:
 * - 'S' para calificaciones 95 o mayores
 * - 'A' para calificaciones entre 90 y 94
 * - 'B' para calificaciones entre 80 y 89
 * - 'C' para calificaciones entre 70 y 79
 * - 'D' para calificaciones entre 60 y 69
 * - 'F' para calificaciones menores a 60
 */
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("ingrese su calificacion: ");
    }
    while (n <= -1 || n > 100);

    if (n >= 95)
    {
        printf("tienes una s \n");
    }

    else if (n >= 90)
    {
        printf("tienes una A \n");
    }
    else if (n >= 80)
    {
        printf("tienes una B \n");

    }
    else if (n >= 70)
    {
        printf("tienes una C \n");

    }
    else if (n >= 60)
    {
        printf("tienes una D \n");
    }
    else
    {
        printf("tienes una F \n");
    }

    return 0;
}
