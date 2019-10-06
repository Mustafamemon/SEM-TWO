#include <iostream>
using namespace std;
F(int x , int y, int n ,int a)
{
	int f ;
	if(a>0)
	{
		f=x+y ;
		cout<<f;
	}
	if(n<=0)
	{
		f=x-y ;
		cout<<f;
	}
	
}
int main()
{
	int x , y, n , a ;
	cout<<"ENTER X Y N A : " ;
	cin>>x>>y>>n>>a ;
	F(x,y,n,a);
}
