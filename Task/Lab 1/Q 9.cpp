#include<iostream>
using namespace std ;
int main ()
{
	int amo , temp = 0, rev ;
	cout<<"ENTER THE AMOUNT : " ;
	cin>>amo ;
	temp= amo/100 ;
	cout<<temp<<" Note(s) Of 100 \n" ;
	amo = amo - (temp*100);
	temp= amo/50 ;
	cout<<temp<<" Note(s) Of 50 \n" ;
	amo = amo - (temp*50);
	temp= amo/20 ;
	cout<<temp<<" Note(s) Of 20 \n" ;
	amo = amo - (temp*20);
	temp= amo/10 ;
	cout<<temp<<" Note(s) Of 10 \n" ;
	amo = amo - (temp*10);
	temp= amo/5 ;
	cout<<temp<<" Note(s) Of 5 \n" ;
	amo = amo - (temp*5);
	temp= amo/2 ;
	cout<<temp<<" Note(s) Of 2 \n" ;
	amo = amo - (temp*2);
	temp= amo/1 ;
	cout<<temp<<" Note(s) Of 1 \n" ;
	amo = amo - (temp*1);
	return 0 ;
}
