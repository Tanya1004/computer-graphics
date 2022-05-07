#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void drawAxis()
{
	int maxx=getmaxx();
	int maxy=getmaxy();
	int maxx_2=maxx/2;
	int maxy_2=maxy/2;
	line(0,maxy_2,maxx,maxy_2);
	line(maxx_2,0,maxx_2,maxy);
}

void putPixel(int x,int y,int color)
{
	int maxx_2=getmaxx()/2;
	int maxy_2=getmaxy()/2;
	putpixel(x+maxx_2,maxy_2-y,color);
}

void calc_d(int x0, int y0, int x1, int y1)
{
	int dy, dx, dnew, a, b, dold;
	dy=y1-y0;
	dx=x1-x0;
	a=2*dy;
	b=-2*dx;
	dold=(2*dy)-dx;
	do
	{       putPixel(x0,y0,RED);
		if(dold>0)
		{
			x0++;
			y0++;
			dnew=dold+a+b;
			putPixel(x0,y0,RED);
		}
		else if(dold<0)
		{
			x0++;
			dnew=dold+a;
			putPixel(x0,y0,RED);
		}
		else
		{
			x0++;
			dnew=dold+a;
			putPixel(x0,y0,RED);
		}
		dold=dnew;
	}while((x0<x1)&&(y0<y1));
}

void main()
{
	clrscr();
	int x0, y0, x1, y1;
	cout<<"\nEnter x co-ordinate of first point: ";
	cin>>x0;
	cout<<"\nEnter y co-ordinate of first point: ";
	cin>>y0;
	cout<<"\nEnter x co-ordinate of second point: ";
	cin>>x1;
	cout<<"\nEnter y co-ordinate of second point: ";
	cin>>y1;
	clrscr();
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
	drawAxis();
	calc_d(x0,y0,x1,y1);
	getch();
}
