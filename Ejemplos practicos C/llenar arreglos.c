/*
 * Inicialización y Llenado de Arreglos
 * Este programa solicita al usuario que ingrese la dimensión de un arreglo (x), 
 * luego crea dos arreglos: uno de tamaño fijo N y otro de tamaño variable basado en la entrada del usuario.
 * Después, llena el arreglo de tamaño fijo con valores ingresados por el usuario.
 * Nota: El arreglo de tamaño variable 'arrar' no se utiliza en el código actual.
 */
#include <stdio.h>
#include <cs50.h>

#define N 10

int main ()
{
    int x = get_int("ingrese la dimension del arreglo ");
    int array2 [N];

    int arrar[x];

    for (int i = 0; i < N; i++)
    {
        array2 [i] = get_int("ingrese valores \n");
    }
    return 0;
}