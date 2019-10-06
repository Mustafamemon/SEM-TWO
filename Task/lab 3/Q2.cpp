#include<iostream>
#include<stdlib.h>
using namespace std ;
class employee{
	char *fname ;
	string lname ;
	int sal ;
public :
	employee(){
		fname=NULL ;
		lname='\0' ;
		sal =0 ;
	}
void setfname(char f[]){
	fname=f ;
}
void setlname(string l){
	lname=l ;
}
void setsal(int s){
	if(s>0)
	sal=s*12 ;
}
void get(){
	cout<<"SALARY "<<sal;
}
int increasesal(){
	int temp ;
	temp = sal + (sal*0.1) ;
	return temp ;
}
};
int main (){
	employee e1,e2 ;
	char fname[20] ; string lname ; int sal ;
	cout<<"ENTER THE NAME AND SALARY OF 1st EMPLOYEE : " ;
	cin>>fname>>lname>>sal ;
	e1.setfname(fname)	;
	e1.setlname(lname) ;
	e1.setsal(sal);
	e1.get() ;
	cout<<"\n" ;
	cout<<"ENTER THE NAME AND SALARY OF 2nd EMPLOYEE : " ;
	cin>>fname>>lname>>sal ;
	cout<<"\n" ;
	e2.setfname(fname)	;
	e2.setlname(lname) ;
	e2.setsal(sal);
	e2.get();
	cout<<"\nINCREASE SALARY : "<<e1.increasesal() ;
	cout<<"\nINCREASE SALARY : "<<e2.increasesal() ;
}
