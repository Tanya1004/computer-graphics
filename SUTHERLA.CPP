#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void drawAxis()
{
	int maxx=getmaxx();
	int maxy=getmaxy();
	int maxx_2=maxx/2;
	int maxy_2=maxy/2;
	line(maxx_2,0,maxx_2,maxy);
	line(0,maxy_2,maxx,maxy_2);
}

void top(int &x, int &y, int ym, float m)
{
	int newx=x-((y-ym)/m);
	x=newx;
	y=ym;
}

void bottom(int &x, int &y, int ym, float m)
{
	int newx=((ym-y)/m)+x;
	x=newx;
	y=ym;
}

void right(int &x, int &y, int xm, float m)
{
	int newy=y-m*(x-xm);
	x=xm;
	y=newy;
}

void left(int &x, int &y, int xm, float m)
{
	int newy=m*(xm-x)+y;
	x=xm;
	y=newy;
}

int reject(int c1[4], int c2[4])
{
	for(int i=0; i<4; ++i)
	{
		if(c1[i]==1&&c2[i]==1)
			return 1;
	}
	return 0;
}

int accept(int c1[4], int c2[4])
{
	for(int i=0; i<4; ++i)
	{
		if(c1[i]==1||c2[i]==1)
			return 0;
	}
	return 1;
}

void showcode(int c1[4])
{
	for(int i=0; i<4; ++i)
		cout<<c1[i];
}

void createcode(int code1[4], int code2[4], int x1, int y1, int x2, int y2, int xmax, int ymax, int xmin, int ymin)
{
	if(ymax-y1>0)
		code1[0]=0;
	else
		code1[0]=1;

	if(y1-ymin>0)
		code1[1]=0;
	else
		code1[1]=1;

	if(xmax-x1>0)
		code1[2]=0;
	else
		code1[2]=1;

	if(x1-xmin>0)
		code1[3]=0;
	else
		code1[3]=1;

	if(ymax-y2>0)
		code2[0]=0;
	else
		code2[0]=1;

	if(y2-ymin>0)
		code2[1]=0;
	else
		code2[1]=1;

	if(xmax-x2>0)
		code2[2]=0;
	else
		code2[2]=1;

	if(x2-xmin>0)
		code2[3]=0;
	else
		code2[3]=1;
	cout<<"\nCODE 1 : "; showcode(code1);
	cout<<"\nCODE 2 : "; showcode(code2);
}

void clipline(int xmin, int xmax, int ymin, int ymax, int x1, int y1, int x2, int y2)
{
	int code1[4], code2[4];
	int rej,acc;
	createcode(code1,code2,x1,y1,x2,y2,xmax,ymax,xmin,ymin);
	if(accept(code1,code2)==1)
	{
		cout<<"\nTrivially accepted line\n";
		return;
	}

	if(reject(code1,code2)==1)
	{
		cout<<"\nTrivially rejected line\n";
		return;
	}

	//do
	//{
		float m=(float)(y2-y1)/(x2-x1);
		cout<<"\nslope="<<m;
		if(y1>y2)
		{
			if(y1>ymax)
			{
				top(x1,y1,ymax,m);
				cout<<"\nTop intersection: ("<<x1<<", "<<y1<<")\n";
			}
		}
		else if(y2>ymax)
		{
			top(x2,y2,ymax,m);
			cout<<"\nTop intersection: ("<<x2<<", "<<y2<<")\n";
		}

		if(y1<y2)
		{
			if(y1<ymin)
			{
				bottom(x1,y1,ymin,m);
				cout<<"\nBottom intersection: ("<<x1<<", "<<y1<<")\n";
			}
		}
		else if(y2<ymin)
		{
			bottom(x2,y2,ymin,m);
			cout<<"\nBottom intersection: ("<<x2<<", "<<y2<<")\n";
		}

		if(x1>x2)
		{
			if(x1>xmax)
			{
				right(x1,y1,xmax,m);
				cout<<"\nRight intersection: ("<<x1<<", "<<y1<<")\n";
			}
		}
		else if(x2>xmax)
		{
			right(x2,y2,xmax,m);
			cout<<"\nRight intersection: ("<<x2<<", "<<y2<<")\n";
		}

		if(x1<x2)
		{
			if(x1<xmin)
			{
				left(x1,y1,xmin,m);
				cout<<"\nLeft intersection: ("<<x1<<", "<<y1<<")\n";
			}
		}
		else if(x2<xmin)
		{
			left(x2,y2,xmin,m);
			cout<<"\nLeft intersection: ("<<x2<<", "<<y2<<")\n";
		}

	      createcode(code1,code2,x1,y1,x2,y2,xmax,ymax,xmin,ymin);

	      acc=accept(code1,code2);
	      rej=reject(code1,code2);
	      delay(5000);
	      clrscr();
	      drawAxis();
	      cout<<"\nAcc :"<<acc;
	      cout<<"\nRej :"<<rej;
	      cout<<"\nFinal endpoints :\n";
	      cout<<"\n(x1,y1): "<<x1<<", "<<y1;
	      cout<<"\n(x2,y2): "<<x2<<", "<<y2;
	     int maxx=getmaxx()/2;
	     int maxy=getmaxy()/2;
	     line(xmax+maxx, maxy-ymin, xmax+maxx, maxy-ymax);
	     line(xmin+maxx, maxy-ymin, xmin+maxx, maxy-ymax);
	     line(xmax+maxx, maxy-ymax, xmin+maxx, maxy-ymax);
	     line(xmax+maxx, maxy-ymin, xmin+maxx, maxy-ymin);

	     line(x1+maxx, maxy-y1, x2+maxx, maxy-y2);
	//}while(acc==0 && rej==0);
}

void main()
{
	int xmin, xmax, ymin, ymax, x1, y1, x2, y2;

	cout<<"\nEnter lower boundary of clip rectangle : ymin :";
	cin>>ymin;

	cout<<"\nEnter upper boundary of clip rectangle : ymax :";
	cin>>ymax;

	cout<<"\nEnter right boundary of clip rectangle : xmax :";
	cin>>xmax;

	cout<<"\nEnter left boundary of clip rectangle : xmin :";
	cin>>xmin;

	cout<<"\nEnter line coordinates : \n";
	cout<<"\nx1 : "; cin>>x1;
	cout<<"\ny1 : "; cin>>y1;
	cout<<"\nx2 : "; cin>>x2;
	cout<<"\ny2 : "; cin>>y2;

	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "C://TC//BGI");
	drawAxis();
	int maxx=getmaxx()/2;
	int maxy=getmaxy()/2;
	line(xmax+maxx, maxy-ymin, xmax+maxx, maxy-ymax);
	line(xmin+maxx, maxy-ymin, xmin+maxx, maxy-ymax);
	line(xmax+maxx, maxy-ymax, xmin+maxx, maxy-ymax);
	line(xmax+maxx, maxy-ymin, xmin+maxx, maxy-ymin);
	line(x1+maxx, maxy-y1, x2+maxx, maxy-y2);

	clipline(xmin, xmax, ymin, ymax, x1, y1, x2, y2);
	getch();
	closegraph();
}