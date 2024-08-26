
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

void main(void)
{
int driver=DETECT,modo;
int x,i=1;

   /*font style */
    int font = 3;

    /*font direction */
    int direction = 0;

    /* font size */
    int font_size = 5;

initgraph(&driver,&modo,"c:\\TC20\\BIN");
cleardevice();

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


getch();
closegraph();
}