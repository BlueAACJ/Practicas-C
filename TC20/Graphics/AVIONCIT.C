#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<math.h>
#include <time.h>


int main(void)
{

  /*Variables a utilizar*/

  int i,j,k,n,s,f,v;
  int color,maxcolor, x ,y,z,star,end,h;
  char L[80];

 /*Inicializar modo grafico*/

  int driver=DETECT,modo;
  initgraph(&driver,&modo,"c:\\TC20\\BIN");



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

 v=515-z;    /*velocidad del avion*/
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
closegraph();

clrscr();
}
