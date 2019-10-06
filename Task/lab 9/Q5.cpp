#include<iostream>
using namespace std ;
class Numberofdays{
private :
	int no_work_hr ;
public :
	Numberofdays(int a){
		no_work_hr = a ; 
	}
	void set_data(int a){
		no_work_hr = a ;
	}
	float set_day(){
		float days ;
		days = (float)no_work_hr/8.0;
		return days ;
	}
	Numberofdays operator +(Numberofdays &c){
		Numberofdays sum(0);
		sum.no_work_hr = no_work_hr + c.no_work_hr ;
		return sum ;
	}
	Numberofdays operator -(Numberofdays &c){
		Numberofdays sum(0);
		sum.no_work_hr = no_work_hr - c.no_work_hr ;
		return sum ;
	}
	//pre
	Numberofdays operator ++(){
		++no_work_hr;  
		return *this ;
	}
	//post
	Numberofdays operator ++(int){
		Numberofdays c = *this ;
		no_work_hr++;  
		return c;
	}
	//pre
	Numberofdays operator --(){
		--no_work_hr;  
		return *this ;
	}
	//post
	Numberofdays operator --(int){
		Numberofdays c = *this ;
		no_work_hr--  ;  
		return c ;
	}
	int get_data(){
		return no_work_hr ;
	}
};

int main(){
	int hr ;
	cout<<"OBJECT 1\n" ;
	cout<<"ENTER THE NO OF WORK HOUR  : " ;
	cin>>hr ;
	Numberofdays obj1(hr);
	cout<<"NO OF DAYS : "<<obj1.set_day();
	cout<<"\n\t\tAFTRE INCREMENT" ;
	obj1++ ;
	cout<<"\nPost : "<<obj1.get_data() ;
	++obj1 ;
	cout<<"\nPre : "<<obj1.get_data() ;
	cout<<"\n\t\tAFTRE DECREMENT" ;
	obj1-- ;
	cout<<"\nPost : "<<obj1.get_data() ;
	--obj1 ;
	cout<<"\nPre : "<<obj1.get_data() ;
	cout<<"\nOBJECT 2\n" ;
	cout<<"ENTER THE NO OF WORK HOUR  : " ;
	cin>>hr ;
	Numberofdays obj2(hr);
	cout<<"NO OF DAYS : "<<obj2.set_day();
	cout<<"\n\t\tAFTRE INCREMENT" ;
	obj2++ ;
	cout<<"\nPost : "<<obj2.get_data() ;
	++obj2 ;
	cout<<"\nPre : "<<obj2.get_data() ;
	cout<<"\n\t\tAFTRE DECREMENT" ;
	obj2-- ;
	cout<<"\nPost : "<<obj2.get_data() ;
	--obj2 ;
	cout<<"\nPre : "<<obj2.get_data() ;
	Numberofdays obj3(0);
	obj3 = obj1+obj2 ;
	cout<<"\nAFTER ADDITION : " ;
	cout<<obj3.get_data() ;
	obj3 = obj1-obj2 ;
	cout<<"\nAFTER SUBTRACTION : " ;
	cout<<obj3.get_data() ;
	
}
