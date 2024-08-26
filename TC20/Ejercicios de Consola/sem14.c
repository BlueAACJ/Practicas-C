/* UNIVERSIDAD NACIONAL DE INGENIERIA */
/* Proyecto formativo, Semana 14, Lenguajes de programacion */
/* Programa hecho por: Jose Ramirez 2020-0258U */

/* Importamos librerias. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* Cupos por categoria. */
#define N 20
/* Longitud del nombre+apellido. */
#define LEN 40

/* Prototipos de funciones. */
void Titulo(void);
int Menu1(void);
int Menu2(void);
void Agregar(char[N][LEN], int);
void Buscar(char[N][LEN], int);
void Borrar(char[N][LEN], int);
void Imprimir(char[N][LEN], int, int, int);/* Variable uso? 1: dentro de main 2: fuera de la main*/
void Modificar(char[N][LEN], int);

void main(){
    char compas[N][LEN];
    char trabajo[N][LEN];
    char familiares[N][LEN];
    char gimnasio[N][LEN];
    int i, op1, op2;
    int n_compas = 0;
    int n_trabajo = 0;
    int n_familiares = 0;
    int n_gimnasio = 0;

    
    while(1){
        op1 = Menu1();
        switch (op1)
        {
        case 1:
            do{
                
                op2 = Menu2();
                switch (op2)
                {
                    case 1:
                        n_compas += 1;
                        Agregar(compas, n_compas);
                        break;
                    case 2:
                        if(n_compas>0)Buscar(compas, n_compas);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                    case 3:
                        if(n_compas>0)Borrar(compas, n_compas);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        n_compas -= 1;
                        break;
                    case 4:
                        if(n_compas>0)Imprimir(compas, n_compas, 1, op1);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                    case 5:
                        if(n_compas>0)Modificar(compas, n_compas);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                }
            }while(op2 != 6);
            break;

        case 2:
            do{
                
                op2 = Menu2();
                switch (op2)
                {
                    case 1:
                        n_trabajo += 1;
                        Agregar(trabajo, n_trabajo);
                        break;
                    case 2:
                        if(n_trabajo>0)Buscar(trabajo, n_trabajo);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                    case 3:
                        if(n_trabajo>0)Borrar(trabajo, n_trabajo);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        n_trabajo -= 1;
                        break;
                    case 4:
                        if(n_trabajo>0)Imprimir(trabajo, n_trabajo, 1, op1);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                    case 5:
                        if(n_trabajo>0)Modificar(trabajo, n_trabajo);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                }
            }while(op2 != 6);
            
            break;

        case 3:
            do{
                
                op2 = Menu2();
                switch (op2)
                {
                    case 1:
                        n_familiares += 1;
                        Agregar(familiares, n_familiares);
                        break;
                    case 2:
                        if(n_familiares>0)Buscar(familiares, n_familiares);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                    case 3:
                        if(n_familiares>0)Borrar(familiares, n_familiares);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        n_familiares -= 1;
                        break;
                    case 4:
                        if(n_familiares>0)Imprimir(familiares, n_familiares, 1, op1);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                    case 5:
                        if(n_familiares>0)Modificar(familiares, n_familiares);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                }
            }while(op2 != 6);
            
            break;

        case 4:
            do{
                
                op2 = Menu2();
                switch (op2)
                {
                    case 1:
                        n_gimnasio += 1;
                        Agregar(gimnasio, n_gimnasio);
                        break;
                    case 2:
                        if(n_gimnasio>0)Buscar(gimnasio, n_gimnasio);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                    case 3:
                        if(n_gimnasio>0)Borrar(gimnasio, n_gimnasio);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        n_gimnasio -= 1;
                        break;
                    case 4:
                        if(n_gimnasio>0)Imprimir(gimnasio, n_gimnasio, 1, op1);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                    case 5:
                        if(n_gimnasio>0)Modificar(gimnasio, n_gimnasio);
                        else{
                            printf("No hay invitados en tu lista...\n");
                            getch();
                        }
                        break;
                }
            }while(op2 != 6);

            break;
        case 5:
            exit(1);
            break;
        }
    }
    
}

void Titulo(){
    clrscr();
    gotoxy(0,0);
    textcolor(MAGENTA);
    cprintf("%cFeliz cumplea%cos Vilma!\n", 173, 164);
    gotoxy(1,wherey());
    cprintf("Crea tu lista de invitados :)\n");
    textcolor(LIGHTGRAY);
    putchar('\n');
}

int Menu1(){
    int op;

    do{
        Titulo();
        printf("1. COMPA%cEROS.\n", 165);
        printf("2. TRABAJO.\n");
        printf("3. FAMILIARES.\n");
        printf("4. GIMNASIO.\n");
        printf("5. SALIR.\n");
        printf("\t Elija una opci%cn: ", 162);
        scanf("%d", &op);
        fflush(stdin);
    }while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6);

    return op;
}

int Menu2(){
    int op;

    do{
        Titulo();
        printf("1. Agregar.\n", 165);
        printf("2. Buscar.\n");
        printf("3. Borrar.\n");
        printf("4. Imprimir datos.\n");
        printf("5. Modificar.\n");
        printf("6. Regresar al men%c anterior.\n", 163);
        printf("\t Elija una opci%cn: ", 162);
        scanf("%d", &op);
        fflush(stdin);
    }while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6);

    return op;
}

void Agregar(char p[N][LEN], int n){
    Titulo();
    printf("Ingresa el nombre y apellido del invitado.\n");
    printf("-> ");
    gets(p[n-1]);
    fflush(stdin);

    printf("\n%s agregado a la lista de invitados.\n", p[n-1]);
    getch();
}

void Buscar(char p[N][LEN], int n){
    char nombre[50];
    int i, encontrado=0;

    Titulo();
    printf("Ingresa el nombre y apellido del invitado.\n");
    printf("-> ");
    gets(nombre);
    fflush(stdin);

    for (i = 0; i < n; i++)
    {
        if (strcmp(nombre, p[i]) == 0)
        {
            printf("\nInvitado encontrado.\n");
            printf("-> %s\n", p[i]);
            encontrado = 1;
        }
    }

    if(encontrado == 0)printf("No se encontro a %s.", nombre);
    getch();

}

void Borrar(char p[N][LEN], int n){
    int i;

    Imprimir(p, n, 2, 0);
    do{
        printf("\nNumero del invitado a borrar: ");
        scanf("%d", &i);
        fflush(stdin);
        if(i > n || i < 1)printf("Ingresa un n%cmero v%clido.\n", 163, 160);
    }while(i > n || i < 1);
    printf("%s borrado de la lista...\n", p[i-1]);
    
    for (i-1; i < n; i++)
    {
        if(i == n) strcpy(p[i], NULL);
        else strcpy(p[i-1], p[i]);
    }
    
    
    getch();
}

void Imprimir(char p[N][LEN], int n, int uso, int op){
    int i;
    char txt =NULL;
    FILE *pf;

    Titulo();
    printf("Imprimiendo invitados.\n");

    for (i = 0; i < n; i++)
    {
        if(strcmp(p[i], NULL) != 0)printf("%d- %s\n", i+1, p[i]);
    }

    getch();
    
    if(uso == 1){
        putchar('\n');
        printf("1- Crear una lista txt.\n");
        printf("2- Continuar.\n");
        do{
            printf("\t ?: ");
            scanf("%c", &txt);
        }while(txt != '1' && txt != '2');

        if(txt = '1'){
            switch (op)
            {
            case 1:
                pf = fopen("LISTACOMP.txt", "w");
                break;
            
            case 2:
                pf = fopen("LISTATRB.txt", "w");
                break;
            case 3:
                pf = fopen("LISTAFAM.txt", "w");
                break;
            case 4:
                pf = fopen("LISTAGIM.txt", "w");
                break;
            }

            for (i = 0; i < n; i++)
            {
                if(strcmp(p[i], NULL) != 0){
                    fputs(p[i], pf);
                    fputs("\n", pf);
                }
            }

            fclose(pf);
        }
        
    }
    
}

void Modificar(char p[N][LEN], int n){
    char nuevo_nombre[50];
    int n_invitado;

    Imprimir(p, n, 2, 0);
    do{
        printf("\nNumero del invitado a modificar: ");
        scanf("%d", &n_invitado);
        fflush(stdin);
        if(n_invitado > n || n_invitado < 1)printf("Ingresa un n%cmero v%clido.\n", 163, 160);
    }while(n_invitado > n || n_invitado < 1);
    printf("Ingrese el nuevo nombre y apellido del invitado.\n");
    printf("-> ");
    gets(nuevo_nombre);
    fflush(stdin);
    
    printf("Nombre de %s modificado a ", p[n_invitado-1]);
    strcpy(p[n_invitado-1], nuevo_nombre);
    printf("%s\n", p[n_invitado-1]);

    getch();

}


