#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include <conio.h>
#include <graphics.h>
#include<cstring>
#include <math.h>
#include<iomanip>
const int MAXX = 600 ;
const int MAXY = 600 ;
using namespace std ;
class Fun{
public :
	int a , b , d  ;
	char c[4] , e ;
	friend void operator >>(istream&,Fun&) ;
};
void operator >>(istream &input,Fun &f ){
	input>>setw(1)>>f.a ;
	input>>setw(1)>>f.e ;
	input>>setw(1)>>f.b ;
	input>>setw(4)>>f.c ;
	input.ignore();
	input>>setw(1)>>f.d ;
}
float screen_x(float xb, float x, float xe){
	return ( (x - xb) / (xe - xb) * MAXX );
}
float screen_y(float yb, float y, float ye){
	return (MAXY-(y - yb) / (ye - yb) * MAXY);
}
float P2Q_x(float r, float phi){
	return r * cos(phi);
}
float P2Q_y(float r, float phi){
	return r * sin(phi);
}
int main()
{
	int drv = VGA , mode = VGAHI;
	float phi, r, xb, xe, yb, ye, x, y ,q;
	char g[14] ,p[15],t[20],l='0';
	strcpy(p,"POLAR CURVE");
	Fun f ;
	cout<<"ENTER THE FUNCTION (a+bsin(cx)) : " ;
	cin>>f ;
	g[0]='r' ;	
	g[1]='=' ; 
	if (f.a>0){
		g[2]=' ' ;
		g[3]=(char)(f.a+48) ;
		g[4]=f.e ;
	}
	else if (f.a<0){
		g[2]='-' ;
		g[3]=(char)(f.a+48)+(f.a*-2);
		g[4]=f.e ;
	}
	else{
		g[2]=' ' ;
		g[3]= ' ' ;
		if (f.e=='+')
		g[4]=' ' ;
		else
		g[4]=f.e;
	}
	if (f.b!=0){
		g[5]=(char)(f.b+48) ;
		g[6]=f.c[0] ;
		g[7]=f.c[1] ;
		g[8]=f.c[2] ;
		g[9]='(' ;
		g[10]=(char)(f.d+48);
		g[11]='x' ; 
		g[12]=')' ;
		g[13]='\0' ;
	}
	else{
		g[4]='\0' ;
	}
	if (f.a==0&&f.b==0&&f.c!=0){
		g[2]=f.d ;
		g[3]='(' ;
		g[4]=(char)(f.d+48);
		g[5]='x' ; 
		g[6]=')' ;
		g[7]='\0' ;
	}
	initgraph(&drv, &mode, NULL);
	q=1+((f.a+f.b)/5);
	if(f.a==0&&f.b==0){
		if (f.d>1)
		q=(1+f.d/2) ;
		else
		q=1 ;
	}
	xb =-7*q;
	xe = 7*q;
	yb =-7*q;
	ye = 7*q;
	fflush(stdin) ;
	for (int i=0;i<=90*5;i+=(90/q)){
		if (l<='9'){
		if(l!='0'){
		outtextxy((MAXX+i-15)/2,(MAXY-100)/2,&l);
		outtextxy((MAXX)/2,(MAXY+i-100-15)/2,&l);
		}
		outtextxy((MAXX)/2,(MAXY-i-100)/2,&l);
		outtextxy((MAXX-i)/2,(MAXY-100)/2,&l);
		l++ ;
		}
	}
	settextstyle(BOLD_FONT,HORIZ_DIR,3);
	setcolor(RED) ;
	outtextxy(0,5,p);
	setcolor(WHITE);
	line( 0, (screen_y(yb, 0, ye)-50), MAXX, (screen_y(yb, 0, ye)-50) );
	line( screen_x(xb, 0, xe), 0, screen_x(xb, 0, xe), MAXY );
	line((MAXX-MAXX+110),(MAXY-MAXY+140),(MAXX-110),(MAXY-235));
	line((MAXX-MAXX+110),(MAXY-235),(MAXX-110),(MAXY-MAXY+140));
	line((MAXX-MAXX+190),(MAXY-MAXY+55),(MAXX-185),(MAXY-150));
	line((MAXX-MAXX+190),(MAXY-150),(MAXX-185),(MAXY-MAXY+55));
	circle(MAXX/2,(MAXY-100)/2,230);
	circle(MAXX/2,(MAXY-100)/2,200);
	circle(MAXX/2,(MAXY-100)/2,170);
	circle(MAXX/2,(MAXY-100)/2,140);
	circle(MAXX/2,(MAXY-100)/2,110);
	circle(MAXX/2,(MAXY-100)/2,80);
	circle(MAXX/2,(MAXY-100)/2,50);
	circle(MAXX/2,(MAXY-100)/2,30);
	if(f.d!=1&&f.b!=0)
	strcpy(t,"PETALS");
	else if (f.a==0&&f.b==0)
	strcpy(t,"SPIRAL") ;
	else if (f.a==0||f.b==0)
	strcpy(t,"CIRCLE") ;
	else if(f.a==f.b||((f.a*-1)==f.b))
	strcpy(t,"CARDIOD LEMICONS") ;
	else if (f.a<f.b)
	strcpy(t,"INNER-LOOP LEMICONS") ;
	else if (f.a>f.b)
	strcpy(t,"DIMPLE-LEMICONS") ;
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	setcolor(YELLOW) ;
	outtextxy(20,30,g);
	setcolor(GREEN);
	outtextxy(420,450,t);
	moveto( screen_x(xb, 0, xe), screen_y(yb, 0, ye) );
	for(phi=0;phi<=(2*3.141592654);phi+=0.00001){
		if(f.a==0&&f.b==0){
			r=f.d*phi/q ;
		}
		else if ((strcmp(f.c,"sin"))==0){
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
		putpixel(screen_x(xb, x, xe),(screen_y(yb, y, ye)-50),RED);
	}
	getche();
	closegraph();
	return 0;
}
