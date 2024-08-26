#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>
 
void main() {

int driver = DETECT,modo;
int angulo = 0;
double x, y; 
/* iniciando el modo grafico */
initgraph(&driver, &modo, "c:\\tc20\\bin");
 
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
 closegraph();
 return 0;
}