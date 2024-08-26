/*
 * Cálculo del Promedio de Números
 * Este programa solicita al usuario que ingrese 5 números enteros y calcula su promedio.
 * Utiliza un bucle 'for' para leer los números y sumar sus valores. Luego, calcula el promedio
 * dividiendo la suma total por la cantidad de números (5) y muestra el resultado en la consola.
 */
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main()
{
    int numero[5];
    float prom = 0;
    int i;

    for(i = 0; i < 5; i++)
    {
        numero[i] = get_int ("ingrese un numero: ");
        prom = prom + numero [i];
    }

    float prom2 =  prom/5;
    printf("promedio %f \n", prom2);


    return 0;
}
