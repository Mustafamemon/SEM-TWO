#include<iostream>
#include<iomanip>
using namespace std ;
class Distance{
	float d ;//distance
	float d_feet;
	float d_inches ;
public :
	Distance():d(0),d_feet(0),d_inches(0){};
	~Distance(){
		cout<<"\nOBJECT IS KILLED :(" ;
	}
	void set_d(){
		cout<<"ENTER THE DISTANCE IN METERS : ";
		cin>>d ;
		d_feet = d*3.28084 ;
		d_inches = d*39.3701;
	}
	void get_d_f(){
		cout<<"\nIN FEET : "<<fixed<<setprecision(2)<<d_feet ;
	}
	void get_d_i(){
		cout<<"\nIN INCHES : "<<fixed<<setprecision(2)<<d_inches ;
	}
};
int main(){
	Distance D ;
	D.set_d();
	cout<<"\t\t\tDISTACNE ";
	D.get_d_f();
	D.get_d_i();
}
