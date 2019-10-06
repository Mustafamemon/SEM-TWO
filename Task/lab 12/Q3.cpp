#include<iostream>
#include<cstring>
using namespace std;
template<typename T, typename U>
class myclass{
private:
	T x ;
	U y;
public:
	myclass(T ax,U ay)
	{
		x=ax;
		y=ay;
	}
	void Add()
	{
		cout<<x+y;
	}
};
template<>
class myclass<char*,char*>{
private:
	char *h ;
	char *y;
public:
	myclass(char*ax,char *ay)
	{
		h=new char [10];
		y=new char [10];
		strcpy(h,ax);
		strcpy(y,ay);
	}
	void Add()
	{
		strcat(h,y);
		cout<<"\n"<<h;
	}
};
int main()
{
	myclass<int,float> obj(1,2.2);
	obj.Add();
	char ch[]={"Now"},ch1[]={"then"};
	myclass<char*,char*> obj1(ch,ch1);
	obj1.Add();
}
