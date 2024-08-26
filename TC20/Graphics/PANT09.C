#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<string.h>
#include<math.h>
/*------anim1---*/
# define MAS 43
# define MENOS 45
# define SALIR 27
/*-----anim2---*/
#define N getmaxy()
#define radio 40


void menu_lista(int px,int py,int qx, int inc);
void moververtical();
int moverhorizontal(int px,int py,int qx,int inc);
void menuv(int px,int py, int qx,int inc);
void inicializa(void);
void creditos(void);
void ayuda(void);
void logo();
void animacion1(void);
void animacion2(void);
void animacion3(void);
void animacion4(void);
void espera(void);
void avion(void);
void logo(void);

void espera(void){
/*
#include<stdio.h>
#include<conio.h>
#include <graphics.h>
int main()
{
  int gd = DETECT, gm, c , x = 100, y = 50;

  initgraph(&gd, &gm, "C:\\TC20\\BIN");
*/
int c,x=100,y=50;

  for (c = 0; c < 5; c++)
  {
	setlinestyle(c, 0, 0);

    line(x, y, x+200, y);
    y = y + 25;
  }

  getch();

/*  closegraph();
  return 0;
}
*/
}

void animacion1(void){

/*Codigo de efecto de hule para el cuadrado*/
 /* char z; */
int x1=310,x2=330,y1=230,y2=250;
/* setbkcolor(5); */
cleardevice();
setlinestyle(3,0,3);
rectangle(x1,y1,x2,y2);
do{
switch(getch())
        {

    /*Se estirara segun la tecla*/

          case MAS:
                 cleardevice();
                 x1-=10;
		 x2+=10;
	         y1-=10;
	         y2+=10;
                 setcolor(YELLOW);
                 rectangle (x1,y1,x2,y2);
                 break;

	  case MENOS:
                 cleardevice();
                 x1+=10;
		 x2-=10;
	         y1+=10;
	         y2-=10;
                 setcolor(YELLOW);
                 rectangle (x1,y1,x2,y2);
                 break;

        }
	}while(getch()!=SALIR);
clearviewport();
setcolor(WHITE);
settextstyle(0,0,0);
}
void animacion2(void){
/* animacion ruedita */

   /* xc,yc coordenadas del centro */
   int i,xc,yc;

   /* rx1,ry1,seg variables usadas para la cruz */
   int rx1,ry1,seg;
   /* inicializando la variable */
   yc=getmaxy()/2-radio;
   i=0;

   /* el ciclo se detiene cuando hay flecha abajo o i>=N */
   /* kbhit verifica si se presiona una tecla */
   while(i<N&&!kbhit())
   {

   /* incrementando xc para mover la rueda */
   xc=i;
   delay(50);

   /* limpia la pantalla previa */
   clearviewport();

   /* linea representando el camino */
   line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

   /* dibujando la rueda */
   circle(xc,yc,radio);

   /* la cruz de la rueda se muestra alternativamente */
   if(i%2==0)
   {
     line(xc,yc+radio,xc,yc-radio);
     line(xc-radio,yc,xc+radio,yc);
   }
   else
   {
     rx1=xc-(radio/sqrt(2));
     ry1=yc-(radio/sqrt(2));
     seg=sqrt(2)*radio;
     line(rx1,ry1,rx1+seg,ry1+seg);
     line(rx1,ry1+seg,rx1+seg,ry1);
   }

   /* incrementar i */
   i+=3;
  }
  getch();

  clearviewport();

setcolor(WHITE);
setlinestyle(0,0,1);
settextstyle(0,0,0);
} /*-----*/


void animacion3(void){
int angulo = 0;
double x, y;
  clearviewport();

setcolor(WHITE);
setlinestyle(0,0,1);
settextstyle(0,0,0);

line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
/* genera la onda */
for(x = 0; x < getmaxx(); x+=3) {

  /* calcula el valor de y segun x */
  y = 50*sin(angulo*3.141/180);
  y = getmaxy()/2 - y;

  /* colorea un pixel en la posicion dada */
  putpixel(x, y, 15);
  delay(100);

  /* incrementa el angulo */
  angulo+=5;
}

 getch();
 clearviewport();
setcolor(WHITE);
settextstyle(0,0,0);
}
void animacion4(void){
	clearviewport();
	setcolor(WHITE);
	setlinestyle(0,0,1);
	settextstyle(0,0,0);
	avion();
}
void avion(void){
  /*Variables a utilizar*/

  int i,j,n,s,f/*v, k */;
  int /* color,  maxcolor,  x ,y, */ z, /* star,end, */ h;
  char L[80];

 /*Inicializar modo grafico*/

for(j=1;j<=2;j++)
{
 h=17;     /*duracion del ciclo for*/
 z=10;      /*damos movimiento al avion*/
 n=5;       /*dimenciones del avion*/
 s=0;       /*trayectoria en diagonal del avion*/

 for(i=1; i<=h*6; i++)
 {
 z=z+5;
 f=((1.5+1.5)*i); /*variacion de velocidad del avion*/

 delay(f);  /*controla la velocidad del avion*/

/*  v=515-z; */   /*velocidad del avion*/
 cleardevice();
setcolor(BLUE);
setfillstyle(1,RED);      /*Colorea el centro del avion*/
fillellipse(n*15+z,n*17+s,35,2.8);
/*dibujo del avion*/
setcolor(RED);
line(n*2+z,n*17+s,n*4+z,n*16.5+s);
line(n*4+z,n*16.5+s,n*3+z,n*14+s);
line(n*3+z,n*14+s,n*5+z,n*14+s);
line(n*5+z,n*14+s,n*6+z,n*16.5+s);
line(n*6+z,n*16.5+s,n*12+z,n*16+s);
line(n*12+z,n*16+s,n*8+z,n*5+s);
line(n*8+z,n*5+s,n*10+z,n*5+s);
line(n*10+z,n*5+s,n*16+z,n*15.8+s);
line(n*16+z,n*15.8+s,n*20+z,n*16+s);
arc(n*20+z,n*17+s,-90,90,n*1.5);
line(n*20+z,n*18+s,n*16+z,n*18.2+s);
line(n*16+z,n*18.2+s,n*10+z,n*29+s);
line(n*10+z,n*29+s,n*8+z,n*29+s);
line(n*8+z,n*29+s,n*12+z,n*18+s);
line(n*12+z,n*18+s,n*6+z,n*17.5+s);
line(n*6+z,n*17.5+s,n*5+z,n*20+s);
line(n*5+z,n*20+s,n*3+z,n*20+s);
line(n*3+z,n*20+s,n*4+z,n*17.5+s);
line(n*4+z,n*17.5+s,n*2+z,n*17+s);
window(5,15,40,25);

/*Nombre del estudiante.*/

setcolor(25);

sprintf(L,"Grupo 2M5-CO");
outtextxy(140,205,L);

sprintf(L,"Maria Felix Herrera Tablada Carnet 2019-1145U.");
outtextxy(140,180,L);


	}

 }


getch();
clearviewport();
}

void logo(void){
int font = 3,i=1 ;
/*font direction */
int direction = 0;
/* font size */
	int font_size = 5;
cleardevice();
/* color=getbkcolor(); */
setcolor(LIGHTGRAY);
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(1,1,639,479);
setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
bar(200,64,221,166);
bar(200,150,315,177);
bar(288,170,315,101);
bar(249,138,279,65);
bar(252,79,351,65);
bar(266,72,351,89);
bar(336,66,363,177);
bar(335,69,362,65);
bar(338,161,398,177);
bar(339,154,398,167);
bar(380,162,405,104);
bar(388,151,405,177);
bar(378,65,407,95);
/* for setting text style*/
settextstyle(font, direction, font_size);
/* for printing text in graphics window*/
setcolor(BLUE);
outtextxy(50,208, "GEOMETRIA_COMPUTACIONAL");
/*font style */
 font = 3;
/*font direction */
direction = 0;
/* font size */
font_size = 1;
settextstyle(font, direction, font_size);
outtextxy(95,292,"INTEGRANTES");
outtextxy(55,312,"MARIA FELIX HERRERA TABLADA -- CARNET:2019-1145U");
outtextxy(55,332,"EDUARDO PAIZ -- CARNET:");
outtextxy(55,352, "YASSER CAJINA --CARNET:");
while(i<=5){
font_size=5;
settextstyle(font, direction, font_size);
setcolor(BLUE);
outtextxy(50,208, "GEOMETRIA_COMPUTACIONAL");
sleep(1);
setcolor(5);
outtextxy(50,208, "GEOMETRIA_COMPUTACIONAL");
sleep(1);
i++;
}
}

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
espera();
/*outtextxy(190,320,"AQUI VA EL LOGO UNI ANIMADO la tecla 'esc' para salir"); */
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
outtextxy(270,230,	"grupo: 2M5-CO");
outtextxy(225,250,"materia: GEOMETRIA COMPUTACIONAL");
outtextxy(220,270,"profesor: PROF. RHENE BERROTERAN");
getch();
clearviewport();
}
/*px=10,py=130,qx=110,inc=30 */

void menu_lista(int px,int py,int qx, int inc)
{
int imp=inc/2;
/*box(0,0, getmaxx(), getmaxy(),1,GREEN);*/
/*----------------*/
setcolor(WHITE);
setlinestyle(0,0,1);
settextstyle(0,0,0);
/*-----------------------*/
box(px,py-30,qx,py-30+inc,1,LIGHTRED);
outtextxy(px+10,py-30+imp,"APLICACIONES");
box(px+150,py-30,qx+150,py-30+inc,1,LIGHTRED);
outtextxy(px+150+10,py-30+imp,"AYUDA");
box(px+300,py-30,qx+300,py-30+inc,1,LIGHTRED);
outtextxy(px+300+10,py-30+imp,"CREDITOS");

/*-----------------------*/
box(px,py,qx,py+inc,1,LIGHTRED);
outtextxy(px+10,py+imp,"ANIMACION 1");
box(px,py+inc,qx,py+inc*2,1,LIGHTRED);
outtextxy(px+10,py+inc+imp,"ANIMACION 2");
box(px,py+inc*2,qx,py+inc*3,1,LIGHTRED);
outtextxy(px+10,py+inc*2+imp,"ANIMACION 3");
box(px,py+inc*3,qx,py+inc*4,1,LIGHTRED);
outtextxy(px+10,py+inc*3+imp,"ANIMACION 4");
/*---------------*/
}


int muevehorizontal(int px,int py,int qx,int inc)
{
char tecla;
int j=1;
int imp=inc/2;

clearviewport();
setcolor(WHITE);
setlinestyle(0,0,1);
settextstyle(0,0,0);

box(px,py,qx,py+inc,1,LIGHTRED);
outtextxy(px+10,py+imp,"APLICACIONES");
box(px+150,py,qx+150,py+inc,1,LIGHTRED);
outtextxy(px+150+10,py+imp,"AYUDA");
box(px+300,py,qx+300,py+inc,1,LIGHTRED);
outtextxy(px+300+10,py+imp,"CREDITOS");

/*-------------------------------------*/
do{
setcolor(WHITE);
setlinestyle(0,0,1);
settextstyle(0,0,0);
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
if(tecla=='\x1B')
	   return tecla;

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

		case 1:tecla='\x1B'/*se eligio aplicaciones, hay que salir de esta funcion */;break;
		case 2:ayuda();break; /* se eligio ayuda */
		case 3:creditos();break;  /* ver creditos */
		case 4:tecla='\x1B';break;
	}
	if(j ==1)  menu_lista(px,py+inc,qx,inc);
	break;

}

} while(tecla!='\x1B');

if(j==1) return 1; /* se eligio aplicacion y salimos del menu horizontal*/
return tecla;
}


void menuv(int px,int py, int qx,int inc){
int i=1,j=1,tecla,imp=inc/2;
do{
	setcolor(WHITE);
	setlinestyle(0,0,1);
	settextstyle(0,0,0);

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
			outtextxy(px+10,py+inc*3+imp,"ANIMACION 4");
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
			outtextxy(px+10,py+inc*3+imp,"ANIMACION 4");
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
			case 1:animacion1() ;break;
			case 2:animacion2() ;break;
			case 3:animacion3() ;break;
			case 4:animacion4() ;break;
			}
			if (j!=4) menu_lista(px,py,qx,inc);
			break;
}
} while(tecla!='\x1B');
}
/*------------------*/
void main(){
int tecla;
int px=10,py=85,qx=120,inc=30; /* coordenadas para los menus */
inicializa();
logo();
/*  sleep(10); */
 do{
   clearviewport();
   tecla=muevehorizontal(px,py,qx,inc);
   if(tecla!=27){  /* codigo de esc es 27 en entero */
		menuv(px,py+inc,qx,inc);
		clearviewport();
		/* tecla=getch();*/
   }
   if(tecla==27)
		tecla='\x1B';/* 27 en hexadecimal es \x1B */
   /*printf("PRESIONE ESC PARA SALIR\n"); */
}while(tecla!='\x1B');

}
