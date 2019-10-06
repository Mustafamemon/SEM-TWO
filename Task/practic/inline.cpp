#include<iostream>
using namespace std ;
class employee{
	char name[20] ;
	int age  ;
	public :
	void set(char*,int); 
	void get() ;
};
inline void employee::set(char arr[4], int y){
	name[0]=arr[0];
	name[1]=arr[1];
	name[2]=arr[2];
	age=y ;
}
void employee::get(){
	cout<<name<<" ";
	cout<<age ;
}
int main (){
	employee s ;
	s.set("ALI",20);
	s.get();
	
}
