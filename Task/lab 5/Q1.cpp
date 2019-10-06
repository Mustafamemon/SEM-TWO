#include<iostream>
#include<cstring>
using namespace std ;
class Employee {
private :;
	char * emp_Name ;
	const int emp_ID ;
public :
	Employee(int id):emp_ID(id){
		emp_Name  = new  char[1] ;
		emp_Name = '\0' ;
	}
	void mutator_Name(char *name){
		emp_Name  = new  char[strlen(name)] ;
		strcpy(emp_Name,name) ;
	}
	void acessor_name(){
		cout<<"NAME : "<<emp_Name ;
	}
	const void acessor_id(){
		cout<<"\nID : "<<emp_ID ;
	}
};
int main(){
	int id ;
	char name [10];
	cout<<"\t\t\tFOR FIRST EMPLOYEE: " ;
	cout<<"\nENTER THE EMPLOYEE NAME : " ;
	cin>>name ;
	cout<<"ENTER THE EMPLOYEE ID : " ;
	cin>>id ;
	Employee employee1(id) ;
	employee1.mutator_Name(name);
	cout<<"\t\t\tFOR SECOND EMPLOYEE: " ;
	cout<<"\nENTER THE EMPLOYEE NAME : " ;
	cin>>name ;
	cout<<"ENTER THE EMPLOYEE ID : " ;
	cin>>id ;
	Employee employee2(id) ;
	employee2.mutator_Name(name);
	cout<<"\t\t\tFOR THIRD EMPLOYEE: " ;
	cout<<"\nENTER THE EMPLOYEE NAME : " ;
	cin>>name ;
	cout<<"ENTER THE EMPLOYEE ID : " ;
	cin>>id ;
	Employee employee3(id) ;
	employee3.mutator_Name(name);
	cout<<"\n\t\t\tFOR FIRST EMPLOYEE:\n" ;
	employee1.acessor_name();
	employee1.acessor_id();
	cout<<"\n\t\t\tFOR SECOND EMPLOYEE:\n" ;
	employee2.acessor_name();
	employee2.acessor_id();
	cout<<"\n\t\t\tFOR THIRD EMPLOYEE:\n" ;
	employee3.acessor_name();
	employee3.acessor_id();
}
