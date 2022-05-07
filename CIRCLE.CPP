#include<iostream.h>
#include<graphics.h>
#include<conio.h>

void putPixel(int x, int y, int color)
{
	int maxx_2=getmaxx()/2;
	int maxy_2=getmaxy()/2;
	putpixel(x+maxx_2, maxy_2-y, color);
}

void drawAxis()
{
	int maxx=getmaxx();
	int maxy=getmaxy();
	int maxx_2=maxx/2;
	int maxy_2=maxy/2;
	line(maxx_2,0,maxx_2,maxy);
	line(0,maxy_2,maxx,maxy_2);
}

void circlePlotPoints(int xcenter, int ycenter,int x, int y)
{
	putPixel(xcenter+x, ycenter+y, YELLOW);
	putPixel(xcenter-x, ycenter+y, YELLOW);
	putPixel(xcenter+x, ycenter-y, YELLOW);
	putPixel(xcenter-x, ycenter-y, YELLOW);
	putPixel(xcenter+y, ycenter+x, YELLOW);
	putPixel(xcenter-y, ycenter+x, YELLOW);
	putPixel(xcenter+y, ycenter-x, YELLOW);
	putPixel(xcenter-y, ycenter-x, YELLOW);
}

void circleMidPoint(int xcen, int ycen, int rad)
{
	int x=0;
	int y=rad;
	int p=1-rad;
	circlePlotPoints(xcen, ycen, x, y);

	while(x<y)
	{
		x++;
		if(p<0)
			p+=2*x+1;
		else
		{
			y--;
			p+=2*(x-y)+1;
		}
		circlePlotPoints(xcen, ycen, x, y);
	}
}

void main()
{
	int xc,yc,r;
	cout<<"\nEnter x center : ";
	cin>>xc;
	cout<<"\nEnter y center : ";
	cin>>yc;
	cout<<"\nEnter radius of circle : ";
	cin>>r;
	clrscr();
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
	drawAxis();
	circleMidPoint(xc, yc, r);
	getch();
	closegraph();
}