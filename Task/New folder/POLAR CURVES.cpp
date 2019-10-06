#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include <conio.h>
#include <graphics.h>
#include<cstring>
#include <math.h>
#include<iomanip>
#include<cwchar>
const int MAXX = 640 ;
const int MAXY = 480 ;
using namespace std ;
class Fun{
public :
	int a , b , d  ;
	char c[4] , e ;
	friend void operator >>(istream&,Fun&) ;
};
void operator >>(istream &input,Fun &f ){
	input>>setw(1)>>f.a ;
	input.ignore();
	input>>setw(1)>>f.e ;
	input.ignore();
	input>>setw(1)>>f.b ;
	input.ignore();
	input>>setw(4)>>f.c ;
	input.ignore();
	input>>setw(1)>>f.d ;
}
float screen_x(float xb, float x, float xe)
{
	return ( (x - xb) / (xe - xb) * MAXX );
}
float screen_y(float yb, float y, float ye)
{
	return (MAXY - (y - yb) / (ye - yb) * MAXY);
}
float P2Q_x(float r, float phi)
{
	return r * cos(phi);
}
float P2Q_y(float r, float phi)
{
	return r * sin(phi);
}
int main()
{
	Fun f ;
	cout<<"ENTER THE FUNCTION (a + b sin 3 x) : " ;
	cin>>f ;
	char g[12] ,p[]={"POLAR CURVE "};
	g[0]='r' ;
	g[1]='=' ;
	g[2]=(char)(f.a+48) ;
	g[3]=f.e ;
	g[4]=(char)(f.b+48) ;
	g[5]=f.c[0] ;
	g[6]=f.c[1] ;
	g[7]=f.c[2] ;
	g[8]=' ' ;
	g[9]=(char)(f.d+48);
	g[10]='x' ; 
	int drv = VGA , mode = VGAHI;
	float phi, r, xb, xe, yb, ye, x, y;
	xb = -10;
	xe = 10;
	yb = -10;
	ye = 10;
	initgraph(&drv, &mode, NULL);
	setcolor(15);
	line( 0, screen_y(yb, 0, ye), MAXX, screen_y(yb, 0, ye) );
	line( screen_x(xb, 0, xe), 0, screen_x(xb, 0, xe), MAXY );
	moveto( screen_x(xb, 0, xe), screen_y(yb, 0, ye) );
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	setcolor(RED) ;
	outtextxy(50,30,p);
	setcolor(YELLOW) ;
	outtextxy(70,50,g);
	for(phi=0;phi<(2*3.1415);phi+=0.0001)
	{
		if ((strcmp(f.c,"sin"))==0){
			if (f.e=='+')
				r = f.a+(f.b*sin(f.d*phi)) ;
			else if (f.e=='-')
				r = f.a-(f.b*sin(f.d*phi)) ;
			else{
				cout<<"INVALID SIGN" ;
				exit(0);
			}
		}
		else if ((strcmp(f.c,"cos"))==0){
			if (f.e=='+')
				r = f.a+(f.b*cos(f.d*phi)) ;
			else if (f.e=='-')
				r = f.a-(f.b*cos(f.d*phi)) ;
			else{
				cout<<"INVALID SIGN" ;
				exit(0);
			}
		}
		else{
			cout<<"INVALID INPUT" ;
			exit(0);
		}
	x = P2Q_x(r, phi);
	y = P2Q_y(r, phi);
	putpixel(screen_x(xb, x, xe),screen_y(yb, y, ye),BLUE);
	}
	getche();
	closegraph();
	return 0;
}
