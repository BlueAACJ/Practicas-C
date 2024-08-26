#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<string.h>


void menu_lista(int px,int py,int qx, int inc);
void moververtical();
void moverhorizontal();

const int y[29]={62,76,90,104,118,132,146,160,174,188,
		 202,216,230,244,258,272,286,300,314,
		 328,342,356,370,384,398,248,262,276,290};

const int x[14]={100,115,130,145,160,175,190,205,220,235,290,305,320,335};

int (*actual)[4][4],(*next)[4][4];
int nowx,nowy;
int i,j;
int _color[25][10];
int _fill[25][10];
int juego[25][10];
int col,fi;
int tipo,nexttipo;
int termino,llego;
clock_t inicio,ahora,tim;
float dific;
char tecla;
int lineas,level;
unsigned long puntos;

void marco()
{setfillstyle(7,1);
 bar(55,55,97,450);
 bar(98,412,251,450);
 bar(252,55,400,450);
 setfillstyle(1,0);
 bar(280,80,370,100);
 bar(280,120,370,140);
 bar(280,160,370,200);
 bar(280,220,370,310);
 outtextxy(290,88,"Nivel");
 outtextxy(290,128,"Lineas");
 outtextxy(290,168,"Puntos");
 outtextxy(290,228,"Sigue");
}

void pres()
 {int c;
 i=0;
 cleardevice();

 do{delay(800);
    if(i==0)c=0;
    else if(i==1)c=3;
    else if(i==2)c=14;
    else if(i==3)c=1;
    else if(i==4)c=4;
    else if(i==5)c=12;
    else if(i==6)c=2;
    else if(i==7)c=6;
    else if(i==8)c=1;
    setcolor(c);
    settextstyle(0,0,7);
	outtextxy(100,100,"TETRIS");
	outtextxy(100,150,"2019 UNI");
    i++;
 }while(i<8);
 setcolor(15);
 settextstyle(0,0,1);
 outtextxy(10,370,"Presione ESC para salir");
 outtextxy(10,390,"Presione cualquier tecla para empezar");
 getch();
 getch();
 cleardevice();
}

void inicializa()
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
/*outtextxy(190,320,"presiona la tecla 'esc' para salir");
outtextxy(200,160,"ÛÛÛÛÛÛ° ÛÛÛÛÛ° ÛÛÛÛÛÛ° ÛÛÛÛ°   Û° ÛÛÛÛ°");
outtextxy(200,170,"  ÛÛ°   Û°       ÛÛ°   Û° Û°   Û° Û°");
outtextxy(200,180,"  ÛÛ°   ÛÛÛ°     ÛÛ°   ÛÛÛÛÛÛ° Û° ÛÛÛÛ°");
outtextxy(200,190,"  ÛÛ°   Û°       ÛÛ°   Û°   Û° Û°    Û°");
outtextxy(200,200,"  ÛÛ°   ÛÛÛÛÛ°   ÛÛ°   Û°   Û° Û° ÛÛÛÛ°");
*/
}

void uno(){
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
}


void tres()
{
clearviewport();
outtextxy(270,170,"CREDITOS");
outtextxy(50,210,"Creado por: Maria Tablada - 2019-1115u/Eduardo Paiz - 2018-0379u");
outtextxy(270,230,"grupo: 1M5-CO");
outtextxy(225,250,"materia: Lenguaje de programacion");
outtextxy(220,270,"profesor: Nelson Barrios");
getch();
}    /*px=10,py=130,qx=110,inc=30 */
void menu_lista(int px,int py,int qx, int inc)
{
int imp=inc/2;
box(0,0, getmaxx(), getmaxy(),1,GREEN);
box(px,py,qx,py+inc,1,LIGHTRED);
outtextxy(px+10,py+imp,"ANIMACION 1");
box(px,py+inc,qx,py+inc*2,1,LIGHTRED);
outtextxy(px+10,py+inc+imp,"ANIMACION 2");
box(px,py+inc*2,qx,py+inc*3,1,LIGHTRED);
outtextxy(px+10,py+inc*2+imp,"ANIMACION 3");
box(px,py+inc*3,qx,py+inc*4,1,LIGHTRED);
outtextxy(px+10,py+inc*3+imp,"SALIR");
}
void muevehorizontal()
{
char tecla;
int i=1,j=1;
int px=10,py=85,qx=110,inc=30,imp=inc/2,mostrar=1;
/* menu_lista(px,py,qx,inc); */
box(px,py,qx,py+inc,1,RED);
outtextxy(px+150+10,py+imp,"APLICACIONES");
box(px+150,py,qx+150,py+inc,1,LIGHTRED);
outtextxy(px+150+10,py+imp,"AYUDA");
box(px+300,py,qx+300,py+inc,1,LIGHTRED);
outtextxy(px+300+10,py+imp,"CREDITOS");
/*-------------------------------------*/
do{
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
outtextxy(px+150,py+imp,"AYUDA");
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
/*case '\x48':j--;break;*/ /*arriba*/
/*case '\x50':j++;break;*/   /*abajo*/
case '\x4b':j--;break;
case '\x4d':j++;break;
/*default: printf("tecla:%x\n",tecla); */
}
if(j>3)j=1;
if(j<1)j=3;
break;

case '\xD': switch(j)

	 {
		case 1:printf("aplicaciones");tecla='\x1B'/*uno()*/;break;
		case 2:printf("ayuda");/*dos()*/;break;
		case 3:printf("creditos");/*tres()*/;break;
		case 4:tecla='\x1B';break;
	}
	if(j ==1) menu_lista(px,py,qx,inc);
	break;

}

} while(tecla!='\x1B');

/*-------------------------------------*/
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
{ case '\x48':i--;break;
case '\x50':i++;break;
case '\x4b':printf("izquierda");break;
case '\x4d':printf("derecha");break;
default: printf("tecla:%x\n",tecla);
}
if(i>4)i=1;
if(i<1)i=4;
break;

case '\xD': switch(i)

	 {	case 1:printf("animacion 1");break;
	case 2:printf("animacion 2");break;
	case 3:printf("animacion 3");break;
	case 4:tecla='\x1B';break;

}
if (j!=4)menu_lista(px,py,qx,inc);
	break;
}

} while(tecla!='\x1B');
}

void main(){
inicializa();
muevehorizontal();
}