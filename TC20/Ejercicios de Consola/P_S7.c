/* 	Autor: 	John Alexander Torres Ortiz 
	Carnet:	2020 - 0350U */
	
/*	Descripcion: El programa simula un base de datos interna de nombres para su procesamiento.
	Puede guardar o sobreescribir esta informacion en un archivo, así como buscar contenido dentro de él.
	Carece de poder eliminar o modificar un elemento especifico dentro del archivo generado.*/
	
/*	IMPORTANTE: Este codigo ha sido desarrollado completamente en DevC++, desconozco su comportamiento
	en otros entornos, sin embargo puedo asegurar su correcta compilacion con mingw64*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

/* Las siguientes constantes tienen el objetivo de mejorar la referencia */
enum categories	{MATE =1, JOB, FAM, GYM, EXIT, MODIFICAR, BORRAR};
enum colors		{blue =1, green, cyan, red, purple, yellow };

typedef struct {
    char name[15];
    char last_name[15];
    int  category;		/* Este campo tiene propósitos de encapsulamiento */
}Persona;

int  Menu       (void);				
int  Submenu    (int category);		
void Imprimir   (Persona *invitado, int category, int  n);
void Agregar 	(Persona *invitado, int category, int *n);
void Borrar     (Persona *invitado, int category, int *n);
int  Buscar 	(Persona *invitado, int category, int  n, int *posicion, int parametro);
void cprint (int color, const char *string,...);

/* ------------------------------------ FUNCION PRINCIPAL ----------------------------------*/
void main (void) {
    int n = 0, categoria;	/* n = Numero de invitados*/
    Persona *invitado = malloc (sizeof(Persona));	/* Una sola estructura dinámica con un espacio por defecto */
    system("color F0");
	categoria = Menu();		/* Obtiene la categoria a filtrar desde el menu */
	do {
	    if (categoria == EXIT) {
	    	cprint(green, "\n\n\n\tGracias por utilizar este programa");
	    	getch();	exit(0);
		}
		
		switch (Submenu(categoria)) {
				case 1:	Agregar		(invitado, categoria, &n);			 		break;
				case 2:	Buscar 		(invitado, categoria,  n, 0, 0);	 		break;
				case 3: Borrar 		(invitado, categoria, &n); 			 		break;
				case 4: Imprimir	(invitado, categoria,  n);			 		break;
				case 5: Buscar		(invitado, categoria,  n, 0, MODIFICAR);	break;
				case 6: categoria = Menu(); break;
		}
	}while (1);
}

/* 	Imprime texto a color. Trabaja sobre fondo blanco por defecto.
	Fuentes:
		http://prog-lenguajec.blogspot.com/p/colores-en-lenguaje-c.html
		http://c.conclase.net/librerias/?ansifun=vprintf#inicio			*/
void cprint (int color, const char *string,...) {
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (240+color));
	va_list format;
	va_start(format, string);
	vprintf	(string, format);
	va_end	(format);
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 240);
}

/*	------------------  Control de memoria -----------------*/
void Reasignar_Memoria (Persona *invitado, int n) {
	invitado = (Persona *) realloc (invitado, sizeof(Persona) * n);
    if (invitado == NULL) {
    	puts("No se pudo reasignar memoria");
    	getch(); exit(1);
	}
}

/*	------------------  Adicion de miembros por el usuario -----------------*/
void Agregar (Persona *invitado, int category, int *n) {
	system("cls");
	char salir[15];		/* Cadena auxiliar para que el usuario finalice la introduccion */
    printf("\t\tIngreso de datos:\n\n** Digite "); cprint(red,"\"salir\" ");
	printf("(min%csculas) en el nombre para finalizar **\n\n",163);
    do {
    	strcpy (salir, "\0");	/* Por defecto la cadena esta vacia */
	    printf("\n\tNombre:\t\t"); 
		fflush(stdin);		scanf("%15[^\n]s", salir);
	    	if (strcmp(salir,"salir") == 0){
	    		break;
			}else if (strcmp(salir, "\0") == 0) {	/* Si el usuario lo deja en blanco (Al presionar enter) */
				cprint(red,"\n\t*No debe dejar este campo vac%co*",161);		continue;	/* Si "true", omite lo posterior y entra nuevamente en el ciclo */
			}
		Reasignar_Memoria (invitado, *(n)+1);		/* Reasigna la memoria para un miembro adicional*/
		strcpy((invitado+(*n))->name, salir);		/* Copia el nombre en su campo */
	    strcpy (salir, "\0");						/* Vacia  la cadena para comprobar el apellido */
	    do {
		    printf("\tApellido:\t");
			fflush(stdin);		scanf("%15[^\n]s", salir);
			if (strcmp(salir, "\0") == 0)
				cprint(red,"\n\t*No debe dejar este campo vac%co*\n",161);
		}while (strcmp(salir, "\0") == 0);
		strcpy((invitado+(*n))->last_name, salir);	/* Copia el apellido en su campo*/
	    switch (category) {							/* Le asigna la categoria actual*/
	        case MATE: 		invitado[*(n)].category = MATE;     break;
	        case JOB: 		invitado[*(n)].category = JOB;      break;
	        case FAM:		invitado[*(n)].category = FAM; 		break;
	        case GYM: 		invitado[*(n)].category = GYM;      break;
	    }
		*(n) += 1; /* Aumenta en uno la cantidad de miembros */
	}while (1);
}
/*	------------------  MENU -----------------*/
int Menu (void) {
	system("cls");
    int ans;	
        printf("\n\n\t\tCrear Categor%ca de Invitados\n\n",161);
        printf("\n\n\t1. Compa%ceros", 164);
        printf("\n\n\t2. Trabajo");
        printf("\n\n\t3. Familiares");
        printf("\n\n\t4. Gimnasio");
        printf("\n\n\t5. Salir");
    do {
        ans = getch();
    }while (ans!= '1' && ans!='2' && ans!='3' && ans!='4' && ans!='5');
    /*	Ya que la tecla se captura en ASCII, es necesario aplicarle un ajuste 
		Este metodo ya se habia empleado para la calculadora de SN, y aplica solo para numeros*/
    return (ans-48);
}
/*	------------------  SUB MENU -----------------*/
int Submenu (int category) {
	system("cls");
    int ans;
	printf("\n\n\t\tCategor%ca ", 161);
	switch(category) {
		case MATE: 		cprint(blue,"Compa%ceros\n\n",164); break;
		case JOB: 		cprint(yellow,"Trabajo\n\n"); 		break;
		case FAM: 		cprint(purple,"Familiares\n\n"); 	break;
		case GYM: 		cprint(green,"Gimnasio\n\n"); 		break;
	}
        printf("\n\n\t1. Agregar");
        printf("\n\n\t2. Buscar");
        printf("\n\n\t3. Borrar");
        printf("\n\n\t4. Imprimir datos");
        printf("\n\n\t5. Modificar");
        printf("\n\n\t6. Regresar al men%c anterior", 163);
    do {
        ans = getch();
    }while (ans!= '1' && ans!='2' && ans!='3' && ans!='4' && ans!='5' && ans!='6');
    return (ans - 48);
}
/*	----------------- Control de archivos de texto --------------------- */
/*	"mode" hace referencia al método de acceso. La funcion Buscar puede usarlo para albergar el nombre*/
/*	"nombre" es el nombre que se le agregara al archivo, es recibido como puntero ya que se empleará
	al momento de abrirlo por la funcion Imprimir y adicionalmente al mostrarlo en modo lectura */
/*	retorna 1 si la operacion se realizó con exito y 0 en caso contrario */
int Control_listas (char *nombre, Persona *invitado, int category, int n, char *mode) {
	FILE *archivo;
	int i, k;
	char linea[40];	/* Cadena auxiliar para el control de entrada y salida de texto */
	switch (category) { /* Nombres diferentes para cada categoria */
		case MATE: 		strcpy(nombre, "Lista_compañeros.txt");	break;
		case JOB: 		strcpy(nombre, "Lista_familiares.txt");	break;
		case FAM: 		strcpy(nombre, "Lista_trabajo.txt");	break;
		case GYM: 		strcpy(nombre, "Lista_gimnasio.txt");	break;
	}
	/* Si es algun metodo de acceso valido */
	if (!strcmp(mode, "a") || !strcmp(mode, "w") || (!strcmp(mode, "r")))
			archivo = fopen(nombre, mode);
	else	archivo = fopen(nombre, "r");	/* Modo de lectura para la solicitud de la funcion Buscar */
	if (archivo == NULL) {
		/* Si se abre en modo lectura, o en el modo solicitado por la busqueda*/
		if (!strcmp(mode, "r") || (strcmp(mode, "a")!=0 && strcmp(mode, "w")!=0 && strcmp(mode, "r")!=0)) {
			cprint(red,"\n\n\tNo se pudo abrir el archivo");
		}else {
			cprint(red,"\n\n\tNo se pudo crear el archivo");
		}
		getch();	return 0;
	}
	if (!strcmp(mode, "a") || !strcmp(mode, "w")) {	/* Operaciones segun el modo de escritura o sobreescritura */
		for (i = 0; i < n; i++) {
	    	if (invitado[i].category == category) {
	    			sprintf(linea, "%s %s", invitado[i].name, invitado[i].last_name);
	    			for (k = 0; k <= strlen(linea); k++) {	/* Control de salida de caracteres especiales */
	    				switch(linea[k]) {
	    					case -127:	linea[k] =  -4;	break;	/* ü */
	    					case -126:	linea[k] = 233;	break;	/* é */
	    					case -96:	linea[k] = 225;	break;	/* á */
	    					case -95:	linea[k] = 237;	break;	/* í */
	    					case -94:	linea[k] = 243;	break;	/* ó */
	    					case -93:	linea[k] = 250;	break;	/* ú */
	    					case -92:	linea[k] = -15; break;	/* ñ */
						}
					}
			        fprintf(archivo, "%s\n", linea);
			}
	    }
	    printf("\n\nGuardado Completo!");
    	fclose(archivo);
    	getch();	return 1;
	}else {	/* Operacion en modo de lectura */
			system("cls");
			printf("Archivo: ");
			if (category == MATE) {/* Ajuste de visualizacion, ya que tiene un caracter especial (ñ) */
					cprint(cyan,"Lista_compa%ceros.txt\n\n\n",164);
			}else	cprint(cyan,"%s\n\n\n", nombre);
//		}
		while(fgets(linea, 40, archivo) != NULL) {
			for (i = 0; i < strlen(linea) - 1; i++) {	/* Control de entrada de caracteres especiales*/
				switch(linea[i]) {
					case -31:	linea[i] = 160;	break;	/* á */
					case -23:	linea[i] = 130;	break;	/* é */
					case -19:	linea[i] = 161;	break;	/* í */
					case -15:	linea[i] = 164;	break;	/* ñ */
					case -13:	linea[i] = 162;	break;	/* ó */
					case -6:	linea[i] = 163;	break;	/* ú */
					case -4:	linea[i] = 129;	break;	/* ü */
				}
			}
			if (!strcmp(mode, "a") || !strcmp(mode, "w") || !strcmp(mode, "r")) {
				puts(linea);
			}else if (!strncmp(mode,linea, strlen(mode))) {
				cprint(green,"Encontrado:\t%s", linea);
				fclose(archivo);
				getch(); return 1;
			}
		}
		if (!strcmp(mode, "a") || !strcmp(mode, "w") || !strcmp(mode, "r")) {
			cprint(green,"\n\nPulse cualquier tecla para volver a la lista actual");
			fclose(archivo);
			getch();	return 1;
		}else {
			fclose(archivo);
			return 3;
		}
	}
}

/*	------------------  Impresion de lista en pantalla -----------------*/
void Imprimir_Pantalla (Persona *invitado, int category, int n) {
	int i, k = 1;
	system("cls");
	printf("\n\n");
    for (i = 0; i < n; i++) {
    	if (invitado[i].category == category) {
		        printf("\t\t%d.\t%s %s\n", k++, invitado[i].name, invitado[i].last_name);
		}
    }
}
/*	-----------  Detecta si la categoria actual esta vacia -------------*/
int Vacio (Persona *invitado, int category, int n) {
	int i, inv_en_categoria = 0;
	for (i = 0; i < n; i++) {
		if (invitado[i].category == category)
			inv_en_categoria += 1;
	}
	if (inv_en_categoria == 0)
		return 1;
	else
		return 0;
}
/*	------------------  MODO DE IMPRESION DE DATOS -----------------*/
void Imprimir (Persona *invitado, int category, int n) {
	int ans = 0;
	char nombre_lista[30];	/* Unicamente existe en esta funcion para ser abierto por el comando system */
	if ( !Vacio (invitado, category, n) ) {		/* Si no esta vacio */
		do {
			Imprimir_Pantalla (invitado, category, n);
			cprint(blue,"\n\tPulse G para guardar esta lista en nuevo documento de texto");
		    printf("\n\nSi ya ten%ca una lista:\n", 161);
			cprint(purple,"\n\tPulse V para ver su contenido",162);
			cprint(yellow,"\n\tPulse X para anexarle el contenido de esta lista (Si no existe, se crear%c)",160);
			cprint(green,"\n\nPulse cualquier otra tecla para volver al men%c anterior",163);
		    ans = toupper(getch());	/* Captura las teclas en mayuscula */
		    
		    switch (ans) {
		    	case 'G':
		    		if (Control_listas(nombre_lista, invitado, category, n, "w")) {		/* Modo de creacion o sobreescritura*/
		    			system("cls");
		    			cprint(green,"Pulse A para abrir el archivo");
		    			cprint(purple,"\nPulse U para abrir su ubicaci%cn",162);
		    			printf("\n\nPulse cualquier otra tecla para volver al men%c anterior",163);
		    			ans = toupper(getch());
		    			
		    			if (ans == 'A') {
		    				system("cls");
							cprint(red,"Cierre el archivo para continuar");
		    				system(nombre_lista);
		    			}else if (ans == 'U') {
							system("start .");
						}
					}
					break;
				case 'V':
					Control_listas(nombre_lista, invitado, category, n, "r");	break;	/* Modo de lectura */
				case 'X':
					Control_listas(nombre_lista, invitado, category, n, "a");	break;	/* Modo de creacion o escritura*/
			}
		}while (ans == 'V' || ans == 'X');
	}else {
		system("cls");
		cprint(red, "\n\tLa lista actual est%c vac%ca",160,161);		Sleep(1000);
		printf("\n\n\n\tIntentando visualizar una lista existente..."); Sleep(1500);
		Control_listas(nombre_lista, invitado, category, n, "r");
	}
}
/*	--------------------------  MODO DE BUSQUEDA ------------------------*/
/*	Mediante las constantes recibe en "parametro" BORRAR, MODIFICAR
	o 0 para unicamente buscar */
/*	Recibe un puntero que sera modificado de acuerdo a la "posicion" donde
	la busqueda finalice con exito*/
/*	Retorna 1 si la operacion se realizo con exito, 0 en caso contrario
	y 2 al ser llamada en modo BORRAR para continuar con el bucle externo*/
int Buscar (Persona *invitado, int category, int  n, int *posicion, int parametro) {
	int i, reintentar;
	/* 	Cadenas auxiliare para realizar la busqueda */
	/* 	Aqui nombre_lista tiene dos propositos:
		1. Como auxiliar para albergar el nombre y apellido y realizar una comparacion completa
		2. Como cadena base para solicitar una busqueda al Control de listas*/
	char name[30];
	char nombre_lista[30];	
	if (Vacio(invitado, category, n) && parametro==MODIFICAR) {
		cprint(red,"\n\n\n\n\n\t\tAgregue al menos un invitado en esta categor%ca", 161);
		getch(); return 0;
	}
	do {
		if (parametro == BORRAR) {
			Imprimir_Pantalla (invitado, category, n);
			printf("\n\nEscriba el nombre del invitado que desea eliminar:\t");
		}else if (parametro == MODIFICAR) {
			Imprimir_Pantalla (invitado, category, n);
			printf("\n\nEscriba el nombre del invitado que desea modificar:\t");
		}else {
			system("cls");
			printf("Escriba el nombre del invitado que desea buscar:\t");
		}
		fflush(stdin); scanf("%30[^\n]s", name);
		for (i = 0; i < n; i++)
		{			/* Si los nombres y categoria coinciden */
			sprintf(nombre_lista, "%s %s", invitado[i].name, invitado[i].last_name);
			if (!strncmp(name, nombre_lista, strlen(name)) && invitado[i].category == category)
			{
				if (parametro == BORRAR) {
					cprint(yellow,"\n\n%cEst%c seguro que desea eliminar a %s %s? S/N", 168, 160, invitado[i].name, invitado[i].last_name);
					do {
						reintentar = toupper(getch());
					}while (reintentar != 'S' && reintentar != 'N');
					
					if (reintentar == 'N') {
						printf("\n\n%cVolver al men%c? S/N ", 168, 163, invitado[i].name, invitado[i].last_name);
						do {
							reintentar = toupper(getch());
						}while (reintentar != 'S' && reintentar != 'N');
						if (reintentar == 'S')	return 0;
						else					return 2;
					}else {
						printf("\tBorrado!");
						*(posicion) = i;
						getch();	return 1;
					}
				}else if (parametro == MODIFICAR) {
					cprint(cyan, "\n\tNota: Si deja uno o ambos campos en blanco, no se aplicar%cn cambios",160);
					printf("\n\nNuevo nombre:\t");
					fflush(stdin);	scanf("%15[^\n]s", invitado[i].name);
					printf("\nNuevo apellido:\t");
					fflush(stdin);	scanf("%15[^\n]s", invitado[i].last_name);
					printf("\n\tHecho!");
					getch();	return 1;
				}else {
					cprint(green,"\n\nEncontrado: %s %s", invitado[i].name, invitado[i].last_name);
					getch(); 	return 1;
				}
			}
		}
		if ( i == n) {	/* Habiendo buscado en todo o la lista esta vacia*/
			if (parametro == 0) {
				cprint(red,"\n\n\tNo encontrado");								Sleep(1000);
				printf("\n\n\tIntentando buscar en una lista existente...");	Sleep(1500);
				reintentar = Control_listas(nombre_lista, invitado, category, n, name);
				if (reintentar == 3) {
					printf("\n\nSin resultados\n");
				}else {
					return 1;
				}
			}
			cprint(red,"\n\nEl nombre ingresado no existe o no corresponde en la lista actual", 130);
			printf("\nPor limitaciones, la b%csqueda es sensible a may%csculas y min%csculas", 163, 163, 163);
			printf("\nTampoco se admite la %c, acentos, vocales con di%cresis, etc",164, 130);
			if (parametro==0)
				printf("\n\nTambi%cn puede verificar la lista en imprimir datos",130);
			printf("\n\n\t1.\tVolver a intentarlo\n\t2.\tVolver al men%c anterior",163);
			do {
				reintentar = getch();
			}while (reintentar!= '1' && reintentar!='2');
			if (reintentar == '2' && parametro == BORRAR) {
				return 0;
			}else if (reintentar == '1' && parametro == BORRAR) {
				return 2;
			}
		}
	}while(reintentar == '1');
	return 0;
}
/*	------------------  Borrado de miembros por el usuario -----------------*/
void Borrar (Persona *invitado, int category, int *n) {
	if ( !Vacio(invitado, category, *n)) {	/* Si no esta vacio */
		int i, posicion, busqueda;
		do {
			busqueda = Buscar (invitado, category, *(n), &posicion, BORRAR);
			system("cls");
		}while (busqueda == 2);
		
		/* Si la operacion de busqueda finaliza con verdadero para proceder al borrado*/
		if (busqueda == 1) {
		    *(n) -= 1;	/* Reduce en uno la cantidad de miembros */
		    /* Mueve todos los campos posteriores a la posicion marcada por "busqueda" */
		    for (i = posicion; i < *(n); i++) {  
		        strcpy( (invitado + i)->name, (invitado + (i+1))->name);    			
		        strcpy( (invitado + i)->last_name, (invitado + (i+1))->last_name);
		        invitado[i].category = invitado[i+1].category;
		    }
		    if (*(n) > 0) {	/* Verifica que se mantenga un espacio por defecto*/
				Reasignar_Memoria (invitado, *(n));	/* Reasigna la memoria de acuerdo a -1 miembros*/
			}
		}
	}else { /* Si la lista esta vacia */
		cprint(red,"\n\n\n\n\n\t\tAgregue al menos un invitado en esta categor%ca", 161);	getch();
	}
}
