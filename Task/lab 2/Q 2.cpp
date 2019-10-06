#include<iostream>
using namespace std ; 
static int cnt  ;
int *divisor(int num){
	int i , *ptr ;
	ptr=new int [20];
	for (i=1;i<=num;i++){
		if (num%i==0){
			ptr[cnt]=i;
			++cnt ;
		}
	}
	return ptr ;
}
int main (){
	int num  , *res , i;
	res = new int[10];
	cout<<"Enter the Number : " ;
	cin>>num ;
	res=divisor(num);
	for (i=0;i<cnt;i++){
		cout<<res[i]<<" " ;
	}
}
