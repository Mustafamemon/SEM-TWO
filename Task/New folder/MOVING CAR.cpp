/*#include<stdio.h>
#include<dos.h>
#include<windows.h>
#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std ;
const int height= 600 ;
const int width = 800 ;
int w = width ;
int h = height ;
void drawline(int mx , int my,int dx,int dy ,int tx,int ty,int color,char *name){
	moveto(mx,my);
	setcolor(color);
	lineto(dx,dy);
	outtextxy(tx,ty,name);
}
int main()
{
	initwindow(height,width);
    char *name ;
    name = new char[30] ;
    strcpy(name,"MADE BY MUSTAFA");
    float j=5.0 ;
    while (true){
    	j=5.0 ;
		for (int i=1;i<19;i++){
    	drawline(0,(height+i),width,(height+i),width-40,height+10,GREEN,name);
		setcolor(RED);
		rectangle((w/6)-80-i+j,h-60-i+j,(w/6)+80+i-j,(h)-30+i-j);
		setcolor(YELLOW);
		circle(((w/3)+55)/2,(h-9),j);
		circle(((w/3)-55)/2,(h-9),j);
		j=j+0.2 ;
		}
		delay(5);
		cleardevice();
    	if (GetAsyncKeyState(VK_LEFT)){	
    		if (w>560)
			w-=10 ;
		}
		if (GetAsyncKeyState(VK_RIGHT)){	
			w+=10 ;
		}
		if (GetAsyncKeyState(VK_UP)){	
			if (h>70)
			h-=10 ;
		}
		if (GetAsyncKeyState(VK_DOWN)){	
			if (h<=590)
			h+=10 ;
		}
		if (w==(4600)){
			strcpy(name,"GAME OVER");
			outtextxy((height/2),(width/2),name);
			system("pause");
			return 0 ;
		}
	}
    return 0 ;
}*/
