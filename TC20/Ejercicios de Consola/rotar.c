#include <stdio.h>
#include <stdlib.h>
/*#include <stdint.h>*/
#include <dos.h>
#include <string.h>



void grey(char*string,FILE*fIn,int size,unsigned char header[]){
    unsigned char buffer[size][3];
	FILE *fOut = fopen(strcat(string,"s1.bmp"),"w+");
    fwrite(header,sizeof(unsigned char),54,fOut);
    int i,j,y;

    for(i=0;i<size;i++)
    {

        buffer[i][2]=getc(fIn);                                 //blue
        buffer[i][1]=getc(fIn);                                 //green
        buffer[i][0]=getc(fIn);                                 //red

        y=(buffer[i][0]*0.3) + (buffer[i][1]*0.59)  + (buffer[i][2]*0.11);          //conversion formula of rgb to gray

        for (j=0;j<3;j++) putc(y,fOut);
    }
    fclose(fOut);
    printf("La imagen se ha formado con exito\n");
}

void copy(char*string,FILE*fIn,int size,unsigned char header[]){
    FILE *fOut = fopen(strcat(string,"_copy.bmp"),"w+");
    fwrite(header,sizeof(unsigned char),54,fOut);
    int i,j;

    for(i=0;i<size;i++)
    {
        for (j=0;j<3;j++) putc(getc(fIn),fOut);
    }
    fclose(fOut);
    printf("La imagen se ha copiado con exito\n");

}

void rotate(char*string,FILE*fIn,unsigned char header[]){
    FILE *fOut = fopen(strcat(string,"_rotate.bmp"),"w+");
    int height = *(int*)&header[18];
    int width = *(int*)&header[22];
    int i,j,choice;
    unsigned char buffer[width][height][3];
    unsigned char out_buffer[width][height][3];



d	for(i=0;i<width;i++)
    {
        for (j=0;j<height;j++){
            buffer[i][j][2]=getc(fIn);                                  //blue
            buffer[i][j][1]=getc(fIn);                                  //green
            buffer[i][j][0]=getc(fIn);                                  //red
        }
    }

    printf("Escriba una opcion\n\t1 : rotar imagen hacia la derecha\n\t2 : rotar imagen hacia la izquierda\n\t3 : rotar imagen 180 grados\n\tCualquier otra tecla : salir del programa\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        for(i=0;i<width;i++)                                //Right
        {
            for(j=0;j<height;j++)
            {
                out_buffer[j][height-1-i][2]=buffer[i][j][2];
                out_buffer[j][height-1-i][1]=buffer[i][j][1];
                out_buffer[j][height-1-i][0]=buffer[i][j][0];
            }
        }

        *(unsigned char*)&header[18]=*(unsigned char*) &width;
        *(unsigned char*)&header[22]=*(unsigned char*) &height;
        break;
    case 2:
        for(i=0;i<width;i++)                                //Left
        {
            for(j=0;j<height;j++)
            {
                out_buffer[j][i][2]=buffer[i][j][2];
                out_buffer[j][i][1]=buffer[i][j][1];
                out_buffer[j][i][0]=buffer[i][j][0];
            }
        }

        header[18]= width;
        header[22]= height;
        break;
    case 3: 
        for(i=0;i<width;i++)                    //Flip          
        {
            for(j=0;j<height;j++)
            {
                out_buffer[width-i][j][2]=buffer[i][j][2];
                out_buffer[width-i][j][1]=buffer[i][j][1];
                out_buffer[width-i][j][0]=buffer[i][j][0];
            }
        }
        break;
    default:
        exit(0);
        break;
    }


    fwrite(header,sizeof(unsigned char),54,fOut);

    for(i=0;i<width;i++)                                
    {
        for(j=0;j<height;j++)
        {
            putc(out_buffer[i][j][2],fOut);
            putc(out_buffer[i][j][1],fOut);
            putc(out_buffer[i][j][0],fOut);
        }
    }

    fclose(fOut);
    printf("La imagen se ha rotado con exito\n");
}


int main(){
    int i,choice;
    char string[50];
    unsigned char header[54];

    printf("Escriba el nombre del archivo a modificar y presione Enter\n");
    scanf("%s",string);
    FILE *fIn = fopen(strcat(string,".bmp"),"r");
    if(fIn==NULL) {
        printf("El archivo no se pudo abrir.\n");
        exit(1);
    }
    for(i=0;i<54;i++)   header[i] = getc(fIn);  

    int height = *(int*)&header[18];
    int width = *(int*)&header[22];
    int size = height*width;

    printf("Escriba una opcion\n\t1 : rotar imagen\n\t2 : copiar imagen\n\t3 : aplicar filtro de grises\n\tCualquier otra tecla : salir del programa\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        rotate(string,fIn,header);
        break;
    case 2:
        copy(string,fIn,size,header);
        break;
    case 3: 
        grey(string,fIn,size,header);
        break;
    default:
        return 0;
        break;
    }

    fclose(fIn);
    return 0;
}