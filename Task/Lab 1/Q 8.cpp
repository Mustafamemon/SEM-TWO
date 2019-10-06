#include<iostream>
using namespace std ;
int main ()
{
	int gue , cha , prod=1 ;;
	cout<<"suppose Chair are less than or equal to number of Guests"<<endl ;
	cout<<"ENTER THE NUMBER OF GUESTS AND CHAIR : " ;
	cin>>gue>>cha ;
	for (int i=gue ;i > (gue-cha) ; i--)
	{
		prod= prod*i ;
	}
	cout<<prod<<" Ways !";
	
}
