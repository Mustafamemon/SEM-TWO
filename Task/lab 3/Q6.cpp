#include<iostream>
using namespace std ;
class vehicle {
	int year ;
	string manu ;
	int speed ;
public :
	void set(int y ,string man , int s){
		year =y ;
		manu=man ;
		speed =s ;
	}
	void get(){
		cout<<"\n\t\tYEAR : "<<year<<" MANUFACTURE : "<<manu ;
	}
	void func (int i ){
		speed=speed + 5 ;
		cout<<"\n\t\tSPEED : "<<speed;
	}
	void func1(int i) {
		speed=speed - 5 ;
		cout<<"\n\t\tSPEED : "<<speed ;
	}
};
int main (){
	vehicle a , b ;
	int y , s ,i ;
	string amanu ;
	cout<<"ENTER THE YEAR , MANUFACTURE & SPEED : " ;
	cout<<"\n\tBIKE : " ;
	cin>>y>>amanu>>s ;
	b.set(y,amanu,s);
	cout<<"\n\tAUTO : " ;
	cin>>y>>amanu>>s ;
	a.set(y,amanu,s);
	cout<<"ENTER THE NO OF WHEELS : " ;
	cin>>y ;
	if (y==2){
	cout<<"FOR BIKE : " ;
	b.get();
	cout<<"\n\tACCELERATE : \n" ;
	for(i=1;i<6;i++){
		b.func(i) ;
	}
	cout<<"\n\tBRAKE : \n" ;
	for(i=1;i<3;i++){
		b.func1(i) ;
	}
	}
	else if (y==3){
	cout<<"\nFOR AUTO : " ;
	a.get() ;
	cout<<"\n\tACCELERATE : \n" ;
	for(i=1;i<6;i++){
		a.func(i) ;
	}
	cout<<"\n\tBRAKE : \n" ;
	for(i=1;i<3;i++){
		a.func1(i) ;
	}
	}
	else
	cout<<"WRONG INPUT" ;
}
