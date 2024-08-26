/*---------------------------*/
/*  Ejemplo en C nº 59:      */
/*  C059.C                   */
/*                           */
/*  Información sobre un     */
/*  fichero BMP (1)          */
/*                           */
/*  Curso de C,              */
/*    Nacho Cabanes          */
/*---------------------------*/

#include <stdio.h>

int main(){

  char nombre[60];
  FILE* fichero;
  int compresion;

  puts("Comprobador de imágenes BMP\n");
  printf("Dime el nombre del fichero: ");
  gets(nombre);
  fichero = fopen(nombre, "rb");
  if (fichero==NULL)
    puts("No encontrado\n");
  else {
    fseek(fichero, 30, SEEK_SET);
    fread(&compresion, 1, 4, fichero);
    fclose(fichero);
	if (compresion == 0)
      puts("Sin compresión");
   else
      puts ("BMP Comprimido ");
  }

  return 0;
}
