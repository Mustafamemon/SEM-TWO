#include<windows.h>
#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std ;
template<typename T>
class Queue{
private:
	int size;
	T *ptr;
	static int cnt;
public:
	Queue(int s=6)
	{
		size=s;
		ptr=new T[size];
		for(int i=0;i<=5;i++)
		{
			ptr[i]=i+1+(0.2*i+2);
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
	
	void Enqueue()
	{
		if(Check_full())
		{
			++cnt;
			cout<<"\nEnter the element : ";
			cin>>ptr[cnt];
		}
	}
	
	void Dequeue()
	{
		if(Empty())
		{
			for(int i=0;i<=cnt;i++)
			{
				ptr[i]=ptr[i+1];
			}
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
			cout<<"\nQueue is Empty\n";
		}
	}
	
	int getsize()
	{
		return size;
	}
};
template <typename T>
int Queue<T>::cnt=0;
int main()
{
	int ans;
	again:
	cout<<"1:For Integer \n2:For Double\n";
	cin>>ans;
	if(ans==1)
	{
		Queue<int> obj;
		do
		{
			cout<<"1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n";
			cin>>ans;
			if(ans==1)
			{
				obj.Enqueue();
			}
			else if(ans==2)
			{
				obj.Dequeue();
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
		Queue<double> obj;
		do
		{
			cout<<"1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n";
			cin>>ans;
			if(ans==1)
			{
				obj.Enqueue();
			}
			else if(ans==2)
			{
				obj.Dequeue();
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
