#include<iostream>
using namespace std ;
class Location{
	int latitude  ;
	int longitude ;
public :
	Location(){
		latitude =  0 ;
		longitude = 0 ;
	}
	Location(int a ,int b){
		latitude =  a ;
		longitude = b ;
	}
	virtual void Display ()const{
		cout<<"\nLATITUDE : "<<latitude ;
		cout<<"\nLONGITUDE : "<<longitude ;
	}
	//pre
	Location operator ++(){
		++latitude  ;
		++longitude ;
		return *this ;
	}
	//post
	Location operator ++(int){
		Location obj(*this);
		latitude++;
		longitude++;
		return obj;
	}
	friend Location operator +(int a,Location obj){
		Location temp ;
		temp.latitude=obj.latitude+a ;
		temp.longitude=obj.longitude+a ;
		return temp ;
	}
};
class Detail : public Location{
private :
	string address ;
public :
	Detail(string a,int b,int c):Location(b,c){
		address = a ;
	}
	void Display()const{
		cout<<"\nADDRESS : "<<address ;
	}
	
};
int main(){
	Detail obj("ABCD",10,20);
	Location obj1(10,20),obj2(5,30),obj3(90,90);
	cout<<"\nDATA OF OBJ :\n" ;
	obj.Display();
	cout<<"\nDATA OF OBJ 1 :\n" ;
	obj1.Display();
	cout<<"\nDATA OF OBJ 2 :\n" ;
	obj2.Display();
	cout<<"\nDATA OF OBJ 3 :\n" ;
	obj3.Display();
	++obj1 ;
	cout<<"\nAFTER INCREMENT :\n" ;
	obj1.Display();
	obj2=obj1++;
	cout<<"\nAFTER INCREMENT & ASSIGNING:\n" ;
	obj2.Display();	
	obj2=10+obj1 ;
	cout<<"\nAFTER ADDITION :\n" ;
	obj2.Display();
	obj1=obj2=obj3 ;
	cout<<"\nAFTER ASSIGNMENT :\n" ;
	cout<<"\n" ;
	obj1.Display();
	cout<<"\n" ;
	obj2.Display();
	cout<<"\n" ;
	obj3.Display();
	cout<<"\n\n\n" ;
	Location *ptr =&obj;
	ptr->Display();
	return 0 ;
}
