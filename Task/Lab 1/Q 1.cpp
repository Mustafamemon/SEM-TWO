#include <iostream>
using namespace std;
int main()
{
	int num ;
	cin>>num ;
	while (num%2==0)
	{
		num/=2 ;
		cout<<num<<endl;
		num+=2;
		cout<<num<<endl;
	}
}

