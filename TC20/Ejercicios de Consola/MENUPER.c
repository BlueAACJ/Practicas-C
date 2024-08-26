/*Programa que almacena la informacion de algún usuario 
La informacion que el programa deberá almacenar será su Nombre, Edad, y Profesion
Los datos estarán en la estructura. Se hará un menu Agregar, Buscar y Borrar
Toda  informacion estará en un archivo de texto
Programa elaborado por: Brandon Daniel González Morales 2020-1045U*/

/*Primeramente definimos nuestras librerias a usar*/
#include <stdio.h>	
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/*Definimos las teclas a usar para el direccionamiento en el menu*/

#define flecha 26
#define arriba 72
#define abajo  80
#define enter 13
#define bloque 219

/*Definimos como estructura los datos a ingresar al metodo persona*/

typedef struct Detalles		
{
    char nombre[20];
    char profesion[20];
    char edad[20];
} persona;

/*Definimos como estructura los datos de las personas con el fin de manipular de forma mas rapida el regitro de los datos */

typedef struct Datos
{
    int ID;
    persona personas[15];
} registro;

/*Los metodos a usar para el resgistro de las personas*/ 

void menu(void);
void ocultarcursor(void);
void agregar(void);
void buscar(void);
void eliminar(void);
void cargarDatos(void);
void guardarDatos(void);

/*Definicion de variables*/

int i, j;

registro Datos;

int main()
{
    cargarDatos();
    menu();
    return 0;
}

/*En el metodo guardar datos le decimos que abra un fichero con la extencion txt para guardar los datos de las personas ingresadas por el usuario */

void guardarDatos(void)
{   
    FILE *fichero;
    fichero = fopen("Datos.txt","w");
    fwrite(&Datos,sizeof(Datos),1,fichero);
    fclose(fichero);
}

/* En este metodo nos mostrara los datos de las personas ingresadas si no se ha ingresado ninguna persona nos retorna el valor de cero pero si hay datos nos cargara los datos ingresados*/

void cargarDatos(void)
{
    FILE *fichero;
    fichero = fopen("Datos.txt","r");
    if(fichero==NULL)
    {
        Datos.ID = 0;
        return;
    }
    fread(&Datos,sizeof(Datos),1,fichero);
    fclose(fichero);
}

/*En nuestro metodo menu se nos mostrara las opciones que tiene el usuario ya sea para agregar, buscar, eliminar un usuario o bien salir del programa*/

void menu(void)
{
    char * commandos[4] = {"Agregar","Buscar","Eliminar","Salir"};
    int opcion = 0;
    char tecla;
    system("cls");
    textcolor(LIGHTGREEN);
    gotoxy(35,5);
    cprintf("Menu Principal");

    do /*Inicio del do*/
    {
        for(i = 0; i < 4; i++)	/*Ciclo for que controla las opciones del usuario*/
        {
            if(i == opcion)	/*Validamos la opcion*/
                textcolor(LIGHTCYAN);
            else 
                textcolor(WHITE);

            gotoxy(25,9 + i*2);
            cprintf("%c %s", i==opcion?flecha:NULL, commandos[i]);
        }

        ocultarcursor();
        do
            tecla = getch();
        while (tecla != arriba && tecla != abajo && tecla != enter);
	/*En el do While validamos que se capturen los datos hasta que el usuario ingrese un valor distinto a las teclas predefinidas anteriormente*/
        if(tecla == arriba)
            opcion = opcion==0 ? 3 : opcion - 1;
        
        else if (tecla == abajo)
            opcion = opcion==3 ? 0 : opcion + 1;
        else if (tecla == enter)
        {
            switch(opcion)
            {
                case 0:
                    agregar();
                    break;
                case 1:
                    buscar();
                    break;
                case 2:
                    eliminar();
                    break;
                default:
                    exit(0);
            }
            system("cls");
            textcolor(LIGHTGREEN);
            gotoxy(35,5);
            cprintf("Menu Principal");
        }
    }
    while(1);
}

/*En el menu agregar solicitamos al usuario el nombre, la edad y la profesion de la persona*/

void agregar(void)
{
    char * commandos[5] = {"Nombre:", "Edad:", "Profesion:", "Agregar", "Volver"};
    int opcion = 0;
    char tecla;
    persona temporal;
    system("cls");
    textcolor(LIGHTGREEN);
    gotoxy(35,5);
    cprintf("Agregar nuevo expediente");

    do
    {
        for(i = 0; i < 5; i++)
        {
            if(i == opcion)
                textcolor(LIGHTCYAN);
            else 
                textcolor(WHITE);

            gotoxy(25,9 + i*2);
            cprintf("%c %s", i==opcion?flecha:NULL, commandos[i]);
        }

        ocultarcursor();
        do
            tecla = getch();
        while (tecla != arriba && tecla != abajo && tecla != enter);
        textcolor(WHITE);

        if(tecla == arriba)
            opcion = opcion==0 ? 4 : opcion - 1;
        
        else if (tecla == abajo)
            opcion = opcion==4 ? 0 : opcion + 1;
        else if (tecla == enter)
            switch(opcion)
            {
                case 0:
                    gotoxy(35,9);
                    printf("                              ");
                    gotoxy(35,9);
                    scanf("%s",temporal.nombre);
                    gotoxy(35,9);
                    cprintf("%s",temporal.nombre);
                    break;
                case 1:
                    gotoxy(33,11);
                    printf("                              ");
                    gotoxy(33,11);
                    scanf("%s",temporal.edad);
                    gotoxy(33,11);
                    cprintf("%s",temporal.edad);
                    break;
                case 2:
                    gotoxy(38,13);
                    printf("                              ");
                    gotoxy(38,13);
                    scanf("%s",temporal.profesion);
                    gotoxy(38,13);
                    cprintf("%s",temporal.profesion);
                    break;
                case 3:
                    if(strcmp(temporal.profesion[0],"")==0 || strcmp(temporal.edad[0],"")==0 || strcmp(temporal.nombre[0],"")==0)
                        break;
                    Datos.personas[Datos.ID] = temporal;
                    Datos.ID++;
                    guardarDatos();
                    cargarDatos();
                default:
                    return;
            }

    }
    while(1);
}

/*En el metodo buscar solicitamos al usuario el nombre de la persona a buscar*/

void buscar(void)
{
    char * commandos[5] = {"Nombre:", "Buscar", "Volver"};
    int opcion = 0;
    char tecla;
    persona temporal;
    system("cls");
    textcolor(LIGHTGREEN);
    gotoxy(35,5);
    cprintf("Buscar expediente");

    do
    {
        for(i = 0; i < 3; i++)
        {
            if(i == opcion)
                textcolor(LIGHTCYAN);
            else 
                textcolor(WHITE);

            gotoxy(25,9 + i*2);
            cprintf("%c %s", i==opcion?flecha:NULL, commandos[i]);
        }

        ocultarcursor();
        do
            tecla = getch();
        while (tecla != arriba && tecla != abajo && tecla != enter);

        if(tecla == arriba)
            opcion = opcion==0 ? 2 : opcion - 1;
        
        else if (tecla == abajo)
            opcion = opcion==2 ? 0 : opcion + 1;
        else if (tecla == enter)
            switch(opcion)
            {
                case 0:
                    gotoxy(35,9);
                    printf("                              ");
                    gotoxy(35,9);
                    scanf("%s",temporal.nombre);
                    break;
                case 1:
                    j=0;
                    for (i = 0; i < Datos.ID ; i++)
                    {
                        if(strcmp(temporal.nombre,Datos.personas[i].nombre) == 0)
                        {
                            textcolor(LIGHTMAGENTA);
                            gotoxy(10,14 + j);
                            cprintf("%d- Nombre: %s | Edad: %s | Profesion: %s",j+1,Datos.personas[i].nombre,Datos.personas[i].edad,Datos.personas[i].profesion);
                            j++;
                            if(j==10)
                                break;
                        }
                    }
                    if(j<1)
                    {
                        textcolor(RED);
                        gotoxy(10,15);
                        cprintf("No se ha encontrado un expediente");
                        ocultarcursor();
                        getch();
                        gotoxy(10,15);
                        cprintf("                                 ");
                    }
                    break;
                default:
                    return;
            }

    }
    while(1);
}

/*En el metodo eliminar solicitamos al usuario el nombre de la persona a eliminar mediante la busqueda y despues eliminamos a la persona*/

void eliminar(void)
{
    char * commandos[5] = {"Nombre:", "Buscar y Eliminar", "Volver"};
    int opcion = 0;
    int eliminarID;
    int posiblesExpediedntes[10];
    char tecla;
    persona temporal;
    system("cls");
    textcolor(LIGHTGREEN);
    gotoxy(35,5);
    cprintf("Eliminar expediente");

    do
    {
        for(i = 0; i < 3; i++)
        {
            if(i == opcion)
                textcolor(LIGHTCYAN);
            else 
                textcolor(WHITE);

            gotoxy(25,7 + i*2);
            cprintf("%c %s", i==opcion?flecha:NULL, commandos[i]);
        }

        ocultarcursor();
        do
            tecla = getch();
        while (tecla != arriba && tecla != abajo && tecla != enter);

        if(tecla == arriba)
            opcion = opcion==0 ? 2 : opcion - 1;
        
        else if (tecla == abajo)
            opcion = opcion==2 ? 0 : opcion + 1;
        else if (tecla == enter)
            switch(opcion)
            {
                case 0:
                    gotoxy(35,7);
                    printf("                              ");
                    gotoxy(35,7);
                    scanf("%s",temporal.nombre);
                    break;
                case 1:
                    j=0;
                    for (i = 0; i < Datos.ID ; i++)
                    {
                        if(strcmp(temporal.nombre,Datos.personas[i].nombre) == 0)
                        {
                            textcolor(LIGHTMAGENTA);
                            gotoxy(10,15 + j);
                            cprintf("%d- Nombre: %s | Edad: %s | Profesion: %s",j+1,Datos.personas[i].nombre,Datos.personas[i].edad,Datos.personas[i].profesion);
                            posiblesExpediedntes[j] = i;
                            j++;
                            if(j>10)
                                break;
                        }
                    }
                    if(j<1)
                    {
                        textcolor(RED);
                        gotoxy(10,13);
                        cprintf("No se ha encontrado un expediente");
                        ocultarcursor();
                        getch();
                        gotoxy(10,13);
                        cprintf("                                 ");
                        break;
                    }
                    if(j>1)
                    {
                        textcolor(WHITE);
                        gotoxy(10,13);
                        cprintf("Indique cual de los expedientes desea eliminar");
                        gotoxy(58,13);
                        scanf("%d",eliminarID);
                        gotoxy(10,14);
                        cprintf("Eliminando...");
                        ocultarcursor();
                        getch();
                    }
                    else if(j==1)
                    {
                        textcolor(RED);
                        gotoxy(10,13);
                        cprintf("Presione cualquier tecla para eliminar");
                        ocultarcursor();
                        getch();
                        eliminarID = 1;
                    }
                    for(i = posiblesExpediedntes[eliminarID - 1]; i < Datos.ID-1; i++)
                    {
                        Datos.personas[i] = Datos.personas[i+1];
                    }
                    Datos.ID--;
                    guardarDatos();
                default:
                    return;
            }

    }
    while(1);
}

/*El metodo ocultar cursor es para evitar el parpadeo del cursor al ingresar o escribir datos*/

void ocultarcursor(void)
{
    textcolor(BLACK);
    gotoxy(78,25);
    cprintf("%c",bloque);
    gotoxy(78,25);
}

