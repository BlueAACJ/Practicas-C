#include <graphics.h>
#include <process.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <mouse.h>

 void iniciar(void);
 void figura(void);
 void cerrar(void);
 void pantalla_presen(void);
 void pantalla_iniciar(void);
 void pantalla_iniciar2(void);
 void cuadricula(void);

 int color(void);
 int raton(int, int, int, int, int);

 void main(void)
 {
	iniciar();
	cerrar();
 }

/***************************************************************************/
 void iniciar(void)
 {
  int adapta, modo;
	detectgraph(&adapta,&modo);
	initgraph(&adapta,&modo,"");
	pantalla_presen();
 }

 void cerrar(void)
 {
   closegraph();
   restorecrtmode();
 }

/*SUGERENCIA

generen una funcion que dibuje los botones, es decir una funcion que genere
n botones recibiendo las coordenadas y el mensaje que tenga.

Una sola funcion que generen las pantallas.
*/

/***************************************************************************/
 void pantalla_presen(void)
 {
	int eleccion;
	cleardevice();
	rectangle(500,420,600,460);
	setfillstyle(9,7);
	floodfill(540,430,WHITE);
	settextstyle(3,0,1);
	setcolor(15);
	outtextxy(525,430,"INICIAR");
	setfillstyle(1,BLUE);
	floodfill(10,10,WHITE);
    figura();

	eleccion=raton(500,420,600,460,1);
	if(eleccion==1)
	   pantalla_iniciar();
 }
 /*************************************************************************/
 void figura(void)
 {
  setcolor(15);
  line(470,24,396,206);line(396,206,475,206);line(396,206,390,198);
  line(396,206,396,233);line(396,233,335,375);line(396,233,466,386);
  line(390,198,390,24);line(390,198,376,188);line(386,196,310,196);
  line(376,188,313,52);line(376,188,326,161);line(326,161,313,161);
  line(313,161,313,24);line(313,161,300,178);line(300,178,300,189);
  line(300,189,310,196);line(310,196,316,219);line(316,219,316,235);
  line(316,235,323,248);line(323,248,333,298);line(333,298,335,386);
  line(392,203,372,215);line(372,215,316,219);line(372,215,323,248);
  line(382,209,333,298);line(300,189,250,189);line(285,189,285,223);
  line(285,223,316,223);line(285,223,262,240);line(262,240,335,335);
  line(320,244,266,244);line(258,180,258,240);line(252,240,262,240);
  line(260,240,260,386);line(252,240,180,386);line(252,240,238,231);
  line(238,231,85,360);line(238,231,231,223);line(231,223,85,247);
  line(231,223,229,204);line(229,204,85,185);line(229,204,85,185);
  line(229,204,238,192);line(238,192,85,64);line(238,192,250,189);
  line(258,180,220,24);
  setcolor(0);
  rectangle(267,156,281,168);rectangle(227,163,241,175);rectangle(200,210,214,222);
  rectangle(205,181,219,193);rectangle(205,234,219,246);rectangle(222,254,236,266);
  rectangle(244,260,258,272);rectangle(262,260,276,272);rectangle(290,250,304,262);
  rectangle(290,226,304,238);rectangle(290,209,304,221);rectangle(265,209,279,221);
  rectangle(240,209,252,221);rectangle(423,157,437,169);rectangle(397,152,411,164);
  rectangle(370,147,384,159);rectangle(343,155,357,167);rectangle(329,179,343,191);
  rectangle(326,204,340,216);rectangle(329,221,343,233);rectangle(343,240,357,252);
  rectangle(363,250,377,262);rectangle(389,256,403,268);rectangle(413,249,427,261);
  setfillstyle(1,14);
  floodfill(270,160,0);floodfill(230,170,0);floodfill(205,215,0);
  floodfill(210,185,0);floodfill(210,240,0);floodfill(230,257,0);
  floodfill(250,265,0);floodfill(270,265,0);floodfill(295,255,0);
  floodfill(295,230,0);floodfill(295,218,0);floodfill(270,218,0);
  floodfill(245,218,0);floodfill(430,160,0);floodfill(405,158,0);
  floodfill(375,150,0);floodfill(350,160,0);floodfill(340,185,0);
  floodfill(330,209,0);floodfill(340,225,0);floodfill(350,245,0);
  floodfill(370,255,0);floodfill(395,260,0);floodfill(420,250,0);

 }



/***************************************************************************/
 void pantalla_iniciar()
 {
	int eleccion;
	cleardevice();
	setfillstyle(1,BLUE);
	floodfill(10,10,WHITE);
	setfillstyle(9,7);
	bar(0,440,640,480);
	setcolor(BLACK);
	rectangle(0,440,640,480);
	rectangle(60,375,160,415);
	rectangle(260,375,360,415);
	rectangle(460,375,560,415);
  setfillstyle(9,7);
	floodfill(81,385,BLACK);
	floodfill(261,385,BLACK);
	floodfill(461,385,BLACK);
  settextstyle(3,0,1);
	setcolor(15);
	outtextxy(85,385,"AYUDA");
	outtextxy(285,385,"INICIAR");
	outtextxy(485,385,"SALIR");
	settextstyle(0,0,1);
	outtextxy(45,450,"Seleccione su Opcion...");

	eleccion=raton(60,375,160,415,3);

	 switch(eleccion)
		   {
			case 1:
				   break;
			case 2:
				   pantalla_iniciar2();
				   break;
			case 3:
                   closegraph();
				   restorecrtmode();
				   exit(1);
		   }


 }

/***************************************************************************/
 void pantalla_iniciar2(void)
 {
   int /*eleccion=0,*/coles=1,continua=0,x,y,x1,y1,clic;
   int cuadros[100][3],cont=-1,j;

  cleardevice();
	setfillstyle(1,BLUE);
	floodfill(10,10,WHITE);
	setfillstyle(9,7);
	bar(0,440,640,480);
	setcolor(BLACK);
	rectangle(0,440,640,480);
	rectangle(60,375,160,415);
	rectangle(210,375,310,415);
	rectangle(360,375,460,415);
	rectangle(510,375,610,415);
  setfillstyle(9,7);
	floodfill(81,385,BLACK);
	floodfill(261,385,BLACK);
	floodfill(431,385,BLACK);
	floodfill(550,385,BLACK);
  settextstyle(3,0,1);
	setcolor(15);
	outtextxy(85,385,"COLOR");
	outtextxy(225,385,"MOSTRAR");
	outtextxy(385,385,"DIVIDIR");
	outtextxy(535,385,"SALIR");
	/*setfillstyle(1,0);
	floodfill(70,10,WHITE);*/
	setfillstyle(1,0);
	bar(60,0,640,350);

	 cuadricula();

/*while(eleccion!=4)
	 {
	  eleccion=raton(60,375,160,415,4);
	  switch(eleccion)
		   {
			case 1:
				   coles=color();
				   break;
			case 2:
				   break;
			case 3:
				   break;
			case 4:
						 pantalla_iniciar();
						 break;
		   }
	  }*/
	mver();
	while(continua==0)
		 {
		  x=mxpos(1);
		  y=mypos(1);
		  clic=mclick();
		  if(clic==1)
			{
			if(x>=60 && y<=350)
			   {
				mocultar();
				/*cont=cont+1;*/
				x1=(x/10)*10;
				y1=(y/10)*10;
				/*cuadros[cont][0]=x1;
				cuadros[cont][1]=y1;
				cuadros[cont][2]=coles;*/
				setfillstyle(1,coles);
				bar(x1,y1,x1+10,y1+10);
				mver();
			   }
			if(x>=60 && x<=160 && y>=375 && y<=415)
			  {
				   coles=color();
				   mver();
			  }
			/*if(x>=210 && x<=310 && y>375 && y<415)
			   {
				for(j=0;j<i;j++)
				   {
					setfillstyle(1,cuadros[j][2]);
					bar(cuadros[j][0],cuadros[j][1],cuadros[j][0]+10,cuadros[j][1]+10);
				   }
			   }*/
			if(x>=510 && x<=610 && y>=375 && y<=415)
			   continua=1;
			}
		 }
	 mocultar();
	 pantalla_iniciar();
 }


/***************************************************************************/


int color(void)
{
 int i,x1,y1,x,y,seguir=0,pres,opcion;

 x1=30;
 y1=15;
	for(i=0;i<16;i++)
	   {
		setcolor(0);
		circle(x1,y1,10);
		setfillstyle(1,i);
		floodfill(x1,y1,BLACK);
		y1=y1+25;
	   }
   mver();
   msituar(1,10,5);
   mlimit(1,0,0,59,400);
   while(seguir==0)
	  {
	   pres=0;
	   x=mxpos(1);
	   y=mypos(1);
	   pres=mclick();
	   if(pres==1)
		{

		 if((x>=20) && (x<=40) && ((y>=5 && y<=25) || (y>=5 && y<=25) ||
			(y>=30 && y<=50) || (y>=55 && y<=75) || (y>=80 && y<=100) ||
			(y>=105 && y<=125) || (y>=130 && y<=150) || (y>=155 && y<=175) ||
			(y>=180 && y<=200) || (y>=205 && y<=225) || (y>=230 && y<=250) ||
			(y>=255 && y<=275) || (y>=280 && y<=300) || (y>=305 && y<=325) ||
			(y>=330 && y<=350) || (y>=355 && y<=375) || (y>=380 && y<=400)))
		   {
			 opcion=y/25;
			 seguir=1;
		   }
		}
	 }
	mlimit(1,0,0,640,470);
	mocultar();
	setfillstyle(1,1);
	bar(0,0,59,400);
   /*x1=30;
	y1=15;
    for(i=0;i<16;i++)
	   {
		setcolor(1);
		circle(x1,y1,10);
		setfillstyle(1,1);
		floodfill(x1,y1,1);
		y1=y1+25;
	   }*/
  return(opcion);
}

void cuadricula(void)
{
  int x1,y1,x2,y2,i,j;

	y1=0;
	y2=10;
    setfillstyle(1,0);
	bar(60,0,640,350);
    setcolor(15);
	for(i=1;i<=35;i++)
	   {
		x1=60;
		x2=70;
		for(j=1;j<58;j++)
			{
			 rectangle(x1,y1,x2,y2);
			 x1=x1+10;
			 x2=x2+10;
			};
		 rectangle(x1,y1,x2-1,y2);
		 y1=y1+10;
		 y2=y2+10;
	   }
}

int raton(int x1, int y1, int x2, int y2, int can)
{
 int x,y,pres,opcion,seguir=0;

 mver();
 msituar(1,320,235);
 pres=0;
 while(seguir==0)
	   {
		x=mxpos(1);
		y=mypos(1);
		pres=mclick();
		if(pres==1)
		  {
		   if(can==1)
			 {
				 if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
					{
					 opcion=1;
					 seguir=1;
					}
			   }
			 else
			   if(can==2)
				 {
				  if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
					{
					 opcion=1;
					 seguir=1;
					}
				  if(x>=(x1+200) && x<=(x2+200) && y>=y1 && y<=y2)
					{
					 opcion=2;
					 seguir=1;
					}
				 }
              else
			   if(can==3)
				 {
				  if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
					{
					 opcion=1;
					 seguir=1;
					}
				  if(x>=(x1+200) && x<=(x2+200) && y>=y1 && y<=y2)
					{
					 opcion=2;
					 seguir=1;
					}
				   if(x>=(x1+400) && x<=(x2+400) && y>=y1 && y<=y2)
					{
					 opcion=3;
					 seguir=1;
					}
				 }
               else
			   if(can==4)
				 {
				  if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
					{
					 opcion=1;
					 seguir=1;
					}
				  if(x>=(x1+150) && x<=(x2+150) && y>=y1 && y<=y2)
					{
					 opcion=2;
					 seguir=1;
					}
				   if(x>=(x1+300) && x<=(x2+300) && y>=y1 && y<=y2)
					{
					 opcion=3;
					 seguir=1;
					}
				   if(x>=(x1+450) && x<=(x2+450) && y>=y1 && y<=y2)
					{
					 opcion=4;
					 seguir=1;
					}
				 }
			 }
		   }
  mocultar();
  return(opcion);
}
