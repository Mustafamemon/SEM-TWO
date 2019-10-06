#include<iostream>
#include<cmath>
using namespace std ;
class complex{
	int real ;
	int imag ;
public :
	void mag();
	void get_data(char a);	
	complex(int a , int b);
	complex add(complex d,char a);
	complex(complex &c);
	complex() : real(0),imag(0){
	}
	~complex(){
		cout<<"\nOBJECT IS KILLED\n";
	}
};
void complex::get_data(char a){	
	cout<<" "<<real<<" "<<a<<" "<<imag<<"i\n" ;
}
void complex::mag(){
	float z ;
	z = (float)((real)*(real)+ (imag)*(imag));
	z = pow(z,0.5);
	cout<<z ;
}
complex::complex(int a , int b){	
	real = a ;
	imag = b ;
}
complex::complex(complex &c){
	this->real = c.real ;
	this->imag = c.imag ;
}
complex complex::add(complex d , char a){
	complex res  ;
	res.real = real + d.real ;
	if (a=='+')
	res.imag = imag + d.imag ;
	else if (a=='-'){
	res.imag = imag - d.imag ;
	if(res.imag<0){
		res.imag = res.imag*-1 ;
	}
	return res ;
}
}
int main (){
	complex  c2 ;
	int x , y1 ,y2 ;
	char a,a1 ,a2 , b;
	cout<<"ENTER THE 1st COMPLEX NUMBER IN THIS FORM a + bi : " ;
	cin>>x>>a1>>y1>>b;
	complex c(x,y1);
	cout<<"ENTER THE 2nd COMPLEX NUMBER IN THIS FORM a + bi : " ;
	cin>>x>>a2>>y2>>b;
	if (a1==a2)
	a='+' ;
	else
	a='-' ;
	cout<<"\t\tADDITION : \n";
	complex c1(x,y2) ;
	c2 = c.add(c1,a);
	c.get_data(a1);
	c1.get_data(a2);
	if (y1>y2)
	a=a1;
	else
	a=a2;
	cout<<"+\n";
	cout<<"-------------\n" ;
	c2.get_data(a);
	cout<<"-------------\n" ;
	cout<<"\t\tMAGNITUDE : \n\n";
	cout<<"MAGNITUDE OF 1st COMPLEX NUMBER : " ;
	c.mag();
	cout<<"\n\nMAGNITUDE OF 2nd COMPLEX NUMBER : " ;
	c1.mag();
	cout<<"\n\nMAGNITUDE OF COMPLEX NUMBER AFTER ADDING : " ;
	c2.mag();
	complex c3(c2);
	
}
