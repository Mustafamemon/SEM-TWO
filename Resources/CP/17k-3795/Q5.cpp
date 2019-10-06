#include<iostream>
using namespace std ;
class date{
	int day ;
	int month ;
	int year ;
public :
	date(int d , int m , int y);
	void set_data(int aday ,int amonth , int ayear);
	void display_date();
	~date(){
		cout<<"\nOBJECT IS KILLED\n";
	}
};
date::date(int d , int m , int y){
	day = d ;
	month = m ;
	year = y ;
}
void date::set_data(int aday ,int amonth , int ayear){
	if (aday>0 && aday<32)
	day = aday ;
	if (amonth>0 && amonth<13)
	month = amonth ;
	if (ayear>0 && ayear<13)
	year = ayear ;
}
void date::display_date(){
	cout<<month<<"/"<<day<<"/"<<year<<"\n" ;
}
int main (){
	int d , m , y ;
	cout<<"ENTER THE DAY : " ;
	cin>>d ;
	cout<<"ENTER THE MONTH : " ;
	cin>>m ;
	cout<<"ENTER THE YEAR : " ;
	cin>>y ; 
	date c(1,1,1);
	c.set_data(d,m,y);
	c.display_date();
}
