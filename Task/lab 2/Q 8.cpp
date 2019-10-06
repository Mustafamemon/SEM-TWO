#include<iostream>
using namespace std ;
int rev(int num , int reve){
	int temp ;
	if (num>0){
		return rev(num/10,++reve);
	}
	return reve ;
}
int main (){
	int  num , res ;
	cout<<"ENTER THE NUMBER : " ;
	cin>>num ;
	res=rev(num,0);
	cout<<res; 
}
