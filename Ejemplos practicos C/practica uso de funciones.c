/*
 * Operaciones Aritméticas Básicas
 * Este programa realiza cuatro operaciones aritméticas básicas: resta, suma, multiplicación y división.
 * Define funciones para cada operación y las llama desde la función principal con dos números enteros.
 * Los resultados de las operaciones se imprimen en la consola.
 */
#include <stdio.h> 
#include <cs50.h> 
void restar (int a , int b );
void sumar (int a , int b );
void multiplicar (int a , int b );
void dividir (int a , int b );
int main ()
{
    int x , y ;
    x = y = 0;
    x = 4 ;
    y = 6 ;
    
    restar (x,y);
    sumar (x,y);
    multiplicar (x,y);
    dividir (x,y);
    
    return 0; 
}
void restar (int a , int b )
{
    printf ("la resta de a - b es: %d \n",(a-b));
}
void sumar ( int a , int b )
{
    printf ("la suma de a + b es: %d \n ", (a+b));
}
void multiplicar (int a , int b )
{
    printf ("la multiplicacion de a * b es:%d \n", (a*b));
}
void dividir (int a , int b)
{
    printf ("la division de a / b es : %d \n", (a/b));
}
