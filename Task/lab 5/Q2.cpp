#include<iostream>
#include<cstring>
using namespace std ;
class rentcal{
private :
	const float rentPerDay ;
	char *customerName;
	int numberOfDays ;
	float customerRent ;
public :
	rentcal():rentPerDay(1000.85){
		customerName = new char [1];
		customerName = '\0' ;
		numberOfDays = 0 ;
		customerRent = 0.0 ;
	}
	void RentCalculator(char name[] , int days);
	void RentWithBonus();
	void RentWithoutBonus();
	void DisplayRent()const;
	
};
void rentcal::RentCalculator(char name[] , int days){
	this->customerName = new char [strlen(name)];
	this->customerName = name ;
	numberOfDays=days ;
}
void rentcal::DisplayRent()const{
	cout<<"\nCUSTOMER NAME :"<<customerName<<"\nDAYS : "<<numberOfDays<<"\nRENT :"<<customerRent;
}
void rentcal::RentWithBonus(){
	customerRent = rentPerDay*(numberOfDays-1) ;
}
void rentcal::RentWithoutBonus(){
	customerRent = rentPerDay*numberOfDays ;
}
int main(){
	char name[10] ,name1[10];
	int days ;
	cout<<"ENTER THE NAME : " ;
	cin>>name; 
	cout<<"ENTER THE NUMBER OF DAYS : " ;
	cin>>days ;
	rentcal r ;
	r.RentCalculator(name,days);
	if (days<=7){
		r.RentWithoutBonus();
	}
	else
	r.RentWithBonus();
	cout<<"\nENTER THE NAME : " ;
	cin>>name1; 
	cout<<"\nENTER THE NUMBER OF DAYS : " ;
	cin>>days ;
	rentcal r1 ;
	r1.RentCalculator(name1,days);
	if (days<=7){
		r1.RentWithoutBonus();
	}
	else
	r1.RentWithBonus();
	r.DisplayRent();
	r1.DisplayRent();
}
