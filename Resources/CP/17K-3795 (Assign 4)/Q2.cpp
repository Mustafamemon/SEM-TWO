#include<windows.h>
#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std ;
template<typename T>
class Stack{
private:
	int size;
	T *ptr;
	static int cnt;
public:
	Stack(int s=6)
	{
		size=s;
		ptr=new T[size];
		for(int i=0;i<6;i++)
		{
			ptr[i]=i+1+(0.1*i+i-2+4);
		}
		cnt=5;
	}
	
	bool Empty()
	{
		if(cnt<0)
		{
			cout<<"\nUnder-Flow\n";
			return false;
		}
		return true;
	}
	
	bool Check_full()
	{
		if(cnt==(size-1))
		{
			cout<<"\nOver-Flow\n";
			return false;
		}
		return true;
	}
	
	void push()
	{
		if(Check_full())
		{
			++cnt;
			cout<<"\nEnter the element : ";
			cin>>ptr[cnt];
		}
	}
	
	void pop()
	{
		if(Empty())
		{
			--cnt;
		}
	}
	
	void Display()
	{
		for(int i=0;i<=cnt;i++)
		{
			cout<<ptr[i]<<"\t";
		}
		cout<<"\n";
		if(cnt<0)
		{
			cout<<"\nStack is Empty\n";
		}
	}
	
	int getsize()
	{
		return size;
	}
};
template <typename T>
int Stack<T>::cnt=0;
int main()
{
	int ans;
	again:
	cout<<"1:For Integer \n2:For Double\n";
	cin>>ans;
	if(ans==1)
	{
		Stack<int> obj;
		do
		{
			cout<<"1:Push\n2:Pop\n3:Display\n4:Exit\n";
			cin>>ans;
			if(ans==1)
			{
				obj.push();
			}
			else if(ans==2)
			{
				obj.pop();
			}
			else if(ans==3)
			{
				obj.Display();
			}
			else if(ans>4)
			{	
				cout<<"\nInvalid-Input\n";
			}
		}while(ans!=4);	
	}
	else if (ans==2)
	{
		Stack<double> obj;
		do
		{
			cout<<"1:Push\n2:Pop\n3:Display\n4:Exit\n";
			cin>>ans;
			if(ans==1)
			{
				obj.push();
			}
			else if(ans==2)
			{
				obj.pop();
			}
			else if(ans==3)
			{
				obj.Display();
			}
			else if(ans>4)
			{	
				cout<<"\nInvalid-Input\n";
			}
		}while(ans!=4);
	}
	else
	{
		cout<<"\nInvalid-Input\n";
		Sleep(2000);
		system("cls");
		goto again;
	}
}
