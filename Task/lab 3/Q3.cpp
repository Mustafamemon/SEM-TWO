#include<iostream>
using namespace std ;
class invoice {
	string pname ;
	int item ;
	float pric ;
public :
	invoice(){
		item = 0 ;
		pric = 0 ;
	}
	string pdes ;
	void setpnam(string apname){
		pname=apname ;
	}
	void setpdes(string apdes){
		pdes=apdes ;
	}
	void setitem(int aitem){
		if(aitem>0)
		item=aitem ;
	}
	void setpric(float apric){
		if (apric>0.0)
		pric=apric ;
	}
float  getinvoice(){
	return (float)item*pric ;
}
};
int main (){
	invoice r ;
	string x  ;
	int z ;
	float a ;
	cout<<"ENTER PART NUMBER , NO OF ITEM & PRICE PER ITEM : " ;
	cin>>x>>z>>a;
	r.setpnam(x); 
	fflush(stdin) ;
	cout<<"ENTER THE PART DESCRIPTION " ;
	getline(cin,r.pdes);
	cout<<r.pdes ;
	r.setitem(z);
	r.setpric(a);
	cout<<"TOTAL AMOUNT : "<<r.getinvoice() ;
}
