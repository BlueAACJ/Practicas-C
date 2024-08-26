//02/09/2021
//El siguiente problema consiste en un arreglo con los siguientes elementos [1,2,3,4,5] y
//se desea aumentar en 5 los siguientes elementos, 2 y 4, como seria la solución a este caso?
#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

int main ()
{
    int array1[5] = {1, 2, 3, 4, 5};
    int suma=0;

    for (int i=0; i < 5; i++)
    {
        printf(" %i", array1[i]);

    }
    printf("\n arreglo orignal\n ");

    for (int i=0; i < 5; i++)
    {

        if (array1[i] % 2 == 0)
        {

            suma = array1[i] + 5;

            printf (" %i",suma);
        }
        else
        {
        printf(" %i", array1[i]);
        }


    }
    printf("\n arreglo con la suma\n ");

    return 0;
}