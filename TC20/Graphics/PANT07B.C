#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<string.h>


void menu_lista(int px,int py,int qx, int inc);
void moververtical();
int moverhorizontal(int px,int py,int qx,int inc);
void menuv(int px,int py, int qx,int inc);
void inicializa(void);
void creditos(void);
void ayuda(void);

void inicializa(void)
{
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,"c:\\tc\\bgi");
}

void box (int x1,int y1,int x2,int y2, int relleno,int color)
{
int poly [8];
poly [0]=x1;
poly [1]=y1;
poly [2]=x2;
poly [3]=y1;
poly [4]=x2;
poly [5]=y2;
poly [6]=x1;
poly [7]=y2;
setfillstyle (relleno,color);
fillpoly (4,poly);
line(1,80,630,80);
line(125,1,125,468);

outtextxy(190,320,"AQUI VA EL LOGO UNI ANIMADO la tecla 'esc' para salir");
}

void ayuda(void){
clearviewport();
outtextxy(250,70,"INSTRUCCIONES");
outtextxy(140,110,"presionar '>'para acomodar piezas a la derecha");
outtextxy(140,130,"presionar '<'para acomodar piezas a la izquierda");
outtextxy(140,150,"presionar 'v'para bajar las piezas mas rapido");
outtextxy(140,190,"presionar 'a'para rotar pieza hacia la izquierda");
outtextxy(140,210,"presionar 'q'para rotar pieza hacia la derecha");
outtextxy(200,170,"(las flechas del teclado)");
outtextxy(200,250,"presionar 'esc'para salir");
getch();
clearviewport();
}


void creditos(void)
{
clearviewport();
outtextxy(270,170,"CREDITOS");
outtextxy(50,210,"Creado por: Maria Tablada - 2019-1115u/Eduardo Paiz - 2018-0379u");
outtextxy(270,230,"grupo: 1M5-CO");
outtextxy(225,250,"materia: Lenguaje de programacion");
outtextxy(220,270,"profesor: Nelson Barrios");
getch();
clearviewport();
}
/*px=10,py=130,qx=110,inc=30 */

void menu_lista(int px,int py,int qx, int inc)
{
int imp=inc/2;
/*box(0,0, getmaxx(), getmaxy(),1,GREEN);*/

/*----------------*/
box(px,py,qx,py+inc,1,LIGHTRED);
outtextxy(px+10,py+imp,"ANIMACION 1");
box(px,py+inc,qx,py+inc*2,1,LIGHTRED);
outtextxy(px+10,py+inc+imp,"ANIMACION 2");
box(px,py+inc*2,qx,py+inc*3,1,LIGHTRED);
outtextxy(px+10,py+inc*2+imp,"ANIMACION 3");
box(px,py+inc*3,qx,py+inc*4,1,LIGHTRED);
outtextxy(px+10,py+inc*3+imp,"SALIR");
/*---------------*/

}


int muevehorizontal(int px,int py,int qx,int inc)
{
char tecla;
int j=1;
int imp=inc/2;
clearviewport();
box(px,py,qx,py+inc,1,RED);
outtextxy(px+10,py+imp,"APLICACIONES");
box(px+150,py,qx+150,py+inc,1,LIGHTRED);
outtextxy(px+150+10,py+imp,"AYUDA");
box(px+300,py,qx+300,py+inc,1,LIGHTRED);
outtextxy(px+300+10,py+imp,"CREDITOS");

/*-------------------------------------*/
do{
box(px,py,qx,py+inc,1,LIGHTRED);
outtextxy(px+10,py+imp,"APLICACIONES");
box(px+150,py,qx+150,py+inc,1,LIGHTRED);
outtextxy(px+150+10,py+imp,"AYUDA");
box(px+300,py,qx+300,py+inc,1,LIGHTRED);
outtextxy(px+300+10,py+imp,"CREDITOS");
switch(j)
{
case 1: box(px,py,qx,py+inc,1,RED);
outtextxy(px+10,py+imp,"APLICACIONES");
break;
case 2: box(px+150,py,qx+150,py+inc,1,RED);
outtextxy(px+150+10,py+imp,"AYUDA");
break;
case 3: box(px+300,py,qx+300,py+inc,1,RED);
outtextxy(px+300+10,py+imp,"CREDITOS");
break;
}
tecla=getch();
switch(j)
{
case 1: box(px,py,qx,py+inc,1,LIGHTRED);
outtextxy(px+10,py+imp,"APLICACIONES");
break;
case 2: box(px+150,py,qx+150,py+inc,1,LIGHTRED);
outtextxy(px+150+10,py+imp,"AYUDA");
break;
case 3: box(px+300,py,qx+300,py+inc,1,LIGHTRED);
outtextxy(px+300+10,py+imp,"CREDITOS");
break;
}
switch(tecla)
{
case '\x0': tecla=getch();
switch (tecla)
{
case '\x4b':j--;break;
case '\x4d':j++;break;
}
if(j>3)j=1;
if(j<1)j=3;
break;

case '\xD': switch(j)

	 {
		case 1:printf("aplicaciones");tecla='\x1B'/*uno()*/;break;
		case 2:printf("ayuda");ayuda();break;
		case 3:printf("creditos");creditos();break;
		case 4:tecla='\x1B';break;
	}
	if(j ==1) menu_lista(px,py+inc,qx,inc);
	break;

}

} while(tecla!='\x1B');

if(j==1) return 1; /* se eligio aplicacion y salimos del menu horizontal*/
return 0;
}


void menuv(int px,int py, int qx,int inc){
int i=1,j=1,tecla,imp=inc/2;
do{
	switch(i)
	{
	case 1: box(px,py,qx,py+inc,1,RED);
			outtextxy(px+10,py+imp,"ANIMACION 1");
			break;
	case 2: box(px,py+inc,qx,py+inc*2,1,RED);
			outtextxy(px+10,py+inc+imp,"ANIMACION 2");
			break;
	case 3: box(px,py+inc*2,qx,py+inc*3,1,RED);
			outtextxy(px+10,py+inc*2+imp,"ANIMACION 3");
			break;
	case 4: box(px,py+inc*3,qx,py+inc*4,1,RED);
			outtextxy(px+10,py+inc*3+imp,"SALIR");
			break;
	}
	tecla=getch();
	switch(i)
	{
	case 1: box(px,py,qx,py+inc,1,LIGHTRED);
			outtextxy(px+10,py+imp,"ANIMACION 1");
			break;
	case 2: box(px,py+inc,qx,py+inc*2,1,LIGHTRED);
			outtextxy(px+10,py+inc+imp,"ANIMACION 2");
			break;
	case 3: box(px,py+inc*2,qx,py+inc*3,1,LIGHTRED);
			outtextxy(px+10,py+inc*2+imp,"ANIMACION 3");
			break;
	case 4: box(px,py+inc*3,qx,py+inc*4,1,LIGHTRED);
			outtextxy(px+10,py+inc*3+imp,"SALIR");
			break;
	}
	switch(tecla)
	{
	case '\x0': tecla=getch();
				switch (tecla)
				{
				case '\x48':i--;break; /*arriba*/
				case '\x50':i++;break; /*abajo*/
				};
				if(i>4)i=1;
				if(i<1)i=4;
				break;

case '\xD':
			switch(i)
			{
			case 1:printf("animacion 1")/* animacion1()  */;break;
			case 2:printf("animacion 2")/* animacion2()  */;break;
			case 3:printf("animacion 3")/* animacion3()  */;break;
			case 4:tecla='\x1B';break;
			}
			if (j!=4) menu_lista(px,py,qx,inc);
			break;
}
} while(tecla!='\x1B');
}
/*------------------*/
void main(){
int tecla;
int px=10,py=85,qx=120,inc=30;
inicializa();
/* do{ */
   muevehorizontal(px,py,qx,inc);
   menuv(px,py+inc,qx,inc);
 /*  tecla=getch();
   if(tecla=='\xD')
		tecla='\x1B';
   printf("repetir o salir\n");
}while(tecla=='\x1B');*/

}
