#include<iostream>
using namespace std;
template<typename T>
class multiply{
public:
	void multip(T a,T b)
	{
		cout<<a*b;
	}
	void multip(T a,T b,T c)
	{
		cout<<endl<<a*b*c;
	}
};
int main()
{
	multiply <int>obj;
	obj.multip(2,4);
	obj.multip(2,3,5);
}
