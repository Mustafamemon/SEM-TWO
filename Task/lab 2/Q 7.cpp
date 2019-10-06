#include<iostream>
using namespace std ;
int rev(int num , int reve){
	int temp ;
	if (num>0){
		temp = num%10 ;
		reve= (reve*10)+temp ;
		return rev(num/10,reve);
	}
	cout<<reve ;
}
int main (){
	int  num ;
	cout<<"ENTER THE NUMBER : " ;
	cin>>num ;
	rev(num,0);
}
