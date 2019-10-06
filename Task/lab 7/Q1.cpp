#include<iostream>
using namespace std ;
class person{
private :
	int age ;
protected :
	string name ;
public :
	int get_age()const{
		return age ;
	}
	string get_name()const{
		return name ;
	}
	person(int a , string n){
		age = a ;
		name = n ; 
	}
};
class employee{
private :
	int empid;
protected  :
	int salary ;
public :
	int get_id()const{
		return empid ;
	}
	int get_sal()const{
		return salary ;
	}
	employee(int id , int sal){
		empid = id ;
		salary = sal ;
	}
};
class Manager : public person, public employee{
private: 
	string type;
public :
	Manager(string atype , int a , string aname , int aid , int asal):person(a,aname),employee(aid,asal){
		type = atype ;
	}
	string get_type()const{
		return type ;
	}
};
class ITmanager : public Manager{
private :
	int person ;
public :
ITmanager(int aperson , string atype ,int aid , int asal ,int a , string aname ):Manager(atype,a,aname,aid,asal){
		person = aperson ;
}
void Display()const{
	cout<<"\n\tAGE\tNAME\t\tEMP-ID\tSALARY\tTYPE\tPERSON\n";
	cout<<"\t"<<get_age()<<"\t"<<get_name()<<"\t"<<get_id()<<"\t"<<get_sal()<<"\t"<<get_type()<<"\t"<<person ;
}
};
int main(){
	int age , id , sal , person ;
	string name , type ;
	cout<<"ENTER THE NAME OF EMPLOYEE : " ;
	getline(cin,name);
	cout<<"ENTER THE AGE OF THE EMPLOYEE : " ;
	cin>>age;
	cout<<"ENTER THE EMPLOYEE ID : " ;
	cin>>id;
	fflush(stdin);
	cout<<"ENTER THE EMPLOYEE SALARY : " ;
	cin>>sal;
	fflush(stdin);
	cout<<"ENTER THE TYPE : " ;
	cin>>type;
	fflush(stdin);
	cout<<"ENTER THE NO OF PERSON :" ;
	cin>>person;
	ITmanager obj(person,type,id,sal,age,name);
	obj.Display();
	return 0 ;
}
