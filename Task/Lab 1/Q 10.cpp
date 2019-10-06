#include <iostream>
using namespace std;
int main()
{
	int num,temp,rev;
	cout<<"ENTER THE NUMBER : " ;
	cin>>num ;
	while (num>0)
	{
		temp=num%10 ;
		rev= (rev*10)+temp ;
		num/=10 ;
	}
	while (rev>0)
	{
		temp=rev%10 ;
		temp++;
		if (temp>9)
		cout<<"0" ;	
		else
		cout<<temp;
		rev/=10;
	}
}
