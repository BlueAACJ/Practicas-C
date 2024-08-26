 #include<stdio.h>
 #include<stdlib.h>
 #include<process.h>
 #include<conio.h>
 #include<graphics.h>
 #include "a:\presenta.c"

 #define X 0
 #define Y 1
 #define DIM 2
 #define PMAX 100
 #define ARRIBA 72
 #define ABAJO 80
 #define DERECHA 77
 #define CLAVE 8
 #define IZQUIERDA  75
 #define ENTER 13
 #define NEGRO 0
 #define BLANCO 15
 #define TAMCUR 5
 #define ponercursor(x,y) dibcursor(x,y);
 #define borrarcursor(x,y) dibcursor(x,y);

 typedef enum {FALSE,TRUE} bool;
 typedef int tPointi[DIM];
 typedef tPointi tPolygoni[PMAX];

 void polilinea(void);

 long area2(tPointi c,tPointi a,tPointi b)
 {
  long area;
  area=(b[0]-a[0])*(c[1]-a[1]);
  area-=(b[1]-a[1])*(c[0]-a[0]);
  area=(area)*(-1);
  return(area);
 }

 long areaPoly2(int n,tPolygoni P)
 {
  int i;
  long suma=0;
  for(i=1;i<n-1;i++)
	suma+=area2(P[0],P[i],P[i+1]);
  return(suma);
 }

  void xorpixel(int x,int y)
			{
			 putpixel(x,y,CLAVE^getpixel(x,y));
			}
	 void dibcursor(int x,int y)
		 {
			int i;
			for(i=0;i<TAMCUR;i++)
					{
						xorpixel(x-i,y);
						xorpixel(x+i,y);
						xorpixel(x,y-i);
						xorpixel(x,y+i);
					}
			 xorpixel(x,y);
			}
			/***********************************/
      	int leer(void)
		 {
			int tecla;
			while((tecla=getch())!=0)
			if(tecla==27)
				exit(0);
			else
				return(tecla);
				return(getch());

			}
			/*****************************************/
		void dibujo1(void)
			{

            int body_ping[] = {175,67,167,67,167,68,162,68,162,70,157,70,157,72,155,72,155,74,151,74,
						151,77,150,77,150,80,149,80,149,81,146,81,146,85,145,85,145,87,144,87,
						144,120,145,120,145,136,146,136,146,142,145,142,145,144,144,144,144,145,143,145,
						143,147,142,147,142,151,140,151,140,154,136,154,136,157,135,157,135,160,134,
						160,134,161,133,161,133,163,132,163,132,164,131,164,131,166,130,166,130,167,
                        129,167,129,173,124,173,124,179,123,179,123,185,122,185,122,188,121,188,
						121,193,120,193,120,195,119,195,119,199,116,199,116,201,114,201,114,202,
						113,202,113,207,111,207,111,217,113,217,113,220,111,220,111,222,110,222,
                        110,227,106,227,106,231,104,231,104,232,102,232,102,233,98,233,98,234,93,234,
						93,236,91,236,91,237,89,237,89,244,91,244,91,260,89,260,89,264,88,264,88,
						267,89,267,89,269,91,269,91,270,93,270,93,271,98,271,98,274,104,274,104,
						275,106,275,106,276,110,276,110,277,114,277,114,278,122,278,122,280,124,
						280,124,281,129,281,129,283,132,283,132,284,135,284,135,286,142,286,142,
						284,145,284,145,283,148,283,148,281,149,281,149,280,150,280,150,278,154,
                        278,154,276,163,276,163,275,200,275,200,280,202,280,202,283,206,283,206,284,
						207,284,207,284,220,286,220,284,221,284,221,283,223,283,223,281,225,281,
						225,280,226,280,226,278,227,278,227,276,232,276,232,275,233,275,233,274,
						234,274,234,271,235,271,235,270,236,270,236,269,240,269,240,268,243,268,
						243,265,246,265,246,263,248,263,248,262,252,262,252,261,255,261,255,258,
						256,258,256,257,257,257,257,250,257,249,255,249,255,246,252,246,252,245,
						251,244,248,244,248,243,246,243,246,238,245,238,245,236,246,236,243,199,
						242,199,242,198,240,198,240,192,237,192,237,188,236,188,235,183,235,180,
						234,180,234,177,233,177,233,172,232,172,232,169,227,169,227,164,223,160,
						222,160,222,157,221,157,221,154,220,154,220,149,214,149,214,144,213,144,
						213,142,212,142,212,138,211,138,211,136,210,136,210,134,207,134,207,129,
						206,129,206,118,205,118,205,93,202,93,202,87,201,87,201,84,199,84,199,80,
						196,80,196,78,192,74,192,73,189,73,189,72,186,72,186,70,183,70,183,68,175,
						68,175,67};
			int eye_left[] = {159,102,156,102,151,102,150,104,150,116,151,117,151,121,154,121,154,
							  118,156,118,156,117,159,117,159,115,162,115,162,107,161,107,161,104,160,104,160,103,159,102};
			int eye_right[] = {189,120,189,117,191,117,191,110,189,110,189,105,188,102,186,100,184,99,
							   176,99,175,100,173,102,172,104,172,115,175,115,175,117,177,117,177,118,
							   183,118,183,120,186,120,189,120};
			int mouth_ping[] = {175,117,172,115,162,115,159,117,156,118,154,121,151,121,151,125,150,
								125,150,130,151,133,154,136,156,139,158,142,161,144,171,144,171,143,
								174,143,174,141,176,141,176,139,180,139,180,137,183,137,183,135,186,
								135,186,133,189,133,189,129,191,129,191,125,189,125,189,123,186,123,
								186,121,183,120,183,118,177,118,175,117};
			int mouth_inside[] = {157,136,162,137,169,137,172,136,174,135,176,134,178,132,181,130,184,
								  128,186,126};
			int body_ping_inside[] = {189,133,186,133,186,135,183,135,183,137,180,137,180,139,176,139,
									  176,141,174,141,174,143,171,143,171,144,161,144,158,142,156,139,
									  154,136,151,133,150,130,150,148,149,148,149,150,148,150,148,153,
									  144,153,144,156,143,156,143,159,142,159,142,161,141,161,141,169,
									  139,169,139,174,135,174,135,180,134,180,134,182,133,182,133,186,
									  132,186,132,189,131,189,131,192,130,192,130,195,129,195,129,200,
									  128,200,128,219,130,219,132,222,135,225,136,227,139,227,141,230,
									  146,236,149,237,151,240,153,241,153,248,150,248,150,250,146,250,
									  146,255,149,255,149,258,150,258,150,261,153,262,154,262,154,263,
									  181,263,181,262,184,262,184,260,185,259,187,259,187,258,190,258,
									  190,257,193,257,193,255,194,253,197,250,200,250,200,249,201,249,
									  201,221,202,221,202,219,211,219,212,217,212,184,211,184,211,181,
									  208,181,208,179,207,179,207,174,206,174,206,169,203,169,202,168,
									  202,161,200,161,200,153,197,153,197,148,196,148,195,146,192,140,
									  191,136,190,134,189,133};
int foot_left[] = {122,217,113,217,113,220,111,220,111,222,110,222,110,227,106,227,106,231,104,231,104,
				   232,102,232,102,233,98,233,98,234,93,234,93,236,91,236,91,237,89,237,89,244,91,244,
				   91,260,89,260,89,264,88,264,88,267,89,267,89,269,91,269,91,270,93,270,93,271,98,271,
				   98,274,104,274,104,275,106,275,106,276,110,276,110,277,114,277,114,278,122,278,122,
				   280,124,280,124,281,129,281,129,283,132,283,132,284,135,284,135,286,142,286,142,284,
				   145,284,145,283,148,283,148,281,149,281,149,280,150,280,150,278,150,261,150,258,149,
				   258,149,255,146,255,143,250,143,248,142,249,142,246,141,246,141,243,140,243,140,240,
				   136,240,136,236,135,236,135,233,134,233,134,231,133,231,133,230,132,230,132,227,129,
				   224,129,221,124,221,122,217};
int foot_right[] = {213,219,211,219,202,219,202,221,201,221,201,249,201,275,200,275,200,280,202,280,202,
					283,206,283,206,284,207,284,207,286,220,286,220,284,221,284,221,283,223,283,223,281,
					225,281,225,280,226,280,226,278,227,278,227,276,232,276,232,275,233,275,233,274,234,
					274,234,271,235,271,235,270,236,270,236,269,240,269,240,268,243,268,243,265,246,265,
					246,263,248,263,248,262,252,262,252,261,255,261,255,258,256,258,256,257,257,257,257,
					250,257,249,255,249,255,246,252,246,252,245,251,244,248,244,248,243,246,243,246,238,
					245,238,245,236,243,236,243,224,240,224,240,222,237,222,237,225,236,225,234,227,234,
					233,228,233,228,233,226,234,226,236,222,236,218,235,216,233,214,231,213,227,213,222,213,219};


			drawpoly(254,body_ping);
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(165,87,WHITE);
			drawpoly(20,eye_left);
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(157,105,WHITE);
			drawpoly(22,eye_right);
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(178,103,WHITE);
			drawpoly(40,mouth_ping);
      setfillstyle(SOLID_FILL,YELLOW);
			floodfill(165,130,WHITE);
			setcolor(BLACK);
			drawpoly(10,mouth_inside);
			setcolor(WHITE);
			drawpoly(118,body_ping_inside);
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(185,230,WHITE);
			drawpoly(93,foot_left);
			setfillstyle(SOLID_FILL,YELLOW);
			floodfill(121,252,WHITE);
			drawpoly(85,foot_right);
      setfillstyle(SOLID_FILL,YELLOW);
			floodfill(224,256,WHITE);
			setcolor(BLACK);
			circle(155,112,5);
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(155,111,BLACK);
			circle(181,112,5);
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(181,113,BLACK);
			setcolor(GREEN);
			}

    int condicion1(int *x,int *y)
  {
	if(((*x>70)&&(*x<200))&&((*y>15)&&(*y<85)))
	   return(1);
	return(0);
  }

  int condicion2(int *x,int *y)
  {
   if(((*x>180)&&(*x<320))&&((*y>45)&&(*y<120)))
	  return(1);
   return(0);
  }

  int condicion3(int *x,int *y)
  {
	if(((*x>50)&&(*x<200))&&((*y>260)&&(*y<360)))
	  return(1);
    return(0);
  }

  int condicion4(int *x,int *y)
  {
	if(((*x>60)&&(*x<200))&&((*y>88)&&(*y<250)))
	  return(1);
    return(0);
  }

  int condicion5(int *x,int *y)
  {
	if(((*x>220)&&(*x<313))&&((*y>140)&&(*y<270)))
	  return(1);
    return(0);
  }

	/******************************************/
	void verificar(int *x,int *y)
			{
			 char *varx="",*vary="";

			 if(condicion1(x,y))
						{
							itoa(*x,varx,10);
              outtextxy(463,21,varx);
							itoa(*y,vary,10);
							outtextxy(502,21,vary);
						}
			 if(condicion2(x,y))
					 {
						 itoa(*x,varx,10);
             outtextxy(463,21,varx);
						 itoa(*y,vary,10);
						 outtextxy(502,21,vary);
					 }
			 if(condicion3(x,y))
					{
					itoa(*x,varx,10);
          outtextxy(463,21,varx);
					itoa(*y,vary,10);
					outtextxy(502,21,vary);
					}
			 if(condicion4(x,y))
			 {
				itoa(*x,varx,10);
        outtextxy(463,21,varx);
				itoa(*y,vary,10);
				outtextxy(502,21,vary);
			 }
			 if(condicion5(x,y))
			 {

				 itoa(*x,varx,10);
         outtextxy(463,21,varx);
				 itoa(*y,vary,10);
				outtextxy(502,21,vary);
			 }
			}
      /*************************************/

			/**************************************/
			void comprobar(int*x,int*y)
				{
				int a=0,b=0,c=0,d=0,i=0;
				int a1=0,b1=0,c1=0,d1=0;
				tPolygoni rectang;
				long area,area1;
				void *buf;

				if(condicion1(x,y))
				{
				  if(i==0)
				  {
					a=70;b=15;c=200;d=85;
				  rectang[0][0]=a;
				  rectang[0][1]=b;
				  rectang[1][0]=a;
				  rectang[1][1]=d;
				  rectang[2][0]=c;
				  rectang[2][1]=d;
				  rectang[3][0]=c;
				  rectang[3][1]=b;
					area=areaPoly2(4,rectang);
					i++;
				  }
				  else
				  {
					a1=70;b1=15;c1=200;d1=85;
					rectang[0][0]=a1;
				  rectang[0][1]=b1;
				  rectang[1][0]=a1;
				  rectang[1][1]=d1;
				  rectang[2][0]=c1;
				  rectang[2][1]=d1;
				  rectang[3][0]=c1;
				  rectang[3][1]=b1;
					area1=areaPoly2(4,rectang);
					i++;

				  }
				}
				if(condicion2(x,y))
				{

                  if(i==0)
				  {
					a=180;b=45;c=320;d=120;
                  rectang[0][0]=a;
				  rectang[0][1]=b;
				  rectang[1][0]=a;
				  rectang[1][1]=d;
				  rectang[2][0]=c;
				  rectang[2][1]=d;
				  rectang[3][0]=c;
				  rectang[3][1]=b;
					area=areaPoly2(4,rectang);
					i++;
				  }
				  else
				  {
				   a1=180;b1=45;c1=320;d1=120;
					rectang[0][0]=a1;
				  rectang[0][1]=b1;
				  rectang[1][0]=a1;
				  rectang[1][1]=d1;
				  rectang[2][0]=c1;
				  rectang[2][1]=d1;
				  rectang[3][0]=c1;
				  rectang[3][1]=b1;
					area1=areaPoly2(4,rectang);
					i++;

				  }
				}
				if(condicion3(x,y))
				{
				  a=50;b=260;c=200;d=360;
				}
				if(condicion4(x,y))
				{

                  if(i==0)
				  {
                    a=60;b=88;c=200;d=250;
                  rectang[0][0]=a;
				  rectang[0][1]=b;
				  rectang[1][0]=a;
				  rectang[1][1]=d;
				  rectang[2][0]=c;
				  rectang[2][1]=d;
				  rectang[3][0]=c;
				  rectang[3][1]=b;
					area=areaPoly2(4,rectang);
					i++;
				  }
				  else
				  {
                    a1=60;b1=88;c1=200;d1=250;
					rectang[0][0]=a1;
				  rectang[0][1]=b1;
				  rectang[1][0]=a1;
				  rectang[1][1]=d1;
				  rectang[2][0]=c1;
				  rectang[2][1]=d1;
				  rectang[3][0]=c1;
				  rectang[3][1]=b1;
					area1=areaPoly2(4,rectang);
					i++;

				  }
				}
				if(condicion5(x,y))
				{
				  a=229;b=140;c=313;d=270;
				}
		 if(i==2)
		 {
		  if(area1<area)
		  {a=a1;b=b1;c=c1;d=d1;}
		 }
		 buf=malloc(imagesize(a,b,c,d));
		 if(buf!=NULL)
		 {
		  getimage(a,b,c,d,buf);
		 }
		 putimage(430,150,buf,COPY_PUT);
		 free(buf);
		 }
 /**********************************/
 int pasoacel=16;
 int escogerpuntacel (int *x,int *y)
		 {
			int *a,*b;
			 int c,ctarri,ctaba,ctder,ctizq;
			 ctarri=ctaba=ctder=ctizq=0;
			 ponercursor(*x,*y);
			/* a=x;b=y;
			 verificar(a,b);*/
			 for(;;)
					{
					 switch(c=leer())
								{
								 case ARRIBA:if(*y>12)
													 {
															 borrarcursor(*x,*y);
															 setfillstyle(1,RED);
															 bar(451,21,489,49);
															 bar(491,21,529,49);
															 *y+=(++ctarri<pasoacel)?-1:-pasoacel;
															 ctaba=ctder=ctizq=0;
															 ponercursor(*x,*y);
															a=x;b=y;
															 verificar(a,b);
														}
												break;
								 case ABAJO:if(*y<412)
													{
														borrarcursor(*x,*y);
                            setfillstyle(1,RED);
														bar(451,21,489,49);
														bar(491,21,529,49);
														*y+=(++ctaba<pasoacel)?1:pasoacel;
														ctarri=ctder=ctizq=0;
														ponercursor(*x,*y);
														a=x;b=y;
														verificar(a,b);
													}
												break;
								 case DERECHA: if(*x<377)
													{
														 borrarcursor(*x,*y);
                             setfillstyle(1,RED);
														 bar(451,21,489,49);
														 bar(491,21,529,49);
														 *x+=(++ctder<pasoacel)?1:pasoacel;
														 ctarri=ctaba=ctizq=0;
														 ponercursor(*x,*y);
														 a=x;b=y;
														 verificar(a,b);
													}
											break;
								case IZQUIERDA: if(*x>25)
													{
														borrarcursor(*x,*y);
														setfillstyle(1,RED);
														bar(451,21,489,49);
														bar(491,21,529,49);
														*x+=(++ctizq<pasoacel)?-1:-pasoacel;
														ctder=ctarri=ctaba=0;
														ponercursor(*x,*y);
														a=x;b=y;
														verificar(a,b);
													 }
												break;
								default: borrarcursor(*x,*y);
								return (c);
					}
			}
  }



 /*****************************/
 void punto(void)
			 {
				 int x1,y1,car;
				 void *buf;
				 x1=getmaxx()/2-100;
				 y1=getmaxy()/2-30;
				 outtextxy(463,5,"x");
				 outtextxy(505,5,"y");
				 car=escogerpuntacel(&x1,&y1);
				 buf=malloc(imagesize(430,150,580,312));
				 getimage(430,150,580,312,buf);
				 while(car==ENTER)
				 {
				  if(condicion1(&x1,&y1)||condicion2(&x1,&y1)||condicion3(&x1,&y1)||condicion4(&x1,&y1)||condicion5(&x1,&y1))
					{
					 putimage(430,150,buf,COPY_PUT);
					 comprobar(&x1,&y1);
					}
				   car=escogerpuntacel(&x1,&y1);
				 }
                free(buf);

		 }
/*************************************/

void cuadro(void)
	{
		 rectangle(1,1,getmaxx()-1,getmaxy()-1);
		 setcolor(WHITE);
		 rectangle(3,3,getmaxx()-250,getmaxy()-50);
		 setfillstyle(SOLID_FILL,LIGHTGRAY);
		 floodfill(4,4,WHITE);
		 setfillstyle(SOLID_FILL,LIGHTGRAY);
		 rectangle(391,3,getmaxx()-3,getmaxy()-50);
		 floodfill(395,5,WHITE);
		 setfillstyle(SOLID_FILL,BLUE);
		 rectangle(3,433,getmaxx()-3,getmaxy()-3);
		 floodfill(8,440,WHITE);
		 dibujo1();
		 setcolor(14);
		 settextstyle(2,HORIZ_DIR,5);
		 outtextxy(75,438,"PRESIONE ENTER :PARA ESCOGER FIGURA");
		 outtextxy(75,450,"PRESONE ESC :PARA SALIR DEL PROGRAMA");
		 outtextxy(75,461,"USE DIRECCIONALES: PARA LA INTERACION");
		 setfillstyle(SOLID_FILL,RED);bar(392,4,getmaxx()-4,getmaxy()-51);
		 setcolor(WHITE);
		 setfillstyle(SOLID_FILL,LIGHTGRAY);
		 rectangle(450,20,490,50);
		 floodfill(411,25,WHITE);
		 setfillstyle(SOLID_FILL,RED);
		 rectangle(490,20,530,50);
		 floodfill(500,25,WHITE);
		 circle(80,45,6);
		 line(86,45,105,45);
		 setfillstyle(9,RED);
		 circle(130,45,25);
		 floodfill(130,45,WHITE);
		 setfillstyle(11,BLUE);
		 circle(150,45,25);
		 floodfill(150,45,WHITE);
		 setfillstyle(2,BLUE);
		 floodfill(165,45,WHITE);
		 line(135,65,140,200);
		 setcolor(BLUE);
		 setlinestyle(DASHED_LINE,2,NORM_WIDTH);
		 rectangle(70,15,200,85);
		rectangle(180,45,320,120);
		 rectangle(50,260,200,360);
		 rectangle(60,88,200,250);
		 rectangle(220,140,313,270);
		 setcolor(16);
		 }
 /************************/
 void main(void)
	{
	 int ada=DETECT,modo;
	 initgraph(&ada,&modo,"c:\\TC20\\BIN");
	 presenta();
	 getch();
	 cleardevice();
	 cuadro();
	 punto();
	 getch();
	 restorecrtmode();
 }
