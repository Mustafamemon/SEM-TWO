#include<iostream>
using namespace std;
template<typename T>
class myclass{
private:
	int size;
	T *ptr;
public:
	myclass(int s=10)
	{
		size=s;
		ptr=new T[size];
		cout<<"\nEnter The Element Of the Array : ";
		for(int i=0;i<size;i++)
		cin>>ptr[i];
	}
	T sum()
	{
		T sum='\0';
		for(int i=0;i<size;i++)
		sum=sum+ptr[i];
		return sum ;
	}
};
int main()
{
	while(-1)
	{
	myclass<int> obj(5);
	cout<<obj.sum();
	myclass<double> obj1(5);
	cout<<obj1.sum();
}
}
