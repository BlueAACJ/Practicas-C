// Verifique si un numero es positivo o negativo 
// Hecho en CS50
#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int numero=0;

    numero = get_int("ingrese un numero\n");

    if (numero < 0)
    {
        printf("el numero es negativo \n");
    }
    else
    {
        printf("el numero es positivo\n");
    }

    return 0;
}
