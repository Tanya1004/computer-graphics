#include<iostream.h>
#include<process.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
int x[10][3], coord,i,j, new_x[10][3];
void drawAxis()
{
	int maxx=getmaxx();
	int maxy=getmaxy();
	int maxx_2=maxx/2;
	int maxy_2=maxy/2;
	line(maxx_2,0,maxx_2,maxy);
	line(0,maxy_2,maxx,maxy_2);
}

void input()
{
	clrscr();
	cout<<"\nEnter number of co-ordinates(less than 10): ";
	cin>>coord;
	if(i>10)
	{
		cout<<"\nInvalid number";
	}
	else
	{
		for(i=0; i<coord; i++)
		{
			cout<<"\nCo-ordinates of "<<i+1<<" point: ";
			cout<<"\nEnter x co-ordinate: ";
			cin>>x[i][0];
			cout<<"\nEnter y co-ordinates: ";
			cin>>x[i][1];
			x[i][2]=1;
		}
	}
}
void draw()
{
	int gdrive=DETECT, gmode;
	initgraph(&gdrive, &gmode,"C:\\TC\\BGI");
	drawAxis();
	int xx=getmaxx()/2;
	int yy=getmaxy()/2;
	for(i=0; i<coord; i++)
	{
		if(i+1==coord)
		{
			setcolor(YELLOW);
			line(ceil(x[0][0]+xx), ceil(yy-x[0][1]), ceil(x[coord-1][0]+xx), ceil(yy-x[coord-1][1]));
		}
		else
		{
			setcolor(YELLOW);
			line(ceil(x[i][0]+xx), ceil(yy-x[i][1]), ceil(x[i+1][0]+xx), ceil(yy-x[i+1][1]));
		}
	}
	for(i=0; i<coord; i++)
	{
		if(i+1==coord)
		{
			setcolor(RED);
			line(ceil(new_x[0][0]+xx), ceil(yy-new_x[0][1]), ceil(new_x[coord-1][0]+xx), ceil(yy-new_x[coord-1][1]));
		}
		else
		{
			setcolor(RED);
			line(ceil(new_x[i][0]+xx), ceil(yy-new_x[i][1]), ceil(new_x[i+1][0]+xx), ceil(yy-new_x[i+1][1]));
		}
	}

	getch();
	closegraph();
}
void multiply(float arr[3][3])
{
	for(i=0; i<coord; i++)
	{
		for(j=0; j<3; j++)
		{
			new_x[i][j]=0;
		}
	}

	for(i=0; i<coord; i++)
	{
		for(j=0; j<3; j++)
		{
			for(int k=0; k<3; k++)
			{
				new_x[i][j]+=x[i][k]*arr[k][j];
			}
		}
	}
	cout<<"\nNEW MATRIX";
	for(i=0;i<coord; i++)
	{
		for(j=0; j<3; j++)
		{
			cout<<new_x[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void rotation()
{
	float R[3][3];
	int direction;
	double angle;
	cout<<"\n1. Clockwise";
	cout<<"\n2. Counterclocwise";
	cout<<"\nChoose direction: ";
	cin>>direction;
	cout<<"\nEnter angle: ";
	cin>>angle;
	if(direction==1)
	{
		R[0][0]=cos(angle*(M_PI/180));
		R[0][1]=(-1)*sin(angle*(M_PI/180));
		R[0][2]=0;
		R[1][0]=sin(angle*(M_PI/180));
		R[1][1]=cos(angle*(M_PI/180));
		R[1][2]=0;
		R[2][0]=0;
		R[2][1]=0;
		R[2][2]=1;
	}
	else
	{
		R[0][0]=cos(angle*(3.14159/180));
		R[0][1]=sin(angle*(3.14159/180));
		R[0][2]=0;
		R[1][0]=(-1)*sin(angle*(3.14159/180));
		R[1][1]=cos(angle*(3.14159/180));
		R[1][2]=0;
		R[2][0]=0;
		R[2][1]=0;
		R[2][2]=1;
	}
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			cout<<R[i][j]<<"\t";
		}
		cout<<"\n";
	}

	multiply(R);

}
void reflection()
{
	float refl[3][3];
	int option;
	cout<<"\n1. Reflection through x-axis(y=0)";
	cout<<"\n2. Reflection through y-axis(x=0)";
	cout<<"\n3. Reflection about the line y=x";
	cout<<"\n4. Reflection about the line y=-x";
	cout<<"\nEnter your choice: ";
	cin>>option;
	if(option==1)
	{
		refl[0][0]=1;
		refl[0][1]=0;
		refl[0][2]=0;
		refl[1][0]=0;
		refl[1][1]=-1;
		refl[1][2]=0;
		refl[2][0]=0;
		refl[2][1]=0;
		refl[2][2]=1;
	}
	else if(option==2)
	{
		refl[0][0]=-1;
		refl[0][1]=0;
		refl[0][2]=0;
		refl[1][0]=0;
		refl[1][1]=1;
		refl[1][2]=0;
		refl[2][0]=0;
		refl[2][1]=0;
		refl[2][2]=1;
	}
	else if(option==3)
	{
		refl[0][0]=0;
		refl[0][1]=1;
		refl[0][2]=0;
		refl[1][0]=1;
		refl[1][1]=0;
		refl[1][2]=0;
		refl[2][0]=0;
		refl[2][1]=0;
		refl[2][2]=1;
	}
	else if(option==4)
	{
		refl[0][0]=0;
		refl[0][1]=-1;
		refl[0][2]=0;
		refl[1][0]=-1;
		refl[1][1]=0;
		refl[1][2]=0;
		refl[2][0]=0;
		refl[2][1]=0;
		refl[2][2]=1;
	}
	multiply(refl);
}
void shearing()
{
	float shear[3][3];
	int option, xshear, yshear;
	cout<<"\n1. Shearing in x axis";
	cout<<"\n2. Shearing in y axis";
	cout<<"\nEnter your choice: ";
	cin>>option;
	if(option==1)
	{
		cout<<"\nEnter factor: ";
		cin>>xshear;
		shear[0][0]=1;
		shear[0][1]=0;
		shear[0][2]=0;
		shear[1][0]=xshear;
		shear[1][1]=1;
		shear[1][2]=0;
		shear[2][0]=0;
		shear[2][1]=0;
		shear[2][2]=1;
	}
	else if(option==2)
	{
		cout<<"\nEnter factor: ";
		cin>>yshear;
		shear[0][0]=1;
		shear[0][1]=yshear;
		shear[0][2]=0;
		shear[1][0]=0;
		shear[1][1]=1;
		shear[1][2]=0;
		shear[2][0]=0;
		shear[2][1]=0;
		shear[2][2]=1;
	}
	multiply(shear);
}
void scaling()
{
	float scal[3][3];
	int direction;
	float factor, xfactor, yfactor;
	cout<<"\n1. Local Scaling";
	cout<<"\n2. Overall Scaling";
	cout<<"\nEnter your choice: ";
	cin>>direction;
	if(direction==1)
	{
		cout<<"\nEnter x scaling factor: ";
		cin>>xfactor;
		cout<<"\nEnter y scaling factor: ";
		cin>>yfactor;
		scal[0][0]=xfactor;
		scal[0][1]=0;
		scal[0][2]=0;
		scal[1][0]=0;
		scal[1][1]=yfactor;
		scal[1][2]=0;
		scal[2][0]=0;
		scal[2][1]=0;
		scal[2][2]=1;
	}
	else if(direction==2)
	{
		cout<<"\nEnter overall scaling factor: ";
		cin>>factor;
		scal[0][0]=1;
		scal[0][1]=0;
		scal[0][2]=0;
		scal[1][0]=0;
		scal[1][1]=1;
		scal[1][2]=0;
		scal[2][0]=0;
		scal[2][1]=0;
		scal[2][2]=factor;
	}
	multiply(scal);
}
void translation()
{
	float trans[3][3];

	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(i==2 && j==0)
			{
				cout<<"\nEnter x translation factor: ";
				cin>>trans[i][j];
			}
			else if(i==2 && j==1)
			{
				cout<<"\nEnter y translation factor: ";
				cin>>trans[i][j];
			}
			else if(i==j)
			{
				trans[i][j]=1;
			}
			else
				trans[i][j]=0;
		}
	}

	multiply(trans);
}
void main()
{
	clrscr();
	int choice;
	do
	{
		cout<<"\n\t\t\t\t\tMENU";
		cout<<"\n1. Translation";
		cout<<"\n2. Rotation";
		cout<<"\n3. Scaling";
		cout<<"\n4. Reflection";
		cout<<"\n5. Shearing";
		cout<<"\n6. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case(1):{	input();
					translation();
					draw();
					break;
				}
			case(2):{       input();
					rotation();
					draw();
					break;
				}
			case(3):{       input();
					scaling();
					draw();
					break;
				}
			case(4):{       input();
					reflection();
					draw();
					break; }
			case(5):{       input();
					shearing();
					draw();
					break;
				}
			case(6):{ exit(0); }
			default:{ cout<<"\nInvalid input\nEnter again"; }
		}
	}while(choice!=6);
	getch();
}
