#include<graphics.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
void ffill(int x,int y,int o_col,int n_col)
{
  int current = getpixel(x,y);
  if(current==o_col)
  {
    delay(1);
    putpixel(x, y, n_col);
    ffill(x+1, y,o_col, n_col);
    ffill(x-1, y,o_col, n_col);
    ffill(x, y+1,o_col, n_col);
    ffill(x, y-1,o_col, n_col);
  }
  
}
int main()
{
int x1, y1, x2, y2, x3, y3, x4, y4, xavg, yavg;
cout<< " \n\t Enter the points of triangle (x1 y1 x2 y2 x3 y3):";
cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 ;
xavg = (x1 +x2 +x3 +x4)/ 4;
yavg = (y1 +y2 +y3 +y4)/ 4;    
int gd = DETECT,gm;
initgraph(&gd, &gm,NULL);
setcolor(1); //color index 1
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x4,y4);
line(x4,y4,x1,y1);
// assuming BLACK and RED are predefined color constants in graphics.h
ffill(xavg, yavg, BLACK, RED);
getch();
closegraph();
return 0;
}
