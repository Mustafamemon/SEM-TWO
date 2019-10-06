#include<stdlib.h>
#include<iostream>
using namespace std ;
int p;
class A{
private :
	static int a ;
	int b;
public:
	static int h;
	A()
	{
		b=0;
	}
	static void func1()
	{
		cout<<"Q";		
	}
	void func ()
	{
		func1();
		cout<<a<<"\t"<<b<<endl;
	}
};
int A::a=0;
int A::h=0;
class B:public A{
private:
	int f ;
	int g ; 
public:
	inline void func1()
	{
		cout<<f<<"\t"<<g<<endl;	
	}
};
int main()
{
	A::h=0;
	A obj1;
	obj1.func();
	return 0;
}
