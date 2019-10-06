//draws a rectangle using functions
#include <stdio.h>
#include <iostream>
using namespace std; 
void draw_solid_line(int size,char a);
void draw_hollow_line(int size,char a);
void draw_rectangle(int len, int wide,char a);

int main(void) {
    int length, width;
        
    cout<<"Enter length and width of rectangle :";
    cin>>length>>width;
    char a ;
    cout<<"Enter the symbol : ";
	cin>>a ;
    draw_rectangle(length, width,a); 
    cout<<"\b";
    system("pause");
    return 0;
}
void draw_solid_line(int size , char a){
	int i  ;
	for (i=1;i<=size;i++){
		cout<<a;
	}
	cout<<endl<<a;
}
void draw_hollow_line(int size,char a) {
    int i ;
    for (i=2;i<size;i++){
		cout<<" " ;
	}
	cout<<a ;
}
void draw_rectangle(int len, int wide,char a) {
    int i;
    draw_solid_line(wide,a);
    if (len > 2){
		for (i=1; i<=len-2; i++){
		draw_hollow_line(wide,a);
    	cout<<endl<<a;
    }
    }
    cout<<"\b";
    draw_solid_line(wide,a);
}
