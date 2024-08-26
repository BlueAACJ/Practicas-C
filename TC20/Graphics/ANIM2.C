#include<math.h>
#include<graphics.h>
#define N getmaxy()
#define radio 40

/* animacion ruedita */

 void main()
 {
   
   int driver=DETECT,modo;

   /* xc,yc coordenadas del centro */
   int i,xc,yc;

   /* rx1,ry1,seg variables usadas para la cruz */
   int rx1,ry1,seg;

   /* iniciando el modo grafico */
   initgraph(&driver,&modo,"c:\\tc20\\bin");

   /* inicializando la variable */
   yc=getmaxy()/2-radio;
   i=0;

   /* el ciclo se detiene cuando hay flecha abajo o i>=N */
   /* kbhit verifica si se presiona una tecla */ 
   while(i<N&&!kbhit())
   {

   /* incrementando xc para mover la rueda */
   xc=i;
   delay(50);

   /* limpia la pantalla previa */
   clearviewport();

   /* linea representando el camino */
   line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

   /* dibujando la rueda */
   circle(xc,yc,radio);

   /* la cruz de la rueda se muestra alternativamente */
   if(i%2==0)
   {
     line(xc,yc+radio,xc,yc-radio);
     line(xc-radio,yc,xc+radio,yc);
   }
   else
   {
     rx1=xc-(radio/sqrt(2));
     ry1=yc-(radio/sqrt(2));
     seg=sqrt(2)*radio;
     line(rx1,ry1,rx1+seg,ry1+seg);
     line(rx1,ry1+seg,rx1+seg,ry1);
   }

   /* incrementar i */
   i+=3;
  }
}
