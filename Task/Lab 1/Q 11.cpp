#include <iostream>
using namespace std;
int main()
{
	int i,j=2,num ;
	cout<<"ENTER THE NUMBER OF TERMS : " ;
	cin>>num ;
	for (i=1;i<=num;i++)
	{
		cout<<j<<endl;
		j=(j*2)+2 ;
	}
}
