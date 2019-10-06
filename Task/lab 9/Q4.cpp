#include<iostream>
using namespace std ;
class phonecalls{
private:
	string phone ;
	int min ;
	float rate ;
public :
	phonecalls(){
		phone='\0' ;
		min=0 ;
		rate=0.0;
	}
	void set_data(string no , int m , float r ){
		phone = no ;
		min = m ;
		rate = r ;
	}
	bool operator ==(phonecalls &c){
		if (phone==c.phone)
		return true; 
		else
		return false;
	}
	friend istream& operator>>(istream&input ,phonecalls &c){
		cout<<"ENTER THE PHONE NO : " ;
		cin>>c.phone;
		cout<<"ENTER THE MINS  : ";
		cin>>c.min;
		cout<<"ENTER THE RATE CHANGE PER MIN : ";
		cin>>c.rate;
	}
};
int main(){
	phonecalls P[10] ;
	for(int i=0;i<=9;i++){
		cin>>P[i] ;
		for (int j=0;j<i;j++)
		if (P[i]==P[j]){
			cout<<"WRONG INPUT\n" ;
			--i ;
			cout<<"INPUT AGAIN\n"; 	
		}
	}
}
