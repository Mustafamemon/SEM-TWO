#include <iostream>
using namespace std;
int main()
{
	int num ;
	cout<<"ENTER THE NUMBER : " ;
	cin>>num ;
	if (num==1 || num==3 || num==5 || num==7 || num==8 || num==10 || num==12)
	cout<<"DAYS  : Thirty One " ;
	if (num==4 || num==6 || num==9 || num==11 )
	cout<<"DAYS  : Thirty " ;
	if (num==2)
	cout<<"DAYS  : Twenty Nine " ;
}
