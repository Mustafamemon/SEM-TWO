#include<iostream>
#include<cstdlib>
using namespace std;
template<typename T>
class stack{
private:
	int size;
	int cnt;
	T *ptr;
public:
	stack(int =11);
	~stack();
	T& push();
	T& pop();
	void Display();
};
template<typename T>
stack<T>::stack(int s)
{
	size=s;
	cnt=0;
	ptr = new T[size];	
}
template<typename T>
stack<T>::~stack()
{
	delete []ptr;
}
template<typename T>
T& stack<T>::push()
{
	cout<<"ENTER THE NUM";
	cin>>ptr[cnt];
	++cnt;
	return ptr[cnt];
}
template<typename T>
T& stack<T>::pop()
{
	--cnt;
}
template<typename T>
void stack<T>::Display()
{
	for(int i=0;i<cnt;i++)
	cout<<ptr[i]<<"\t";
}
int main()
{
	int ans;
	stack<float> obj;
	do 
	{
		cout<<"\n1:PUSH\n2:POP\n3:DISPLAY\n4:EXIT";
		cin>>ans;
		if(ans==1)
		obj.push();
		else if(ans==2)
		obj.pop();
		else if(ans==3)
		obj.Display();	
	}while(ans!=4);	
}
