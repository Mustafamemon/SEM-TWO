#include<iostream>
using namespace std ;
class DOB{
private :
	int D ;
	int M ;
	int Y ;
public :
	void set_DOB(int d,int m,int y){
		D=d ;
		M=m ;
		Y=y ;
	}
	void Display(){
		cout<<D<<'/'<<M<<'/'<<Y<<endl ;
	}
	~DOB(){
		cout<<"1" ;
	}
};
class B{
private :
	DOB ptr ;
public:
	void DATA(){
		ptr.set_DOB(1,2,3);
		ptr.Display();
	}
	~B(){
		cout<<"2" ;
	}
};
int main(){
	B p ;
	p.DATA();
}
