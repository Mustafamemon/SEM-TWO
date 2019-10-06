#include<iostream>
using namespace std ;
class rectangle{
	float len ;
	float widt ;
public :
	rectangle(){
		len=1;
		widt=1 ;
	}
	void set(float alen , float awidt){
		if (alen>0.0 && alen<20.0)
			len=alen ;
		if (awidt>0.0 && awidt<20.0)
			widt=awidt ;
	}
	void get(){
		cout<<"AREA OF RECTANGLE OF LENGTH "<<len<<" AND WIDTH "<<widt<<" IS " ;
	}
float area(){
	return len*widt; 
}
float pra(){
	return 2*(len+widt); 
}
};
int main (){
	rectangle r ;
	r.get();
	cout<<r.area();
	float x , y ;
	cout<<"\nENTER THE LENGTH AND WIDTH : \n" ;
	cin>>x>>y ;
	r.set(x,y);
	r.get();
	cout<<r.area()<<" AND PARAMETER IS : "<<r.pra();
	return 0 ;
}
