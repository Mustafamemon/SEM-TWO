#include<iostream>
using namespace std ;
class sales{
	int id ;
	string name ;
	int qty ;
public :
	~sales(){
		cout<<"\nOBJECT IS DELETED :(" ;
	}
	sales(){
		id = 0 ;
		name  = '\0' ;
		qty = 0 ;
	}
	sales(int id){
		this->id = id ;
		fflush(stdin);
		cout<<"ENTER THE ITEM NAME : " ;
		getline(cin,name) ;
		cout<<"ENTER THE QUANTITY : " ;
		cin>>qty ;
	}
	sales(int id , string name , int qty){
		this->id = id ;
		this->name = name ;
		this->qty = qty ;
	}
	sales(const sales &obj){
		id = obj.id;
		name = obj.name ;
		qty = obj.qty ;
	}
	void get_data(){
		cout<<"ID :"<<id<<endl<<"ITEM NAME :"<<name<<endl<<"QAUANTITY : "<<qty<<endl ;
	}
};
int main(){
	int sid ;
	sales s ;
	cout<<"AFTER DEFAULT CONSTRUCTOR : \n";
	s.get_data();
	cout<<"ENTER THE ID : " ;
	cin>>sid ;
	sales s1(sid) ;
	cout<<"AFTER PARAMETERIZED CONSTRUCTOR : \n";
	s1.get_data();
	sales s2(173795,"MUSTAFA",10);
	cout<<"AFTER VALUE OF OWN CHOICE : \n";
	s2.get_data();
	sales s3(s2);
	cout<<"AFTER COPYING CONSTRUCTOR : \n";
	s3.get_data();
	
}
