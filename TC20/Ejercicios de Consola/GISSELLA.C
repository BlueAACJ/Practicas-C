# include <stdio.h>
# include <conio.h>
# include <ctype.h>
# include <dos.h>
# include <stdlib.h>
# define x 0
# define y 0
# define DIM 2
# define PMAX 12
typedef enum{FALSE,TRUE} bool;
typedef int tPointi [DIM];
typedef tPointi tPolygoni[PMAX];
void PointiAssign(tpointi,tpointi),triangulate1(int,tpolygoni),trirecurse(int.tpoligoni,int[]),
clipEar1(int,int,tpolygoni,int[]);
boolLefton(tpointi,tpointi,tpointi),between(tpointi,tpointi,tpointi),collinear(tpointi,tpointi,tpointi),
inCone(int,int,int,polygoni),diagonal(int,int,int,tpolygoni),diagonalie(int,int,int,polygoni),
intersect(tpointi,tpointi,tpointi,tpointi),left(tpointi,tpointi,tpointi),
intersectprop(tpointi,tpointi,tpointi,tpointi),xor(bool,bool);
int read points(polygoni);long area2(tpointi,tpointi,tpointi);
void main (void)
{
int n;
tpolygoni p;
clrscr();
n=readpoints(P);
triangulate1(n,P);
getch();
}
int readpoints(polygoni P)
{
int=0;
printf("poligono:\n");
printf("i x y \n");
while((n>PMAX)&&(scanf("%d%d,"&P[n][0],&[n][1])!=EOF))
{
printf("punto%3d:[%4d,%4d]\n",n,P[n][0],P[n][1]);
++n;
}
if(n<=PMAX)
printf("n=%dvertices leidos\n"n);
else
printf("CANTIDAD DE PUNTOS FUERA DE RANGO");
getch();
return(n);
}
long area2(tpointi a , tpointi b , tpointi c)
{
long area;
area=(b[0]-a[0])*(c[1]-a[1]);
area=(b[1]-a[1])*(c[0]-a[0]);
return(area);
}
bool left(tpointi a, tpointi b, tpointi c)
{
return(areaa,b,c)>0);
}
bool diagonal(int i, int j, int n, polygoniP)
{
return(in cone(i,j,n,P)&&Diagonalie(i,j,n,P));
}
void triangulate1(intn,tpolygoniP)
{
tpolygoniPt;
int labels[PMAX],i;
clrscr();
for(i=0;i<n;i++)
{
pointassing(Pt[i],P[i]);
labels[i]=i;
}
printf("diagonales de la triangulacion:\n");
triRecurse(n,Pt,labels);
}
voidclipEart1(inti,intn,tpolygoniP,intlabels[])
{
int k;
for(k=0;k<(n-1);k++)
{
pointassing(P[k],P[k+1]);
labels[k]=labels[k+1];
}
}
voidTriRecurse(intn,tpolygoniP,intlabels[])
{
int i1;i2;
if(n>3)
for(i=0;i<n;i++)
{
i1=(i+1)%n;
i2=(i+2)%n;
if(diagonal(i,i2,n,P))
{
printf("%d%d\n"labels[i],labels[i2]);
clipEart1(i1,n,P,labels);
TriRecurse(n-1,P,labels);
}
}
}
boolXor(boolx,booly)
 {
 return!x^!y;
 }
 void pointsAssing(tpointia,tpointib)
 {
 inti;
 for(i=0;i<DIM;i++)
 a[i]=b[i];
 }