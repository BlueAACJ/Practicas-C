//02/09/2021
//Realice un programa en C donde se imprima la matriz nula, la matriz debe de estar contenida en un arreglo bidimensional
#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

int main ()
{
    int matriz [2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matriz [i][j] = 0;
            printf ("%d ", matriz [i][j]);
        }

        printf("\n");
    }


    return 0;
}