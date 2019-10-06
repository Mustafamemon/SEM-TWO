#include<iostream>
using namespace std;
template<typename T>
class bubble{
private:
	int size;
	T *ptr;
public:	
	bubble(int=10);
	int func()
	{
		T temp;
		for (int i=0;i<size;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(ptr[i]>ptr[j])
				{
					temp=ptr[i];
					ptr[i]=ptr[j];
					ptr[j]=temp;
				}
			}
		}
		return 0;
	}
	void display()
	{
		for (int i=0;i<size;i++)
		cout<<ptr[i]<<"\t";
	}
	~bubble()
	{
		delete []ptr;
	}
};
template<typename T>
bubble<T>::bubble(int s)
{
	size=s;
	ptr=new T[size];
	cout<<"\nEnter The Element Of the Array : ";
	for(int i=0;i<size;i++)
	cin>>ptr[i];
}
int main()
{
	cout<<9/9;
	bubble<int> obj(5);
	cout<<"\n\nBEFORE SORTING\n";
	obj.display();
	obj.func();
	cout<<"\n\nAFTER SORTING\n";
	obj.display();
	bubble<float> obj1(5);
	cout<<"\n\nBEFORE SORTING\n";
	obj1.display();
	obj1.func();
	cout<<"\n\nAFTER SORTING\n";
	obj1.display();
	bubble<char> obj2(5);
	cout<<"\n\nBEFORE SORTING\n";
	obj2.display();
	obj2.func();
	cout<<"\n\nAFTER SORTING\n";
	obj2.display();
}
