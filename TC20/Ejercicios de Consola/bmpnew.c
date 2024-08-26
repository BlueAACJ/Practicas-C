#include <stdio.h>
#include <stdlib.h>
/*#define BUFFER 0x100 */

typedef struct
{
int pixels_ancho;
int pixels_alto;
int bits_x_pixel;
int compresion; /*0-ninguna,1-RLE8, 2-RLE4    */
}foto;

typedef struct
{
/*int b;
int g;
int r; */
int gris;/*para que tengo 8 bits */
}rgb;

void main()
{
FILE *fichero,*fichero_salida;
char nombre[20] = "s11.bmp",nombre2[20] = "foto2.bmp";
foto imagen;
int buffer,*buffer_imag,num_bytes,i,num_bytes_salida;
rgb *buffer_rgb;



if ((fichero = fopen(nombre, "rb")) == NULL)/*Abro la foto para lectura en binario */
{
printf("El fichero no existe o no se puede abrir.\n");
exit(-1);
}

if ((fichero_salida = fopen(nombre2, "wb")) == NULL) /*Abro la foto para escritura en binario    */
{
printf("El Fichero no existe o no se puede abrir.\n");
exit(-1);
}

/*COMIENZO LA LECTURA DE LA CABECERA Y ESCRIBO LA CABECERA DE LA SALIDA (cambio los 24 bits por 8 bits) */

/*parte de la cabecera que no interesa  */
fread(&buffer,1,2,fichero);
fwrite(&buffer,1,2,fichero_salida);
fread(&buffer,1,4,fichero);
buffer = 800*533+54; /*bytes imagen + cabecera */
fwrite(&buffer,1,4,fichero_salida);
fread(&buffer,1,2,fichero);
fwrite(&buffer,1,2,fichero_salida);
fread(&buffer,1,2,fichero);
fwrite(&buffer,1,2,fichero_salida);
fread(&buffer,1,4,fichero);
fwrite(&buffer,1,4,fichero_salida);
fread(&buffer,1,4,fichero);
fwrite(&buffer,1,4,fichero_salida);
fread(&buffer,1,4,fichero);/*ancho en pixels */
imagen.pixels_ancho = buffer;
fwrite(&buffer,1,4,fichero_salida);
fread(&buffer,1,4,fichero);/*alto en pixels  */
imagen.pixels_alto = buffer;
fwrite(&buffer,1,4,fichero_salida);
fread(&buffer,1,2,fichero);/*no interesa */
fwrite(&buffer,1,2,fichero_salida);
fread(&buffer,1,2,fichero);
imagen.bits_x_pixel = buffer;
buffer=24; /*<------------------esta es la linea que si cambio pasa de verse borrosa(8bits) a verse bien pero por triplicado y en peque&#241;o (24bits)   */
fwrite(&buffer,1,2,fichero_salida);/*8bits por pixel */
fread(&buffer,1,4,fichero);
imagen.compresion = buffer;
fwrite(&buffer,1,4,fichero_salida);
fread(&buffer,1,4,fichero);
/*buffer = 800*533;//1byte por pixel y 800x533 pixels */
fwrite(&buffer,1,4,fichero_salida);
fread(&buffer,1,4,fichero);
fwrite(&buffer,1,4,fichero_salida);
fread(&buffer,1,4,fichero);
fwrite(&buffer,1,4,fichero_salida);
fread(&buffer,1,4,fichero);
fwrite(&buffer,1,4,fichero_salida);
fread(&buffer,1,4,fichero);
fwrite(&buffer,1,4,fichero_salida);

/*FIN LECTURA DE LA CABECERA */



/*En total hay 800*533pixels de 24 bits por pixel por tanto bytes = (800*533*24)/8    */

num_bytes = (imagen.pixels_alto*imagen.pixels_ancho*imagen.bits_x_pixel)/8;


/*COMIENZO LECTURA DE LA IMAGEN EN SI
//reservo tama&#241;o para buffer_imag sabiendo el numero de bytes que tengo   */
buffer_imag = (int *)malloc(num_bytes*sizeof(int));
/*relleno buffer_imag con la imagen */
for(i=0;!feof(fichero);i++)
{
fread(&buffer,1,1,fichero);
buffer_imag[i]= buffer;
}
/*FIN LECTURA DE LA IMAGEN */
fclose(fichero);

/*AHORA VOY A ASIGNAR A CADA PIXEL SU CODIFICACION RGB
//En bmp hay 1 byte para b,otro xa g y otro xa r consecutivamente
//los guardo en la estructura correspondiente
//reservo para el array de rgb
//A la vez convierto a gris utilizando esta formula sacada de Matlab Xrgb = 0.2990*R + 0.5870*G + 0.1140*B;
//Ahora la imagen pasa de tener 3 bytes a tener 1byte=8bits=255 posibles colores=escala de grises
*/
buffer_rgb = (rgb*)malloc(num_bytes*sizeof(rgb));/*el buffer tiene tantas pos como bytes
//En blanco y negro hay 800*533 pixels y cada pixel tiene 1byte */
num_bytes_salida = imagen.pixels_alto*imagen.pixels_ancho;

for(i=0;i<num_bytes+1;i++)
{
/* buffer_rgb[i].b = buffer_imag[i];//componente b
// buffer_rgb[i].g = buffer_imag[i+1]; //componente g
// buffer_rgb[i].r = buffer_imag[i+2];//componente r
*/
if(i%3==0)
buffer_rgb[i/3].gris = (int)(0.299*buffer_imag[i+2]+0.587*buffer_imag[i+1]+0.114*buffer_imag[i]);
}

/*&#191; ERROR buffer_rgb[i] tiene 4 bits de longitud y con eso relleno 1byte. Perdida de info?

//escribo imagen salida */
for(i=0;i<num_bytes+1;i++)
{
fwrite(&buffer_rgb[i].gris,1,1,fichero_salida);

}
fclose(fichero_salida);

/*fin escritura imagen salida */
}