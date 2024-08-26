#include<stdio.h>
#include<conio.h>
void manip();
void biggest();
void factorial();
int menu(int);
int main()
{
  int x=menu(1);
  while(1)
  {
    window(20,12,50,20);
    if(x==1)
      manip();
    else if(x==2)
      biggest();
    else if(x==3)
      factorial();
    else if(x==4)
      goto out;
    x=menu(x);
}
out:
return 0;
}
int menu(int in) /* prints menu and returns selected item number*/
{
 int i;
 char temp,ch;
 char items[4][20]={" Manip            ",
                    " Biggest          ",
                    " Factorial        ",
                    " Exit             "};
 window(20,5,50,10);
 while(1)
 {
   for(i=1;i<=4;i++)
   {
      if(i==in)
      {
        textcolor(BLACK);
        textbackground(WHITE);
      }
      else
      {
        textcolor(WHITE);
        textbackground(BLACK);
   }
  gotoxy(1,i);
  cprintf("%s",items[i-1]);
 }
 ch=getch();
 if(ch==0)
   ch=getch();
 switch(ch)
 {
   case 72:  /* selecting up arrow */
     if(in>1)
       in--;
     break;
   case 80:  /* selecting down arrow */
     if(in<4)
       in++;
     break;
   case 13:
     return in;
  }
 }
}
void manip()
{
  int x,y;
  clrscr();
  textcolor(WHITE);
  textbackground(BLACK);
  gotoxy(1,1);
  cprintf("First number:\n\r");
  scanf("%d",&x);
  gotoxy(1,3);
  cprintf("Second number:\n\r");
  scanf("%d",&y);
  gotoxy(1,5);
  cprintf("Sum %d",(x+y));
  gotoxy(1,6);
  cprintf("Substraction %d",x-y);
  gotoxy(1,7);
  cprintf("Product %d",x*y);
  gotoxy(1,8);
  cprintf("Division %f",(float)x/y);
}
void biggest()
{
 int x,y;
 clrscr();
 textcolor(WHITE);
 textbackground(BLACK);
 gotoxy(1,1);
 cprintf("First number:\n\r");
 scanf("%d",&x);
 gotoxy(1,3);
 cprintf("Second number:\n\r");
 scanf("%d",&y);
 gotoxy(1,5);
 if(x==y)
   cprintf("Equals");
 else if(x>y)
   cprintf("Biggest number %d",x);
 else if(x<y)
   cprintf("Biggest number %d",y);
}
void factorial()
{
 int n,i,fact;
 clrscr();
 textcolor(WHITE);
 textbackground(BLACK);
 gotoxy(1,1);
 cprintf("Enter any integer:\n\r");
 scanf("%d",&n);
 for(fact=i=1;i<n;i++)
    fact=fact*i;
 gotoxy(1,3);
 cprintf("Factorial %d",fact);
}