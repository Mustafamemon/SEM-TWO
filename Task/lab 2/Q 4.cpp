#include<iostream>
using namespace std ;
void func(int num){
	int i ,j , flag=1 ;
	for (i=2;i<=num;i++){
		for (j=2;j<=(i/2);j++){
		if ((i%j)==0){
			flag = 0 ;
			break ;
		}
	}
	if (flag==1){
		cout<<i<<endl ;
	}
	else
	flag=1;
	}	
}
void func1(int num){
	int i , flag=1 ;
	for (i=2;i<num;i++){
		if ((num%i)==0){
			flag = 0 ;
			break ;
		}
	}
	if (flag==1)
	cout<<"PRIME NO"; 	
	else
	cout<<"NOT PRIME NO" ;
}
int main (){
	int num ,ch;
	cout<<"1:TEST THE NUMBER \n2:RANGE  : " ;
	cin>>ch ;
	if (ch==2)
	cout<<"ENTER THE ENDING POINT : " ;
	else if (ch==1)
	cout<<"ENTER THE NUMBER : ";
	else
	main () ;
	cin>>num ;
	if (ch==2)
	func(num);
	else 
	func1(num);
}
