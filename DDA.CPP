#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void calc_slope(int,int,int,int);
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

void main()
{
	clrscr();
	int x1,y1,x2,y2;
	cout<<"Enter x co-ordinate of first point: ";
	cin>>x1;
	cout<<"\nEnter y co-ordinate of first point: ";
	cin>>y1;
	cout<<"\nEnter x co-ordinate of second point: ";
	cin>>x2;
	cout<<"\nEnter y co-ordinate of second point: ";
	cin>>y2;

	int gdriver=DETECT, gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	calc_slope(x1,y1,x2,y2);

	getch();
	closegraph();
}

void calc_slope(int x1, int y1, int x2, int y2)
{
	drawAxis();
	float ydiff=y2-y1;
	float xdiff=x2-x1;
	float m=ydiff/xdiff;
	float xi=x1, yi=y1;
	if(m<=1&&(x1<x2))
	{
		do
		{
			putPixel(ceil(xi),ceil(yi),YELLOW);
			xi+=1;
			yi=yi+m;
		}while(xi<=x2&&yi<=y2);
	}
	else if(m<=1&&(x1>x2))
	{
		do
		{
			putPixel(ceil(xi),ceil(yi),YELLOW);
			xi-=1;
			yi=yi-m;
		}while(xi>=x2&&yi>=y2);
	}
	else if(m>1&&(x1<x2))
	{
		do
		{
			putPixel(ceil(xi),ceil(yi),YELLOW);
			xi=xi+(1/m);
			yi=yi+1;
		}while(xi<=x2&&yi<=y2);
	}
	else
	{
		do
		{
			putPixel(ceil(xi),ceil(yi),YELLOW);
			xi=xi-(1/m);
			yi=yi-1;
		}while(xi>=x2&&yi>=y2);
	}
}

