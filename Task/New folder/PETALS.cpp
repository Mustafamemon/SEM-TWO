   /*visit us for more sources */
#include<cstring>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include<iostream>
#include<stdio.h>
#include<cstdlib>
/** Change the values below to suit your screen resolution.
	These values will probably suit most users.   ***/
#define MAXX 640
#define MAXY 480
using namespace std ;
/* Co-ordinate conversion functions, prototypes and declarations */
float screen_y(float, float, float);
float screen_y(float, float, float);
float P2Q_x(float, float);
float P2Q_y(float, float);
void drawline(int mx , int my,int dx,int dy ,int tx,int ty,int color,char *name){
	moveto(mx,my);
	setcolor(color);
	lineto(dx,dy);
	outtextxy(tx,ty,name);
}
float screen_x(float xb, float x, float xe)
{
	return ( (x - xb) / (xe - xb) * MAXX );
}
float screen_y(float yb, float y, float ye)
{
	return ((y - yb) / (ye - yb) * MAXY);
}
/***********************************************************/
/****** The 2 functions below convert a polar **************
*********************  point into a quadratic point ********/
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
	string ch ;
	char a[7],*b,*d;
	cout<<"ENTER THE FUNCTION : " ;
	getline(cin,ch,'\n');
	for (int i=0;i<=7;i++){
		a[i]=ch[i];
	}
	a[7]='\0';
	b=strtok(a," ");
	d=strtok(NULL," ");
	int c  ;
	c = (int)*d-48;
	/* Change the values of 'drv' and 'mode' if you change MAXX and MAXY */
	int drv = VGA , mode = VGAHI;
	float phi, r, xb, xe, yb, ye, x, y;
	/* You can play with the parameters below to determine the viewable
	   area of your graph */
	xb = -2;
	xe = 2;
	yb = -2;
	ye = 2;
	/* Stop playing !!! */
	initgraph(&drv, &mode, NULL);
	/* Draw the X and Y axes */
	setcolor(15);
	char *name ;
    name = new char ;
    strcpy(name,"X");
    drawline(0,MAXX/2.7,MAXY*MAXY,MAXX/2.7,MAXY-20,MAXX+10,WHITE,name);
    strcpy(name,"Y");
    drawline(MAXY/2.7,0,MAXX*MAXX,MAXY/2.7,MAXY/2+10,0,WHITE,name);
	//line( 0, screen_y(yb, 0, ye), MAXX, screen_y(yb, 0, ye) );
	line( screen_x(xb, 0, xe), 0, screen_x(xb, 0, xe), MAXY );
	moveto( screen_x(xb, 0, xe), screen_y(yb, 0, ye) );
	outtextxy(100,100,a);
	for(phi=0;phi<(2*3.1415);phi+=0.0001)
	{
		if ((strcmp(b,"sin"))==0)
		r = sin(c*phi) ;
		else if ((strcmp(b,"cos"))==0)
		r = cos(c*phi) ;
		else
		{
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
