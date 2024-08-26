#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include<dos.h>
#include<stdlib.h>

# define MAS 43
# define MENOS 45
# define SALIR 27

/*Codigo de efecto de hule para el cuadrado*/
void GD()
   {

     char z;
int x1=310,x2=330,y1=230,y2=250;
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
 cleardevice();
 closegraph();
}


void main (void)
{

    int driver = DETECT,modo;
    initgraph(&driver,&modo,"c:\\tc20\\bin");

	setbkcolor(5);
	GD();

}
