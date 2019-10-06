#include<iostream>
using namespace std ;
class A{
public:
	A(){
		cout<"\nA" ;
	}
	~A(){
		cout<<"\n~A" ;
	}
};
class B:public A{
public:
	B(){
		cout<<"\nB" ;
	}
	~B(){
		cout<<"\n~B" ;
	}	
};
int main(){
	B obj ;
	int a; 
	cin>>a ; 
	
}
