#include<iostream>
using namespace std ;
class student ;
class Person{
public :
	string name ;
	friend student ;
};
class student:public Person{
//	friend Person ;
	int roll ;
	int sems ;
	char sec ;
public :
	student(string name , int roll , int sems , char sec ){
		this->name = name ;
		this->roll = roll ;
		this->sec = sec ;
		this->sems = sems ;
	}
	void get_data(){
		cout<<"\nNAME : "<<name<<endl<<"ROLL NO : "<<roll<<endl<<"SECTION : "<<sec<<endl<<"SEMESTER : "<<sems ;
	}
	friend void func(student*,Person*);
};
void func(student *obj,Person*obj1){
	obj1->name = "KILL" ;
	obj->roll = 123 ;
	obj->sems = 5 ;
	obj->sec = 'E' ;
}
int main(){
	Person s1 ;
	student s("MUSTAFA",173795,2,'E');
	s.get_data();
	func(&s,&s1);
	s.get_data();
}
