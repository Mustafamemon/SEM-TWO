#include<iostream>
using namespace std ;
int func (int x , int y){
	cout<<"AREA : "<<x*y<<endl;
	cout<<"PARAMETER : "<<2*x+2*y;
}
int read (int x  , int y){
	cout<<"ENTER THE LENGTH AND WIDTH : " ;
	cin>>x>>y ;
	func(x,y);
}
int main (){
	read(0,0);
}
