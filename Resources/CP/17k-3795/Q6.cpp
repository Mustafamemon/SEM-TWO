#include<iostream>
using namespace std ;
class fraction{
	int num ;
	int deno ;
public : 
	void set_num(int anum);
	void set_deno(int adeno);
	double divide ();
	void additional ();
	~fraction(){
		cout<<"\nOBJECT IS KILLED\n";
	}
};
void fraction::set_num(int anum){
	num = anum ;
}
void fraction::set_deno(int adeno){
	deno = adeno ;
}
double fraction::divide (){
	double temp ;
	temp = (double) num/deno ;
	return temp ;
}
void fraction::additional (){
	int a , i = 1 ;
	if (num>deno)
	a = deno;
	else
	a = num ;
	if (a!=0){
	for (i=a;i>0;i--){
		if((num%i)==0 && (deno%i)==0)
			break ;
	}
	}
	if (deno/i!=1)
	cout<<num/i<<"/"<<deno/i ;
	else
	cout<<num/i ;
}
int main (){
	int Num , Deno ;
	fraction f ;
	cout<<"ENTER THE NUMERATOR : " ;
	cin>>Num ;
	f.set_num(Num);
	cout<<"ENTER THE DENOMENATOR " ;
	cin>>Deno ;
	f.set_deno(Deno);
	cout<<"DIVISION : "<<f.divide()<<"\nFRACTION : ";
	f.additional();
	return 0 ;
}
