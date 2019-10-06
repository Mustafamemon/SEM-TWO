#include<iostream>
using namespace std ;
class employee {
protected :
	string name ;
	string code ;
public :
employee(string na , string c){
	name = na ;
	code = c ;
}
};
class consultant : virtual public employee{
protected :
	int yearofExperiene ;
public :
	consultant (int y ,string na , string c):employee(na,c){
		yearofExperiene = y ;
	}
};
class manager : virtual public employee{
protected :
	int noofteam ;
public :
	manager(int n,string na , string c):employee(na,c){
		noofteam = n ;
	}
};
class consultantmanager : public consultant , public manager{
public :
	consultantmanager(string na , string c , int y , int n):manager(n,na,c),consultant(y,na,c),employee(na,c){
	}
	void Display()const{
		cout<<"NAME\tCODE\tY-O-E\tN-O-T\n" ;
		cout<<name<<"\t"<<code<<"\t"<<yearofExperiene<<"\t"<<noofteam ;
	}
};
int main(){
	consultantmanager cm("Ali","S-123",17,5) ;
	cm.Display();
	return 0 ;
}
