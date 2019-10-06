#include<iostream>
using namespace std ;
int main (){
	int num , i , sum = 0 , temp=0 , temp1=999999999; 
	for (i=0;i<5;i++){
		cin>>num ;
		sum = sum + num ;
		if (num>temp){
			temp=num ; 
		}
		if (num<temp1){
			temp1=num ;
		}
	}
	cout<<"AVG : "<<sum/5<<"\nGREATER NUM : "<<temp<<"\nSMALLER NUMBER : "<<temp1;	 
}
