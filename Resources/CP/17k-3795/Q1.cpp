#include<iostream>
using namespace std ;
class pizza{
	int type ;
	int size ;
	int pep  ;
	int topp ;
public :
	void settter(int atype , int asize , int apep ,int atopp);
	int  gettype();
	int  getsize();
	int  getpep ();
	int  gettopp();
	void outdescri(double price);
	double computepric(); 
	~pizza(){
		cout<<"\n\n\nOBJECT IS KILLED\n";
	}  
};
void pizza::settter(int atype , int asize , int apep ,int atopp){
	type = atype ;
	size = asize ;
	pep  = apep  ;
	topp = atopp ;
}
void pizza::outdescri(double price){
	cout<<"TYPE : " ;
	switch (type){
	case 1 :
		cout<<"Deep Dish" ;
		break ;
	case 2 :
		cout<<"Hand Tossed" ;
		break ;
	case 3 :
		cout<<"Pan" ;	
		break ;
	default :
		cout<<"WRONG INPUT" ;
		break ;
}
	cout<<"\nSIZE : " ;
	switch (size){
	case 1 :
		cout<<"Small : \n\t\tPRICE : 10 ";
		break ;
	case 2 :
		cout<<"Medium : \n\t\tPRICE : 14 " ;
		break ;
	case 3 :
		cout<<"Large : \n\t\tPRICE : 17 " ;	
		break ;
	default :
		cout<<"WRONG INPUT" ;
		break ;
}
	cout<<"\n\nNo Of PEPPERONI : "<<pep;
	cout<<"\n\nNo Of Cheese Topping : "<<topp<<" \n\t\tPRICE : 2 --- 2*"<<topp<<" = "<<topp*2 ;
	cout<<"\n\nTOTAL PRICE : "<<price ;
}
double pizza::computepric(){
	double pric ;
	switch (size){
		case 1 :
			pric  = (10+(topp*2));
			break ;
		case 2 :
			pric  = (14+(topp*2)) ;
			break ;
		case 3 :
			pric  = (17+(topp*2)) ;
			break ;
		default :
			pric = (topp*2) ;
			break ;
	}
	return pric ;
}
int main (){
	pizza p ;
	int a , b , c , d ;
	double ab ;
	cout<<"MENU :\n\t\tTYPE\n1 : Deep Dish\n2 : Hand Toosed\n3 : Pan\n\t\tSIZE\n1 : Small\n2 : Mediun\n3 : Large\nENTER THE TYPE : ";
	cin>>a ;
	cout<<"ENTER THE SIZE : " ;
	cin>>b ;
	cout<<"ENTER THE NO OF PEPPERONI : "; 
	cin>>c ;
	cout<<"ENTER THE NO OF TOPPING : " ;
	cin>>d ;
	p.settter(a,b,c,d) ;
	ab=p.computepric();
	p.outdescri(ab);
}
