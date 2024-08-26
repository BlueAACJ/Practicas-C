#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define CLAVE "1234"
#define USUARIO "FRAN"

#define LONGITUD 80

int main(){
	
	char usuario[LONGITUD + 1], clave[LONGITUD + 1];
	int o = 1, intento = 0, ingreso = 0;
	typedef char cadena[30];
	int menu;
	int arrayLength[1];
    cadena ncgp1[50][2], ncgp2[50][2];
    int x,i,j,ele,act;
    char opc;

	system("cls");
	gotoxy(25,10);printf("Bienvenido Prof. Francisco\n\n\n");
	gotoxy(25,15);system("pause");
	
	do {
	system("cls");
	printf("\n INICIO DE SESION %c\n",219);
	
	while (o<20){
	printf("%c",254);
	o++;
	}

	printf("\n\n\n USUARIO: ");
	gets(usuario);
	printf("\n\n CLAVE: ");
	gets(clave);
	
	if(strcmp(usuario, USUARIO) == 0 && strcmp(clave, CLAVE) == 0){
		system("cls");gotoxy(3,4);printf("HA iniciado sesion correctamente\n\n\n");system("pause");
		
		ingreso = 1;
	}else{
		system("cls");gotoxy(3,4);printf("\n Usuario y clave incorrectos\n\n");
		intento++;system("pause");
	}
	
	}while (intento < 3 && ingreso == 0); 
		
	if(ingreso == 1){
		system("cls");
		printf("\n\t\t\t\t Sistema de notas \n\n");
		
		do
    {
    	system("cls");
    	printf("1. Ingresar alumno y nota\n");
    	printf("2. Mostrar alumnos en sistema\n");
    	printf("3. Actualizar alumos\n");
    	printf("4. Salir\n");
    	printf("\n --->  ");scanf("%i", &menu);
    	system("cls");
    	
    	switch(menu)
    	{
    		case 1:
    			printf("1. Grupo 1\n");
    			printf("2. Grupo 2\n");
    			printf("\n--->  ");scanf("%d", &ele);
    			system("cls");
    			if(ele==1)
    			{
    				printf("Digite la cantidad de alumnos a ingresar del grupo 1 \n");
	    			scanf("%d", &i);
	    			for (x=0;x<=i-1;x++)
					{
						system("cls");
						printf("Ingrese el nombre del alumno %c%d\n", 35, x+1);
						scanf("%s", &ncgp1[x][0]);
						printf("Ingrese la nota del alumno %c%d\n", 35, x+1);
						system("pause");
						scanf("%s", &ncgp1[x][1]);
						system("cls");
						printf("\nAñadido\n");
						system("pause");
	    			}
	    			getch();
				}
				if(ele==2)
    			{
    				printf("Digite la cantidad de alumnos a ingresar del grupo 2 \n");
	    			scanf("%d", &j);
	   				for (x=0;x<=j-1;x++)
					{
						system("cls");
						printf("Ingrese el nombre del alumno %c%d\n", 35, x+1);
						scanf("%s", &ncgp2[x][0]);
						system("pause");
						printf("Ingrese la nota del alumno %c%d\n", 35, x+1);
						scanf("%s", &ncgp2[x][1]);
						system("cls");
						printf("\nAñadido\n");
						system("pause");
	    			}
				}
				
    			ele=0;
    			break;
    		case 2:
    			
    			printf("Grupo 1\n");
    			for (x=0;x<i;x++)
				{
    			    printf("%d. %s\t",x+1,ncgp1[x][0]);
					printf("%s\t",ncgp1[x][1]);
					printf("\n");
    			}
    			printf("Grupo 2\n");
    			for (x=0;x<j;x++)
				{
    			    printf("%d. %s\t",x+1, ncgp2[x][0]);
					printf("%s\t",ncgp2[x][1]);
					printf("\n");
    			}
    			system("pause");
    			break;
    		case 3:
    			printf("Elija el grupo a actualizar\n");
				printf("1. Grupo 1\n");
    			printf("2. Grupo 2\n");
    			scanf("%d", &ele);
    			if(ele==1)
    			{
					for (x=0;x<i;x++)
					{ system("cls");
    				    printf("%d%s\t",x+1,ncgp1[x][0]);
						printf("%s\t",ncgp1[x][1]);
						printf("\n");
						system("cls");
    				}	
    				printf("Seleccione el alumno que desea actualizar\n");
					scanf("%d", &act);
					system("cls");
					printf("Seleccione la nueva nota de: %s\n", ncgp1[act-1][0]);
					scanf("%s", &ncgp1[act-1][1]);
					system("pause");
							
				}
				if(ele==2)
    			{
    				for (x=0;x<j;x++)
					{
						system("cls");
    				    printf("%d%s\t",x+1,ncgp2[x][0]);
						printf("%s\t",ncgp2[x][1]);
						printf("\n");
						system("cls");
    				}	
    				printf("Seleccione el alumno que desea actualizar\n");
					scanf("%d", &act);
					system("cls");
					printf("Seleccione la nueva nota de: %s\n", ncgp2[act-1][0]);
					scanf("%s", &ncgp2[act-1][1]);
					system("pause");
				}
    			
    		case 4:
    			system("cls");
    			printf("Desea salir?s/n\n");
    			scanf("%c", &opc);
    			break;
		}
	}while(opc != 115 && opc != 83);
    

    getch();
		
		
	}	
	
	return 0;
}
