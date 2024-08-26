/*
 * Función de "Hola Mundo"
 * Este programa define una función llamada 'holamundo' que imprime el mensaje
 * "hola mundo desde mi función" en la consola. La función es llamada desde la función
 * principal 'main', demostrando la declaración y uso básico de funciones en C.
 */
#include <stdio.h>
#include <cs50.h>

void holamundo();

int main (void)
{
    holamundo();
    return 0;
}

void holamundo()
{

    printf ("hola mundo desde mi funcion");
}