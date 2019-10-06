#include<iostream>
using namespace std ;
void func(int num , int *ptr){
	int i ,cnt=0 ;
	cout<<"ENTER THE NUMBER  : " ;
	for (i=0;i<num;i++){
		cin>>ptr[i];
	}
	int temp ,a ;
	if (num%2==0)
	a=num/2;
	else
	a=(num-1)/2 ;
	for (i=num-1;i>=a;i--){
		temp = ptr[cnt];
		ptr[cnt]=ptr[i] ;
		ptr[i]=temp;
		cnt++;	
	}
	for (i=0;i<num;i++){
		cout<<ptr[i]<<" ";
	}
}
int main (){
	int num , arr[50];
	cout<<"Enter how many  Number : " ;
	cin>>num ;
	func(num,arr);
}
