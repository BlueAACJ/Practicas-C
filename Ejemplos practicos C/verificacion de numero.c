/*
 * 2021
 * Evaluación de Rango de Números
 * Este programa solicita al usuario que ingrese un número entero positivo y luego evalúa
 * el número ingresado para determinar en qué rango se encuentra. Dependiendo del valor del número,
 * el programa imprime un mensaje indicando si el número es exactamente 10, menor que 10, mayor
 * que 10 pero menor que 100, o mayor que 100.
 */
#include <stdio.h> 
#include <cs50.h>
int main (void)
{
  int n = get_int(" ingrese un numero positivo\n ")  ;

    if (n==10)
    {
        printf("su numero es 10\n");
    }
    else 
    {
        if (n<10 )
        {  
            printf("su numero es menor a 10\n");
        }
        else 
        {
          if (n<100)
            {
            printf("su numero es mayor a 10 pero menor a 100\n");
            }
          else
            {
            printf("su numero es mayor a 100\n");
            }
        }
    }
    
    return 0 ; 
  
}