#include<iostream>
using namespace std ;
class phone{
	int area ;
	int exchange ;
	int cous ;
	long int no ;
public :
	~phone(){
		cout<<"\nOBJECT IS KILLED :(" ;
	}
	void check(){
		int temp ;
		temp = no/1000000000 ;
		if (temp==0){
		cout<<"WRONG NUMBER " ;
		exit(0);
	}
	}
	phone(long int ano){
		no = ano ;
	}
	void set_no(){
		area = no/100000000 ;
		no = no - (area*100000000);
		exchange = no /10000;
		no = no - (exchange*10000);
		cous = no ;
	}
	void show_no(){
		cout<<"Your Area code is: 0"<<area<<endl<<"Your Exchange Code is: "<<exchange<<endl<<"Your Consumer No is: "<<cous ;
	}
};
int main(){
	long int no ;
	cout<<"ENTER THE NUMBER : ";
	cin>>no;
	phone p(no);
	p.check();
	p.set_no();
	p.show_no();
}

