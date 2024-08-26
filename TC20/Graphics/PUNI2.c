#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<string.h>

int cruz0[4][4]={1,1,1,0,
		 0,1,0,0,
		 0,0,0,0,
		 0,0,0,0,};

int cruz1[4][4]={1,0,0,0,
		 1,1,0,0,
		 1,0,0,0,
		 0,0,0,0,};

int cruz2[4][4]={0,1,0,0,
		 1,1,1,0,
		 0,0,0,0,
		 0,0,0,0,};

int cruz3[4][4]={0,1,0,0,
		 1,1,0,0,
		 0,1,0,0,
		 0,0,0,0,};

int linea0[4][4]={1,1,1,1,
		  0,0,0,0,
		  0,0,0,0,
		  0,0,0,0,};

int linea1[4][4]={1,0,0,0,
		  1,0,0,0,
		  1,0,0,0,
		  1,0,0,0,};

int cuadro0[4][4]={1,1,0,0,
		   1,1,0,0,
		   0,0,0,0,
		   0,0,0,0};

int ele10[4][4]={1,0,0,0,
		 1,1,1,0,
		 0,0,0,0,
		 0,0,0,0};

int ele11[4][4]={0,1,0,0,
		 0,1,0,0,
		 1,1,0,0,
		 0,0,0,0};

int ele12[4][4]={1,1,1,0,
		 0,0,1,0,
		 0,0,0,0,
		 0,0,0,0};

int ele13[4][4]={1,1,0,0,
		 1,0,0,0,
		 1,0,0,0,
		 0,0,0,0};

int ele20[4][4]={0,0,1,0,
		 1,1,1,0,
		 0,0,0,0,
		 0,0,0,0};

int ele21[4][4]={1,1,0,0,
		 0,1,0,0,
		 0,1,0,0,
		 0,0,0,0};

int ele22[4][4]={1,1,1,0,
		 1,0,0,0,
		 0,0,0,0,
		 0,0,0,0};

int ele23[4][4]={1,0,0,0,
		 1,0,0,0,
		 1,1,0,0,
		 0,0,0,0};

int zig10[4][4]={1,0,0,0,
		 1,1,0,0,
		 0,1,0,0,
		 0,0,0,0};

int zig11[4][4]={0,1,1,0,
		 1,1,0,0,
		 0,0,0,0,
		 0,0,0,0};

int zig20[4][4]={0,1,0,0,
		 1,1,0,0,
		 1,0,0,0,
		 0,0,0,0};


int zig21[4][4]={1,1,0,0,
		 0,1,1,0,
		 0,0,0,0,
		 0,0,0,0};

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

void dibujar_figura(int px,int py,int fig[4][4],int fill,int c)
{
 setfillstyle(fill,c);
 for(i=0;i<4;i++)
   {for(j=0;j<4;j++)
      {if(fig[i][j])bar3d(x[px+j],y[py+i],x[px+j]+10,y[py+i]+10,3,1);
      }
   }
}

void borrar_figura(int px,int py,int fig[4][4])
{
 setfillstyle(1,0);
 for(i=0;i<4;i++)
   {for(j=0;j<4;j++)
      {if(fig[i][j])bar(x[px+j],y[py+i]-2,x[px+j]+13,y[py+i]+10);
      }
   }
}

int es_posible(int px,int py,int fig[4][4])
{for(j=0;j<4;j++)
    {for(i=0;i<4;i++)
	{if((fig[j][i]==1)&&((juego[py+j][px+i]==1)||((px+i)<0)||((px+i)>9)||((py+j)>24)))
	  {return(0);
	  }
	}
    }
 return(1);
}

void movizq()
{if(es_posible(nowx-1,nowy,*actual))
   {borrar_figura(nowx,nowy,*actual);
    nowx--;
    dibujar_figura(nowx,nowy,*actual,fi,col);
   }
}

void movder()
{if(es_posible(nowx+1,nowy,*actual))
   {borrar_figura(nowx,nowy,*actual);
    nowx++;
    dibujar_figura(nowx,nowy,*actual,fi,col);
   }
}

void rotarback()
{int (*p)[4][4];
 if(tipo==0)
     {if(actual==&cruz0)p=&cruz1;
      else if(actual==&cruz1)p=&cruz2;
      else if(actual==&cruz2)p=&cruz3;
      else if(actual==&cruz3)p=&cruz0;
     }
 else if(tipo==1)
     {if(actual==&cuadro0)p=&cuadro0;
     }
 else if(tipo==2)
     {if(actual==&linea0)p=&linea1;
      else if(actual==&linea1)p=&linea0;
     }
 else if(tipo==3)
     {if(actual==&ele10)p=&ele11;
      else if(actual==&ele11)p=&ele12;
      else if(actual==&ele12)p=&ele13;
      else if(actual==&ele13)p=&ele10;
     }
 else if(tipo==4)
     {if(actual==&ele20)p=&ele21;
      else if(actual==&ele21)p=&ele22;
      else if(actual==&ele22)p=&ele23;
      else if(actual==&ele23)p=&ele20;
     }
 else if(tipo==5)
     {if(actual==&zig10)p=&zig11;
      else if(actual==&zig11)p=&zig10;
     }
 else if(tipo==6)
     {if(actual==&zig20)p=&zig21;
      else if(actual==&zig21)p=&zig20;
     }
 if(es_posible(nowx,nowy,*p))
    {borrar_figura(nowx,nowy,*actual);
     actual=p;
     dibujar_figura(nowx,nowy,*actual,fi,col);
    }
}

void rotarman()
{
 int (*p)[4][4];
 if(tipo==0)
     {if(actual==&cruz0)p=&cruz3;
      else if(actual==&cruz1)p=&cruz0;
      else if(actual==&cruz2)p=&cruz1;
      else if(actual==&cruz3)p=&cruz2;
     }
 else if(tipo==1)
     {if(actual==&cuadro0)p=&cuadro0;
     }
 else if(tipo==2)
     {if(actual==&linea0)p=&linea1;
      else if(actual==&linea1)p=&linea0;
     }
 else if(tipo==3)
     {if(actual==&ele10)p=&ele13;
      else if(actual==&ele11)p=&ele10;
      else if(actual==&ele12)p=&ele11;
      else if(actual==&ele13)p=&ele12;
     }
 else if(tipo==4)
     {if(actual==&ele20)p=&ele23;
      else if(actual==&ele21)p=&ele20;
      else if(actual==&ele22)p=&ele21;
      else if(actual==&ele23)p=&ele22;
     }
 else if(tipo==5)
     {if(actual==&zig10)p=&zig11;
      else if(actual==&zig11)p=&zig10;
     }
 else if(tipo==6)
     {if(actual==&zig20)p=&zig21;
      else if(actual==&zig21)p=&zig20;
     }
 if(es_posible(nowx,nowy,*p))
    {borrar_figura(nowx,nowy,*actual);
     actual=p;
     dibujar_figura(nowx,nowy,*actual,fi,col);
    }
}

void borrar_linea(int py)
{for(i=0;i<10;i++)
       {setfillstyle(1,0);
	bar(x[i],y[py]-2,x[i]+13,y[py]+10);
       }
}

void dibujar_linea(int py)
{for(i=0;i<10;i++)
    {if(juego[py][i]==1)
       {setfillstyle(_fill[py][i],_color[py][i]);
	bar3d(x[i],y[py],x[i]+10,y[py]+10,3,1);
       }
    }
}

void bajarmatriz(int py)
{for(j=py;j>=0;j--)
    {for(i=0;i<10;i++)
       {juego[j][i]=juego[j-1][i];
	_color[j][i]=_color[j-1][i];
	_fill[j][i]=_fill[j-1][i];
       }
    }
 for(i=0;i<10;i++)
   {juego[0][i]=_color[0][i]=_fill[0][i]=0;
   }
}


void buscarlineas()
{
 int k,m;
 int cont=0,noline;
 int lin[4]={50,50,50,50};
 for(j=0;j<25;j++)
    {noline=0;
     for(i=0;i<10;i++)
	{if(juego[j][i]==0)
	   {noline=1;
	    break;
	   }
	}
     if(!noline)
	{lin[cont]=j;
	 cont++;
	}
    }
 lineas+=cont;
 if(cont==1)puntos+=((100*(level+1))+((25-nowy)*(level+1)));
 else if(cont==0)puntos+=((25-nowy)*(level+1));
 else if(cont==2)puntos+=((300*(level+1))+((25-nowy)*(level+1)));
 else if(cont==3)puntos+=((500*(level+1))+((25-nowy)*(level+1)));
 else if(cont==4)puntos+=((1000*(level+1))+((25-nowy)*(level+1)));
 for(k=0;k<4;k++)
    {if(lin[k]==50)break;
     bajarmatriz(lin[k]);
     for(m=lin[k];m>=0;m--)
	{borrar_linea(m);
	 dibujar_linea(m);
	}
    }
}

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



void actualizar_lineas()
{
 char num[3];
 char lin[3];
 char punt[15];
 level=lineas/10;
 dific=(0.44-(level*0.04));
 if(level>10)dific=0.02;
 itoa(level,num,10);
 itoa(lineas,lin,10);
 ltoa(puntos,punt,10);
 setfillstyle(1,0);
 bar(345,88,360,98);
 outtextxy(345,88,num);
 bar(345,128,360,138);
 outtextxy(345,128,lin);
 bar(290,188,365,198);
 outtextxy(290,188,punt);
 borrar_figura(10,25,*actual);
 dibujar_figura(10,25,*next,5,7);

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
outtextxy(190,320,"presiona la tecla 'esc' para salir");
outtextxy(200,160,"ÛÛÛÛÛÛ° ÛÛÛÛÛ° ÛÛÛÛÛÛ° ÛÛÛÛ°   Û° ÛÛÛÛ°");
outtextxy(200,170,"  ÛÛ°   Û°       ÛÛ°   Û° Û°   Û° Û°");
outtextxy(200,180,"  ÛÛ°   ÛÛÛ°     ÛÛ°   ÛÛÛÛÛÛ° Û° ÛÛÛÛ°");
outtextxy(200,190,"  ÛÛ°   Û°       ÛÛ°   Û°   Û° Û°    Û°");
outtextxy(200,200,"  ÛÛ°   ÛÛÛÛÛ°   ÛÛ°   Û°   Û° Û° ÛÛÛÛ°");

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



void dos(){
int salio=0;
clearviewport();
 do{	  pres();
	  marco();
	  lineas=puntos=level=0;
	  for(i=0;i<25;i++)
	    {for(j=0;j<10;j++)
	       {juego[i][j]=0;}
	    }
	  randomize();
	  tipo=rand()%7;
	  do{
		 nexttipo=rand()%7;
		 if(tipo==0){actual=&cruz0;col=14;fi=1;}
		 else if(tipo==1){actual=&cuadro0;col=1;fi=1;}
		 else if(tipo==2){actual=&linea0;col=4;fi=1;}
		 else if(tipo==3){actual=&ele10;col=12;fi=9;}
		 else if(tipo==4){actual=&ele20;col=6;fi=9;}
		 else if(tipo==5){actual=&zig10;col=3;fi=6;}
		 else if(tipo==6){actual=&zig20;col=2;fi=6;}
		 if(nexttipo==0)next=&cruz0;
		 else if(nexttipo==1)next=&cuadro0;
		 else if(nexttipo==2)next=&linea0;
		 else if(nexttipo==3)next=&ele10;
		 else if(nexttipo==4)next=&ele20;
		 else if(nexttipo==5)next=&zig10;
		 else if(nexttipo==6)next=&zig20;
		 nowx=4;
		 nowy=0;
		 do{
		       inicio=clock();
		       actualizar_lineas();
		       borrar_figura(nowx,nowy,*actual);
		       nowy++;
		       dibujar_figura(nowx,nowy,*actual,fi,col);
		       do{
			  ahora=clock();
			  tim=(ahora-inicio);
			  tecla=0;
			  if(kbhit())
			      {tecla=getch();
			       if(tecla=='q')rotarman();
			       else if(tecla=='a')rotarback();
			       else if(tecla==27){salio=1;break;}
			       else if(!tecla)
				    {tecla=getch();
				     if(tecla==80)break;
				     else if(tecla==75)movizq();
				     else if(tecla==77)movder();
				    }
			      }
		       }while((tim/CLK_TCK)<dific);
		       if(salio)break;
		       llego=0;
		       for(j=0;j<4;j++)
			 {for(i=0;i<4;i++)
			    {if(((*actual)[j][i]==1)&&((nowy+j)==24)){llego=1;break;}
			     else if(((*actual)[j][i]==1)&&(juego[nowy+j+1][nowx+i]==1)){llego=1;break;}
			    }
			  if(llego)break;
			 }
		       if(llego)break;
		 }while(1);
		 if(salio)break;
		 for(j=0;j<4;j++)
		    {for(i=0;i<4;i++)
		       {if(((*actual)[j][i]==1))
			  {juego[nowy+j][nowx+i]=(*actual)[j][i];
			   _fill[nowy+j][nowx+i]=fi;
			   _color[nowy+j][nowx+i]=col;
			  }
		       }
		    }
		 buscarlineas();
		 termino=0;
		 for(i=0;i<10;i++)
		    {if(juego[1][i]==1){termino=1;break;}
		    }
		 tipo=nexttipo;
	  }while(!termino);
	  if(salio)break;
	  getch();
	  settextstyle(0,0,2);
	  cleardevice();
	  if(puntos<60000)
		  {outtextxy(100,100,"perdiste :(");
	      }
	  else outtextxy(100,100,"Y DECIAN QUE ESTE PROGRAMA NO SE PODIA HACER");
	  getch();
	  getch();
	  getch();
 }while(1);
 getch();
 closegraph();
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
}
void menu()
{ box(0,0, getmaxx(), getmaxy(),1,GREEN);

box(10,130,110,180,1,LIGHTRED);
outtextxy(12,145,"INSTRUCCIONES");
box(10,220,110,270,1,LIGHTRED);
outtextxy(20,235,"JUGAR");
box(10,310,110,360,1,LIGHTRED);
outtextxy(20,325,"CREDITOS");
box(10,400,110,450,1,LIGHTRED);
outtextxy(20,415,"SALIR");
}
void mueve()
{ char tecla;
int i=1;
menu();
do{
switch(i)
{
case 1: box(10,130,110,180,1,RED);
outtextxy(12,145,"INSTRUCCIONES");
break;
case 2: box(10,220,110,270,1,RED);
outtextxy(20,235,"JUGAR");
break;
case 3: box(10,310,110,360,1,RED);
outtextxy(20,325,"CREDITOS");
break;
case 4: box(10,400,110,450,1,RED);
outtextxy(20,415,"SALIR");
break;
}
tecla=getch();
switch(i)
{
case 1: box(10,130,110,180,1,LIGHTRED);
outtextxy(12,145,"INSTRUCCIONES");
break;
case 2: box(10,220,110,270,1,LIGHTRED);
outtextxy(20,235,"JUGAR");
break;
case 3: box(10,310,110,360,1,LIGHTRED);
outtextxy(20,325,"CREDITOS");
break;
case 4: box(10,400,110,450,1,LIGHTRED);
outtextxy(20,415,"SALIR");
break;
}
switch(tecla)
{
case '\x0': tecla=getch();
switch (tecla)
{ case '\x48':i--;break;
case '\x50':i++;break;
}
if(i>4)i=1;
if(i<1)i=4;
break;

case '\xD': switch(i)

     {	case 1:uno();break;
	case 2:dos();break;
	case 3:tres();break;
	case 4:tecla='\x1B';break;

}
if (i!=4)menu();
	break;

}

} while(tecla!='\x1B');
}

void main(){
inicializa();
mueve();
}