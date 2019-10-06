#include <iostream>
using namespace std;
int main()
{
	int num,num1,num2,num3,sum ;
	char c ;
	cout<<"Enter first fraction:"; 
	cin>>num>>c>>num1 ;
	cout<<"Enter second fraction:";
	cin>>num2>>c>>num3 ;
	sum = (num*num3)+(num1*num2);
	cout<<sum<<"/"<<num1*num3 ;
}
