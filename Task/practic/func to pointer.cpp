#include<iostream>
using namespace std ; 
int (*papa[4])(int,int);
int func0(int a,int b){
	return a+b; 
}
int func1(int a,int b){
	return a-b; 
}
int func2(int a,int b){
	return a*b; 
}

int func3(int a,int b){
	return a/b; 
}
int main (){
	int num  , i;
	int (*papa[4])(int,int);
	papa[0]=&func0 ;
	papa[1]=func1; 
	papa[2]=func2;
	papa[3]=func3;
	cin>>num ;
	cout<<(papa)[num](2,3);
	 
	
}
