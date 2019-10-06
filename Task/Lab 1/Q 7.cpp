#include <iostream>
using namespace std;
add(float num , float num1)
{
	float res ;
	res=num+num1;
	cout<<res ;
}
sub(float num , float num1)
{
	float res ;
	res=num-num1;
	cout<<res ;
}
mult(float num , float num1)
{
	float res ;
	res=num*num1;
	cout<<res ;
}
div(float num , float num1)
{
	float res ;
	res=num/num1;
	cout<<res ;
}
int main()
{
	float num , num1 ;
	char c ;
	cout<<"ENTER THE 1st NUMBER : " ;
	cin>>num ;
	cout<<"ENTER THE OPERATOR : " ;
	cin>>c ;
	cout<<"ENTER THE 2st NUMBER : " ;
	cin>>num1 ;
	switch (c)
	{
		case '+' :
		add(num , num1) ;
		break ;
		case '-' :
		sub(num , num1) ;
		break ;
		case '*' :
		mult(num , num1) ;
		break ;
		case '/' :
		div(num , num1) ;
		break ;
	}
}

	
