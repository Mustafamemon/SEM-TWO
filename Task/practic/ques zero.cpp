#include<iostream>
using namespace std ;
int main(){
	long long int i , j , temp = 0 ,cnt = 0 , temp1 = 0  , rev= 0 , num = 1 ,p ;
	cout<<"ENTER THE RANGE : " ;
	cin>>p ;
	cout<<num<<"," ;
	for(j=0;j<p;j++){
	while(num!=0){
		temp = num%10 ;
		rev = (rev*10) +temp ; 
		num/=10 ;	
	}
	while (rev!=0){
		temp = rev%10 ;
		temp1=temp;
		while(temp1==temp){
			temp1 = rev%10 ;
			if(temp1==temp){
				cnt++ ;
				rev/=10 ;
			}
		}
		cout<<cnt<<temp;
		num = (num*100)+(cnt*10)+temp;
		cnt=0;
		temp1 = 0 ;
	}
	cout<<"," ;
	if(j==5)
	cout<<"\n" ;
}
cout<<"\b " ;
}
