/*
 * Selección Aleatoria de Pokémon
 * Este programa solicita al usuario que introduzca el nombre de 5 Pokémon y los almacena en un arreglo.
 * Luego, selecciona aleatoriamente uno de los Pokémon ingresados y muestra un mensaje indicando cuál Pokémon ha sido elegido.
 */
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main()
{
    string pokemon[5];
    int i, pokemonal = rand() % 5 ;
    for(i = 0; i < 5; i++)
    {
        pokemon[i] = get_string ("Dame un pokemon: ");
    }

    printf("%s Yo te elijo ", (pokemon[pokemonal]));

    return 0;
}
