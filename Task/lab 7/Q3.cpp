#include<iostream>
using namespace std ;
class product{
private :
	string barcode ;
	string name ; 
public :
	product(){
		name ='\0' ;
		barcode = '\0' ;
	}
	product(string abar , string aname){
		name = aname ;
		barcode = abar ;
	}
	void setcode(string abar){
		barcode = abar ;
	}
	string getcode(){
		return barcode ;
	}
	void scanner(string aname , string abar){
		name = aname ;
		barcode = abar ; 
	}
	void print(){
		cout<<"\nNAME : "<<name ;
		cout<<"\nBARCODE  : "<<barcode ;
	}
};
class prepacked:public product{
private :
	float price ;
public :
	prepacked(){
		price = 0 ;
	}
	prepacked(float aprice){
		price = aprice ;
	}
	void setprice(float aprice){
		price = aprice ;
	}
	float getprice(){
		return price ;
	}
	void scanner(float aprice){
		price = aprice ; 
	}
	void print(){
		cout<<"\nPRICE : "<<price ;
	}
};
class fresh:public product{
private :
	float price_kilo ;
	float weight ;
public :
	fresh(){
		price_kilo = 0.0 ;
		weight = 0.0 ;
	}
	fresh(float aprice , float aweight){
		price_kilo = aprice ;
		weight = aweight ;
	}
	void setprice(float aprice){
		price_kilo = aprice ;
	}
	float getprice(){
		return price_kilo ;
	}
	void setweight(float aweight){
		weight = aweight ;
	}
	float getweight(){
		return weight ;
	}
	void scanner(float aprice ,float aweight ){
		weight = aweight ;
		price_kilo = aprice ;
	}
	void print(){
		cout<<"\nPRICE PER KILO : "<<price_kilo ;
		cout<<"\nWEIGHT : "<<weight ;
	}	
};
int main(){
	string name , barcode ;
	float price , price_kilo , weight ;
	cout<<"\n\tDEFAULT CONSTRUCTOR\n" ;
	product obj ;
	obj.print();
	prepacked obj3 ;
	obj3.print();
	fresh obj6 ;
	obj6.print();
	cout<<"\n\tPARAMETERIZED CONSTRUCTOR\n" ;
	product obj1("MUSTAFA","123456") ;
	obj1.print();
	prepacked obj4(1234);
	obj4.print();
	fresh obj7(12,2.5);
	obj7.print();
	cout<<"\n\tSCANNER AND PRINTER\n" ;
	cout<<"\nENTER THE NAME  : " ;
	cin>>name ;
	cout<<"ENTER THE BARCODE : " ;
	cin>>barcode ;
	cout<<"ENTER THE PRICE  :" ;
	cin>>price ;
	cout<<"ENTER THE PRICE PER KILO : " ;
	cin>>price_kilo ;
	cout<<"ENTER THE WEIGHT : " ;
	cin>>weight ;
	product obj2;
	obj2.scanner(name,barcode) ;
	obj2.print();
	prepacked obj5;
	obj5.scanner(price);
	obj5.print();
	fresh obj8 ;
	obj8.scanner(price_kilo,weight);
	obj8.print() ;
}
