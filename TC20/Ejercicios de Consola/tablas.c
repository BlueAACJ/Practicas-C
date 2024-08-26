/* PROGRAMA DE MATEMATICA DISCRETA
   ELABORADO POR MARIA FELIX TABLADA
   GRUPO 2M4CO
   FECHA: 9-10-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define num   5


int conj(int a,int b);
int disj(int a,int b);
int neg(int a);
void dist(int a);
int implic(int a,int b);
void presentacion(void);


 char forma[10]="%",temp[10]="";

void main() {
 char *valores[]={"F","V"};
 char formato[50];

 /* variables que almacenaran los valores de verdad */

 int P,Q,R; /* 0 es falso, 1 es verdadero */

 /*cada variable solo puede tomar 2 posibles valores de verdad
  para mostrar la tabla se usaran ciclos anidados
 */
 clrscr();
 dist(num); /* cambiando la distancia de separacion de las columnas */

 sprintf(formato," %s %s %s %s %s %s %s\n",forma,forma,forma,forma,forma,forma,forma);
 printf("mostrando tabla de valores de verdad\n");
 printf(formato,"P","Q","R","PoQ","neg(PoQ)","P->R","neg(PoQ)->(P->R)" );

 for(P=1;P>=0;P-- ){
 	for(Q=1;Q>=0;Q--){
		for(R=1;R>=0;R--){
			printf(formato,
			valores[P], /* valores logicos de columna P */
			valores[Q], /* valores logicos de columna Q */
			valores[R], /* valores logicos de columna R */
			valores[disj(P,Q)], /*  disjuncion de valor columna P o Q */
			valores[neg(disj(P,Q))], /*negacion de la conjuncion de P o Q */
			valores[implic(P,R)], /*P->R ,usamos su forma equivalente neg(P)oQ o la funcion implicacion*/
			valores[implic(neg(disj(P,Q)),implic(P,R))]); /* neg(PoQ)->(P->R)   */
		 }
	 }
 }
	printf("\n\n\n");
	presentacion();
   	getch();
}
/* funcion conjuncion devuelve verdadero (1) si ambos son verdaderos
 devuelve falso (0) si almenos uno de ellos es falso
*/
int conj(int a,int b){
	return (a && b);
}

/*funcion disjuncion devuelve verdadero (1) si almenos uno de ellos es verdadero
*/
int disj(int a,int b){
	return (a || b);
}
/* funcion negacion, devuelve el valor logico contrario al de su parametro
*/
int neg(int a){
	return (a==1 ? 0 : 1);
}
/* la funcion dist, se utiliza para especificar la distancia de separacion
de las columnas */
void dist(int a){
 sprintf(temp,"%ds",a);
 strcat(forma,temp);
}
/*la funcion implic, calcula el valor de verdad de P->Q,dado los
valores de P y Q como parametros*/
int implic(int a,int b){
	return disj(neg(a),b);
}

void presentacion(){
 printf("Programa elaborado por Maria Felix Tablada\n");
 printf("Grupo 2M4Co\n");
}