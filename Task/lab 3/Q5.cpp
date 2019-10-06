#include<iostream>
using namespace std ;
class coffee {
	int order ;
	float cost ;
public :
	void setorder(int aorder){
		order=aorder ;
	}
	void get(){
		cost = (float)order*5.5  ;
		cout<<"THE COST OF ORDER  :$ "<<cost;
	}
	void func(){
		cout<<"\nBOXES USED : \n" ;
		int temp ;
		temp = order/20 ;
		order = order - (temp*20) ;
		if (order<19 && order>15)
		{
			temp= temp+1 ;
			order = 0 ;	
		}
		cout<<temp <<"LARGE - $"<<(temp*1.8)<<"\n" ;
		cost = cost + (float)(temp*1.8) ;
		temp=order/10 ;
		order = order - (temp*10) ;
		if (order<10 && order>5)
		{
			temp= temp+1 ;
			order = 0 ;			
		}
		cout<<temp<<"MEDIUM - $"<<temp<<"\n" ;
		cost = cost + (float)(temp*1) ;
		temp = order/5 ;
		order = order - (temp*5) ;
		if (order<5 && order>0)
		temp = temp + 1 ;
		cout<<temp<<"SMALL - $"<<(temp*0.6)<<"\n" ;
		cost = cost + (float)(temp*0.6) ;
		cout<<"\nYOUR TOTAL COST IS  : $ "<<cost ;
	}
};
int main (){
	int ord ;
	cout<<"ENTER THE NO OF ORDER : " ;
	cin>>ord ;
	coffee r ;
	r.setorder(ord) ;
	r.get() ;
	r.func() ;
}
