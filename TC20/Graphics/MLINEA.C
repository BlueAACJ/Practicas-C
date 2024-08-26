/*Programa elaborado por Maria Felix Tablada */
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>


#define ARRIBA 72
#define ABAJO  80
#define DERECHA 77
#define IZQUIERDA 75
#define NEGRO   0
#define BLANCO  15
#define TAM_CURS  5
#define COL_CURS   8
#define TAM_CURS  5
#define PonerCursor(x,y) dib_cursor(x,y,BLANCO)
#define BorrarCursor(x,y) dib_cursor(x,y,NEGRO)




/*PROTOTIPOS DE FUNCIONES DEL RATON */
int mtest(void);

void mver(void);
void mocultar(void);
int mposx(int modo);
int mposy(int modo);
void msituar(int modo, int x, int y);
int mclick(void);
void mlimitar(int modo, int x1,int y1,int x2, int y2);
void dib_cursor(int x,int y);  /*, int color);  */
void logo(void);
void xor_pixel(int x, int y);

/* VARIABLE DE LOS REGISTROS DEL RATON*/
union REGS reg;


/*VERIFICAR PRESENCIA DEL RATON */
int mtest(void)
{
 reg.x.ax=0x0;
 int86(0x33,&reg,&reg);
 if(reg.x.ax>0)
       return reg.x.bx;
  else
       return 0;
}

/*MOSTRAR PUNTERO DEL RATON */
void mver(void)
{
  reg.x.ax=0x1;
  int86(0x33,&reg,&reg);
}

/*OCULTAR PUNTERO DEL RATON */
void mocultar(void)
{
 reg.x.ax=0x2;
 int86(0x33,&reg,&reg);
}

/*COORDENADA 'X' DEL PUNTERO  */
int mposx(int modo)
{

  reg.x.ax=0x3;
  int86(0x33,&reg,&reg);
  return reg.x.cx/modo;
}


/*COORDENADA 'Y' DEL PUNTERO */
int mposy(int modo)
{
  reg.x.ax=0x3;
  int86(0x33,&reg,&reg);
  return reg.x.dx/modo;
}

/*POSICIONAR EL PUNTERO */
void msituar(int modo, int x, int y)
{
 reg.x.ax=0x4;
 reg.x.cx=x*modo;
 reg.x.dx=y*modo;
 int86(0x33,&reg,&reg);
}

/*VERIFICAR SI EXISTE BOTON PRESIONADO */
int mclick(void)
{
  int r=0;
  reg.x.ax=0x5;
  reg.x.bx=0;
  int86(0x33,&reg,&reg);
  if((reg.x.ax)&1)
       r=1;
  else
    if((reg.x.ax>>1)&1)
	r=2;
  return r;
}

/*LIMITAR AREA DE DESPLAZAMIENTO DEL RATON */
void mlimitar(int modo,int x1,int y1, int x2, int y2)
{
 reg.x.ax=0x7;
 reg.x.cx=x1*modo;
 reg.x.dx=x2*modo;
 int86(0x33,&reg,&reg);
 reg.x.ax=0x8;
 reg.x.cx=y1*modo;
 reg.x.dx=y2*modo;
 int86(0x33,&reg,&reg);
}



void main ()
{
  /*modo grafico*/
  int driver =VGA,modo=VGAHI,n=100,b=200;
  initgraph(&driver,&modo,"C:\\TC20\\BIN");
  logo();
   setbkcolor(DARKGRAY);
  /*Verifica si el mouse esta conectado*/
  if(!mtest()){
    textcolor(RED);
    textbackground(WHITE);
    clrscr();
    gotoxy(13,13);
    printf ("Mouse no instalado\n");
    return;
  }


  /*Activa el mouse */
  mver();
  do {
    gotoxy (10,10);
	settextstyle(2,0,4);
	n=mposx(modo)*2; /*esta en modo vga de 640x480*/
	b=mposy(modo)*2;
	printf ("El Mouse se encuentra en la posicion X: %4d Y: %4f", n, (float)b); /*(float)/b*2.5 */
	dib_cursor(n,b); /*BLANCO);*/
	dib_cursor(n,b);/*,NEGRO); */
	/*dib_cursor(n,b);/*,BLANCO);*/
    settextstyle(2,0,4);
	outtextxy(30,30,"cursor NO destructivo");
	outtextxy(30,40,"presione BOTON DERECHO DEL MOUSE para salir ");
  } while (mclick() != 2);/* si se presiona el boton derecho del mouse se sale */

  /*Deshabilitar Mouse */
  mocultar() ;
}

	void dib_cursor(int x,int y){
 /* void dib_cursor(int x, int y ,int color){
	 int col_ant;
	  col_ant=getcolor();
	  setcolor(color);
	  line(x-TAM_CURS,y,x+TAM_CURS,y);
	  line(x,y-TAM_CURS,x,y+TAM_CURS);
	  setcolor(col_ant); */
	  int i;
	  for (i=0;i< TAM_CURS; i++){
		xor_pixel(x-i,y);
		xor_pixel(x+i,y);
		xor_pixel(x,y-i);
		xor_pixel(x,y+i);

	  }  /* fin de for*/
	  xor_pixel(x,y);
  }

  void xor_pixel(int x, int y){
	 putpixel(x,y,COL_CURS^getpixel(x,y));
  }

  void logo(void){
	  /* cuerpo */
	  bar(15,15,635,475);
	  /*dibujar circulo */
	  setcolor(BLACK);
	  setfillstyle(1,RED);
	  circle(320,240,45);
	  floodfill(320,240,BLACK);

	  setcolor(BLUE);
	  /*settextstyle(2,0,6); */
	  settextstyle(2,0,4);
	  outtextxy(60,400,"ESCRITO POR MARIA FELIX HERRERA TABLADA GRUPO: 2M5CO " );
  }