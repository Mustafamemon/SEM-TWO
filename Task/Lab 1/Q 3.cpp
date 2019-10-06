#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	int num ,  marks ;
	cout<<"enter the number of courses " ;
	cin>>num ;
	cout<<"enter the total marks " ;
	cin>>marks ;
	float avg =(float) num / marks ;
	cout<<"AVG : "<<fixed<<setprecision(4)<<avg ;
}
