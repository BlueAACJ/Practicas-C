#include<stdio.h>
#include<conio.h>
void printrect(int,int,int,int);
int main()
{
 int sal,p_hra,p_da;
 float hra,da,gross;
 clrscr();
 /* printing heading box */
 textcolor(YELLOW);
 printrect(20,2,60,4);
 gotoxy(26,3);
 /* printing heading text */
 textcolor(WHITE);
 cprintf("EMPLOYEE PAY SLIP GENERATION");
 /* printing data entry box */
 window(15,6,65,15);
 textcolor(MAGENTA);
 printrect(1,1,50,7);
 /* Accepting data */
 textcolor(WHITE);
 gotoxy(17,2);
 cprintf("INPUT SCREEN");
 gotoxy(2,3);
 cprintf("Salary     :");cscanf("%d",&sal);
 gotoxy(2,4);
 cprintf("HRA Percent:");cscanf("%d",&p_hra);
 gotoxy(2,5);
 cprintf("DA Percent :");cscanf("%d",&p_da);
 getch();
 /* overlapping output window */
 window(18,9,68,18);
 clrscr();
 textcolor(BLUE);
 printrect(1,1,50,7);
 textcolor(WHITE);
 gotoxy(17,2);
 /* printing the output */
 cprintf("OUTPUT SCREEN");
 gotoxy(2,3);
 cprintf("Salary : %d",sal);
 gotoxy(2,4);
 hra=(float)sal*p_hra/100;
 cprintf("House Rent Allowence : %f",hra);
 gotoxy(2,5);
 da=(float)sal*p_da/100;
 cprintf("Dearness Allowences  : %f",da);
 gotoxy(2,6);
 gross=sal+hra+da;
 cprintf("Gross Salary         : %f",gross);
 getch();
 return 0;
}
/* function to print rectangle */
void printrect(int x1,int y1,int x2,int y2)
{
 int i;
 gotoxy(x1,y1);
 cprintf("%c",218); /* to print top-left corner */
 gotoxy(x2,y1);
 cprintf("%c",191); /* to print top-right corner */
 gotoxy(x1,y2);
 cprintf("%c",192); /* to print bottom-left corner */
 gotoxy(x2,y2);
 cprintf("%c",217); /* to print bottom-right corner */
 for(i=x1+1;i<x2;i++) /* printing top horizontal line */
 {
  gotoxy(i,y1);
  cprintf("%c",196);
 }
 for(i=x1+1;i<x2;i++) /* printing bottom horizontal line */
 {
  gotoxy(i,y2);
  cprintf("%c",196);
 }
 for(i=y1+1;i<y2;i++) /* printing left virtical line */
 {
  gotoxy(x1,i);
  cprintf("%c",179);
 }
 for(i=y1+1;i<y2;i++) /* printing right virtical line */
 {
  gotoxy(x2,i);
  cprintf("%c",179);
 }
}