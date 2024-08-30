#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void bresenhamCircle(int xcord, int ycord, int rad)
{
  //function to create circle using Bresenham algorithm
  int dec, x, y;
  dec = 3-2*rad; //dec is the decision parameter
  x = 0;
  y = rad; // set y equals to radius
  while (y>=x)
  {
    putpixel(xcord+x, ycord+y, 15); // bottom right
    putpixel(xcord+y, ycord+x, 15); //right side
    putpixel(xcord+y, ycord-x, 15); //right up
    putpixel(xcord+x, ycord-y, 15);
    putpixel(xcord-x, ycord-y, 15); // left top
    putpixel(xcord-y, ycord-x, 15); //left side
    putpixel(xcord-y, ycord+x, 15); //left bottom
    putpixel(xcord-x, ycord+y, 15); //bottom
    x++; //note: 15 is the color,insteadyou can also put WHITE, RED, GREEN, etc.
    
    if (dec>0)
    {
      //decision parameter
      y--;
      dec = dec+4*(x-y)+10;
    }
    else
     {
       dec = dec+4*x+6;
     }  //delay(10); // optional delay to watch the circle being made
    
  }
}

void ddaLine(float x1, float y1, float x2, float y2)
{
  //DDA line drawing algorithm (will be used for tria)
  float dx, dy, steps, xinc, yinc, x, y;
  dx = abs(x2-x1);
  dy = abs(y2-y1);
  
  if(dx>dy)
  {
    steps = dx;
  }
  else
  {
    steps = dy;
  }
  xinc = (x2-x1)/steps;
  yinc = (y2-y1)/steps;
  
  x = x1;
  y = y1;
  
  putpixel(round(x),round(y), 15);
  for (int i=0;i<steps;i++);
  {
    x = x+xinc;
    y = y+yinc;
    putpixel(round(x), round(y), 15);
    
  }
  
}

int main()
{
  float x1, y1, x2, y2, x3;
  int x, y, r;
  cout<<endl<<"Enter coordinates:";
  cout<<endl<<"Enter the value of X1:\t";
  cin>>x1;
  cout<<endl<<"Enter the value of Y1:\t";
  cin>>y1;
  cout<<endl<<"Enter the value of X2:\t";
  cin>>x2;
  x3 = (x2+x1)/2;
  y2 = y1-sqrt(pow((x2-x1), 2)-pow((x2-x1)/2, 2));
  int gd=DETECT, gm;
  initgraph(&gd, &gm, NULL);
  ddaLine(x1, y1, x2, y1);
  ddaLine(x2, y1, x3, y2);
  ddaLine(x3, y2, x1, y1);
  x = x3;
  y = y2+2*(y1-y2)/3;
  r = (y1-y2)/3;
  bresenhamCircle(x, y, r);
  r = 2*(y1-y2)/3;
  delay(50000);
  closegraph();
  
  return 0;
    
  
}
