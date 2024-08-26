																								/***********************************************************************/
/* TRABAJO DE GEOMETRIA COMPUTACIONAL    */
/* AUTOR: LUIS ENRIQUE TORU¥O ALTAMIRANO */
/* FECHA: 18 DE ABRIL DE 2001            */
/***********************************************************************/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

#define NEGRO 0
#define BLANCO 15
#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
#define ENTER 13
#define TAM_CURS 10
#define COL_CURS 12
#define ESC 27
#define S 115
#define N 110
#define X 0
#define Y 1
#define poner_cursor(x,y)  dib_cursor(x,y);
#define borrar_cursor(x,y) dib_cursor(x,y);
typedef enum{FALSE,TRUE} bool;
typedef int tPointi [2];

/* ---------------------------FUNCIONES-------------------------------*/

bool LeftOn(tPointi a, tPointi b, tPointi c);
long Area2(tPointi a , tPointi b, tPointi c);
void Ptointerno(tPointi m1[50], tPointi pto, int nptos );

void dib_polilinea(void);
	/*Dibuja las lineas que forman el poligono*/

void dib_cursor(int x,int y);
	/*Dibuja y borra el cursor que se ira moviendo de una posicion a otra*/

int escoger_punto(int *,int *);
	/*Devuelve el valor que se escogio por el usuario al dar ENTER en */
	/*algun punto													*/

int leer(void);
	/*Lee el codigo de la tecla que fue presionada, y la devuelve */

void look(void);  /*Dibuja unos marcos */
void menu(void);

void xor_pixel(int x,int y);
	 /*funcion encargada de realizar un conjunto de operaciones, para que */
	 /*se pueda dibujar el cursor no destructivo */

int pasoacel=8;
	/*Variable global, que indica el paso de la aceleracion */


/***************************FUNCION PRINCIPAL******************************/

void statusbar(void)
{
  setcolor(RED);
  rectangle(30,400, getmaxx()-30,450);
  rectangle(35,405,getmaxx()-35, 445);
 }

 int cursorWrapX(int *posx)
 {
 int xmin,xmax,ymin,ymax;
 xmin=45;
 xmax=getmaxx()-45;

 if (posx<=xmin )  return(1);
 if (posx>=xmax )  return(2);
 return(FALSE);

  }

int cursorWrapY(int *posy)
{
int ymin, ymax;
ymin=50;
ymax=360;

if ( posy<=ymin)   return(1);
if ( posy>=ymax)   return(2);

return(FALSE);

}


void main(void)
{
 int x,y,a=DETECT,b;
 initgraph(&a,&b,"c:\\tc20\\bin");

 look();
 x=getmaxx()/2;
 y=getmaxy()/2;
 menu();
 statusbar();
 dib_polilinea();

 if (leer()==ESC )
   	restorecrtmode();
 else main();

 }

void look(void)
{
rectangle(30,40,getmaxx()-30, 380 );

}

int escoger_punto(int *x,int *y)
{
 int c,ct_arriba=0,ct_abajo=0,ct_derecha=0,ct_izquierda=0;
 bool flag=1;
 poner_cursor(*x,*y);

 for(;;)
 {
	 switch(c=leer())
	 {
	 case ARRIBA:
    if ( cursorWrapY(*y)!= 1 )   /*Si llego al limite superior (1) dejar de hacer*/
    {
    borrar_cursor(*x,*y);
    *y+=(++ct_arriba<pasoacel)?-1:-pasoacel;
		ct_abajo=ct_derecha=ct_izquierda=0;
		poner_cursor(*x,*y);
    }
		break;
	 case ABAJO:
    if ( cursorWrapY(*y)!=2 )
    {
		borrar_cursor(*x,*y);
		*y+=(++ct_abajo<pasoacel)?1:pasoacel;
		poner_cursor(*x,*y);
    }
		break;
	 case IZQUIERDA:
    if (cursorWrapX(*x)!=1 )
    {
		borrar_cursor(*x,*y);
		*x+=(++ct_izquierda<pasoacel)?-1:-pasoacel;
		ct_abajo=ct_derecha=ct_arriba=0;
		poner_cursor(*x,*y);
    }
	  break;
	 case DERECHA:
    if (cursorWrapX(*x)!=2)
    {
		borrar_cursor(*x,*y);
		*x+=(++ct_derecha<pasoacel)?1:pasoacel;
		ct_abajo=ct_arriba=ct_izquierda=0;
		poner_cursor(*x,*y);
    }
		break;

   case ESC: return(c);
             break;
   case S:  exit(1);
            break;
   case N:  main();


	 default:borrar_cursor(*x,*y);
	 return(c);
	 }
	 }
	 }

int leer(void)
{
 int tecla;

  while((tecla=getch())!=0)
   if(tecla==ENTER || tecla==ESC || tecla==S || tecla==N )
	          return(tecla);
	 return(getch());
}

void dib_cursor(int x,int y)       /* Funcion que dibuja el cursor */
{
 int i;
  for(i=0;i<TAM_CURS;i++)
  {
   xor_pixel(x-i,y);
   xor_pixel(x+i,y);
   xor_pixel(x,y-i);
   xor_pixel(x,y+i);
  }
  xor_pixel(x,y);

  }

void xor_pixel(int x,int y)      /* Funcion que dibuja los puntos del cursor*/
{
 putpixel(x,y,COL_CURS^getpixel(x,y) );
}

void dib_polilinea(void)  		/* Funcion que dibuja linea */
{
 int x1,x2,y1,y2,car, i=0,j=0 ,escape=0;
 tPointi polices[20], ladrones[20], punto;

 setcolor(BLUE);
 x2=getmaxx()/2;
 y2=getmaxy()/2;
 car=escoger_punto(&x2,&y2);

 while(car==ENTER && escape<=2)
 {
     if(escape==0)
        {  polices[i][0]=x2;
           polices[i][1]=y2;
           circle(x2,y2,2);
           i++;
        }
	/* if(escape==1)  */
       {   setcolor(RED);
           ladrones[j][0]=x2;
           ladrones[j][1]=y2;
           outtextxy(x2,y2,"X");
           j++;
        }
     if(escape==2)
     {     setcolor(10);
           outtextxy(x2,y2,"0");
           punto[0]=x2;
           punto[1]=y2;
           Ptointerno(polices, punto, i);
           setcolor(RED);
           Ptointerno(ladrones,punto, j);
           borrar_cursor(x2,y2);
           escape++;
     }
        car=escoger_punto(&x2,&y2);
        if (car==ESC)
           {
           escape++;
           borrar_cursor(x2,y2);
           x2=getmaxx()/2;
           y2=getmaxy()/2;
           car=escoger_punto(&x2,&y2);
           }

   }  /*while*/

}

void Ptointerno(tPointi m1[50], tPointi pto, int nptos )
{
   int i,j,k;
   static int flag=1;

   for(i=0; i<nptos-2; i++)
        for(j=i+1; j<nptos-1; j++)
             for(k=j+1; k<nptos; k++)
              if(   LeftOn(m1[i], m1[j], pto) &&
                    LeftOn(m1[j], m1[k], pto) &&
                    LeftOn(m1[k], m1[i], pto)  )
                  {
                  if (flag) {
                  setlinestyle(DASHED_LINE,1, NORM_WIDTH);
                  line(m1[i][0], m1[i][1], m1[j][0], m1[j][1]);
                  line(m1[j][0], m1[j][1], m1[k][0], m1[k][1]);
                  line(m1[k][0], m1[k][1], m1[i][0], m1[i][1]);
                  outtextxy(100,100,"Esta dentro");
                  }
                  flag=0;
                  }
}

bool LeftOn(tPointi a, tPointi b, tPointi c)
{
if ( Area2(a,b,c)>=0 )
   return(TRUE);
return(FALSE);
}

long Area2(tPointi a , tPointi b, tPointi c)
{ long area;
  area=(b[0]-a[0])*(c[1]-a[1]);
  area-=(b[1]-a[1])*(c[0]-a[0]);
  return(area);
}

void menu(void)
{
setcolor(BLUE);
setfillstyle(SOLID_FILL,LIGHTGRAY);

bar(0,0,640,20);
setlinestyle(0,0,20);
rectangle(1,0,120,20);

setcolor(RED);
outtextxy(10,8,"N");
setcolor(BLUE);
outtextxy(10+textwidth("N"),8,"uevo Juego");

rectangle(120,0,230,20);
setcolor(RED);
outtextxy(150,8,"S");
setcolor(BLUE);
outtextxy(150+textwidth("S"),8,"alir");

}

