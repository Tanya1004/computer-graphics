#include<iostream.h>
#include<conio.h>
#include<graphics.h>

struct point{
	int x,y;
};

void drawCurve(point arr[4],int xmid,int ymid){
	clrscr();
	float t, c1, c2, c3, c4, x, y;

	line(xmid,0,xmid,2*ymid);
	line(0,ymid,2*xmid,ymid);

	for(t=0.0;t<=1;t+=0.00001){
		float t1 = t*t, t2 = t1*t;

		c1 = 2*t2-3*t1+1;
		c2 = -2*t2+3*t1;
		c3 = t2-2*t1+t;
		c4 = t2-t1;

		x = c1*arr[0].x + c2*arr[1].x + c3*arr[2].x + c4*arr[3].x;
		y = c1*arr[0].y + c2*arr[1].y + c3*arr[2].y + c4*arr[3].y;

		putpixel((int)x+xmid, ymid-(int)y, RED);
	}
	putpixel(xmid+arr[0].x, ymid-arr[0].y, RED);
	putpixel(xmid+arr[1].x, ymid-arr[1].y, RED);
}


int main(){
	int gdriver=DETECT,gmode,i;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

	point arr[4];

	for(i=0;i<4;i++){

		if(i<2){
			cout<<"\n Point "<<i+1<<" : ";
		}
		else{
			cout<<"\n Derivative at point "<<i+1<<" : ";
		}

		cout<<"\n X component: ";
		cin>>arr[i].x;
		cout<<"\n Y component: ";
		cin>>arr[i].y;
	}

	int xmid = getmaxx()/2, ymid=getmaxy()/2;
	drawCurve(arr,xmid,ymid);

	getch();
	closegraph();
	return 0;
}