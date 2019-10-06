#include<iostream>
#include<cstdlib>
using namespace std ;
class counter{
private :
	static int cnt ;
public :
	counter();
	~counter();
	void increment();
	void decrement();
	void reset(counter obj);
	int display();
};
counter::~counter(){
	cout<<"\nOBJECT IS KILLED\n";
}
counter::counter(){
		cnt = 0 ;
}
void counter::increment(){
	++cnt;
}
void counter::decrement(){
	--cnt;
}
void counter::reset(counter obj){
	obj.cnt = 0 ;
}
int counter::display(){
	return cnt ;
}
int counter::cnt ;
int main(){
	counter c , b;
	int a ;
	do{
		cout<<"\n1:FOR INCREMENT\n2:FOR DECREMENT\n3:FOR RESET\nPRESS ANT TO EXIT:\n" ;
		cin>>a ;
		switch (a){
			case 1 :
			c.increment();
			cout<<"\tAFTER INCREMENT : "<<c.display();
			break ;
			case 2:
			c.decrement();
			cout<<"\tAFTER DECREMENT : "<<c.display();
			break ;
			case 3:
			c.reset(b);
			cout<<"\tAFTER RESET : "<<c.display();
			break ;
			default :
			exit(0);
	}
	}while(a>0 && a<4);
}

