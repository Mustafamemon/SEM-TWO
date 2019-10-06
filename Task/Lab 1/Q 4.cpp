#include <iostream>
using namespace std;
swapfloat(float x , float y)
{
	x=x+y ;
	y=x-y ;
	x=x-y ;
	cout<<"x : "<<x<<" y : "<<y ;	
}
int main()
{
	float x ,y ; 
	cout<<"ENTER THE TWO NUMBERS : " ;
	cin>>x>>y;
	swapfloat(x,y);
}
