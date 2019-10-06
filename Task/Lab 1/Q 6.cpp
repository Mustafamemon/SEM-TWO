#include<iostream>
using namespace std ;
digit(int num)
{
	if (num==1)
	cout<<"ONE";
	else if (num==2)
	cout<<"TWO";
	else if (num==3)
	cout<<"THREE";
	else if (num==4)
	cout<<"FOUR";
	else if (num==5)
	cout<<"FIVE";
	else if (num==6)
	cout<<"SIX";
	else if (num==7)
	cout<<"SEVEN";
	else if (num==8)
	cout<<"EIGHT";
	else if (num==9)
	cout<<"NINE";
	else
	cout<<"ERORR\n" ;
}
int main ()
{
	int  num ;
	cout<<"ENTER THE NUMBER ";
	cin>>num ;
	digit(num);
}
