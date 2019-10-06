#include<iostream>
using namespace std ;
class meal{
private :
	string name ;
	int calorie ;
public :
	meal(string n="DAILY-TOTAL",int c = 1){
		name = n;
		calorie = c; 
	}
	meal operator +(meal&c){
		meal temp ;
		temp.calorie=calorie+c.calorie ;
		return temp ;
	}
	friend ostream& operator<<(ostream&,const meal&);
	friend istream& operator>>(istream&,meal&);
};
ostream& operator<<(ostream&output,const meal&c){
	output<<"NAME : "<<c.name ;
	output<<"\nCALORIE :"<<c.calorie ;
}
istream& operator>>(istream&input,meal&c){
	cout<<"ENTER NAME : " ;
	input>>c.name ;
	cout<<"ENTER CALORIE :";
	input>>c.calorie ; 	
}
int main(){
	meal m[21],sum("DAILY-MEAL",0) ;
	for(int i=0;i<21;i++){
		cin>>m[i] ;
		sum = sum + m[i] ;
	}
	cout<<sum;
	
}
