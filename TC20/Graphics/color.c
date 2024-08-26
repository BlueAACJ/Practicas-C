#include<stdio.h>
#include<conio.h>
#include <graphics.h>
int main()
{
  int gd = DETECT, gm, c , x = 100, y = 50;

  initgraph(&gd, &gm, "C:\\TC20\\BIN");

  for (c = 0; c < 5; c++)
  {
	setlinestyle(c, 0, 0);

    line(x, y, x+200, y);
    y = y + 25;
  }

  getch();
  closegraph();
  return 0;
}