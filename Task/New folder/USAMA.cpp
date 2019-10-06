#include<graphics.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<math.h>
#include<cstdlib>
#include<windows.h>
#include<dos.h>


using namespace std;
int main()
{   
	int a=0,b=0,n=3;
	char sign='+', br1 ,br2, pol1='S',pol2,pol3,pol4;
	cout<<"Follow the syntax: \n\n\ta+bSin(nx) / a+bCos(nx): ";
	cin>>a>>sign>>b>>pol1>>pol2>>pol3>>pol4>>n>>br1>>br2;
	cout<<a<<sign<<b<<pol1<<pol2<<pol3<<pol4<<n<<br1<<br2;	
    int gd=DETECT,gm;
	double a1=3,x=10,y=0,t=1,b1=2,n1=0,d=0,k=0;
	char h='0';
	initgraph(&gd,&gm,"Usama");
	setcolor(WHITE);
	line(630/2,600,630/2,0);
	line(0,500/2,700,500/2);
//	for (int i=0;i<(40*10);i+=40)
 //   {
//	outtextxy(((610/2)+i),(510/2),&h);
	//	outtextxy(((610/2)-i),(510/2),&h);
	//outtextxy(((610/2)),((510/2)+i),&h);
//		outtextxy(((610/2)),((510/2)-i),&h);
//	h++ ;
	//}
     int asd;
    int i,j;
  
	//Cardroid
	if((a==b)&& (a!=0)  && (b!=0))
	{
                 a1=3,x=10,y=0,t=0,b1=2,n1=0,d=0,k=0;
                 
                  while(t<=6.28)
               {
		        t+=0.00001;
                x=(1+cos(t))*sin(t);
                y=(1+cos(t))*cos(t);
                if((pol1=='C') && (sign=='-'))
               { //left 
                putpixel(-y*(100/2)+315,x*(100/2)+250,YELLOW);
	            }
                else if((pol1=='S') && (sign=='+'))
                {
                //up 
                putpixel(x*(100/2)+315,-y*(100/2)+250,YELLOW);
	            }
                else if((pol1=='S') && (sign=='-'))
                {
                //down 
                putpixel(x*(100/2)+315,y*(100/2)+250,YELLOW);
	            }
                else if((pol1=='C') && (sign=='+'))
                {
                //right 
                putpixel(y*(100/2)+315,x*(100/2)+250,YELLOW);
                }
                }
    }
  
	//Dimpled
	else if(((a-1)>=b) && (a!=0)  && (b!=0))
	{
        	a1=3,x=10,y=0,t=0,b1=2,n1=0,d=0,k=0;

               while(t<=6.28)
               {
               t+=0.00001;
             x=(1.4+cos(t))*sin(t);
  		  y=(1.4+cos(t))*cos(t);
		        if((pol1=='C') && (sign=='-'))
             {
            //left
             putpixel(-y*(100/2)+315,x*(100/2)+250,YELLOW);
	              } 
                  else if((pol1=='S') && (sign=='+'))
                 {          
                //up 
                putpixel(x*(100/2)+315,-y*(100/2)+250,YELLOW);
                
                   }
                   else if((pol1=='S') && (sign=='-'))
             {
                //down 
                putpixel(x*(100/2)+315,y*(100/2)+250,YELLOW);
	               }
                   else if((pol1=='C') && (sign=='+'))
             {
                //right 
                putpixel(y*(100/2)+315,x*(100/2)+250,YELLOW);
                }
          }
    }
	//Rose2
	
    else if((a==0) && (n>=2))
	{
    
	  a1=n,x=10,y=0,t=0,b1=2;
 	  while(t<=7)
      {
		t+=0.00001;
		a1+=1/2;
       if(pol1=='C'){      
           x=cos(a1*t)*cos(t);
  		y=cos(a1*t)*sin(t);
    }
     else if(pol1=='S')
     {
        x=sin(a1*t)*sin(t);
  		y=sin(a1*t)*cos(t);
    }
                  	putpixel(x*(100)+630/2,y*(100)+500/2,YELLOW);
	   	  
      //  delay(.5);
      }
    }
    
    
	//inner looped Limacon
	else if((a<=(b-1)) && (a!=0)  && (b!=0))
	{
         a1=1,x=10,y=0,t=0,b1=2,d=0,n1=0,k=0;
		  while(t<=6.28)
    
        {
	    	 t+=0.00001;
	    	x=(a1+b1*cos(t))*cos(t);
      		y=(a1+b1*cos(t))*sin(t);
  		   if((pol1=='S') && (sign=='+'))
            { 
          //up
             putpixel(-y*(100/2)+315,-x*(100/2)+250,YELLOW);
	          } 
                 else if((pol1=='C') && (sign=='-'))
             {
               // left 
                putpixel(-x*(100/2)+315,-y*(100/2)+250,YELLOW);
	           }
                else if((pol1=='C') && (sign=='+'))
               { 
                //right 
                putpixel(x*(100/2)+315,y*(100/2)+250,YELLOW);
                }
                else if((pol1=='S') && (sign=='-'))
             {
                //down 
                putpixel(y*(100/2)+315,x*(100/2)+250,YELLOW);
                }    
            //delay(.5);
      
         }
    }
    //circle
    
    else if((a==0 ) && (n==1))
	{
    
	  a1=1,x=10,y=0,t=0,b1=2;
 	  while(t<=6.28)
      {
		t+=0.00001;
		a1+=1/2;
        x=cos(a1*t)*cos(t);
  		y=cos(a1*t)*sin(t);
      //  x=sin(a1*t)*sin(t);
  		//y=sin(a1*t)*cos(t);
     //    circle (300,250,100);
      if( (pol1=='S') && (sign=='-') )
      {       
        	//down
              putpixel(y*(100)+315,x*(100)+250,YELLOW);
              
              }
            if((pol1=='C') && (sign=='+'))
             {       
                //right
               putpixel(x*(100)+315,y*(100)+250,YELLOW);
               }
               //   else
                if((pol1=='C') && (sign=='-'))
             {
                //left
                       putpixel(-x*(100)+315,-y*(100)+250,YELLOW);
                  }
                if((pol1=='S') && (sign=='+'))
             {
                //up
                putpixel(-y*(100)+315,-x*(100)+250,YELLOW);
             }        	
	  //  delay(.5);
          }
        }
    
     
  //   exit(0);
    
	getch();
	closegraph();
	return 0;
}
