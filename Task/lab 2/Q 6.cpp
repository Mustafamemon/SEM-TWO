#include<iostream>
using namespace std ;
int *func(int sec){
	int temp , *ptr;
	ptr = new int[3];
	temp = sec / 3600 ;
	ptr[0]=temp ; 
	sec=sec - (temp*3600) ;
	temp = sec / 60 ;
	ptr[1]=temp ;
	sec=sec - (temp*60) ;
	ptr[2]=sec ;
	return ptr ;
}
int main(){
	int sec , *ptr ;
	cout<<"ENTER THE TIME IN SECOND : " ;
	cin>>sec;
	ptr=func(sec);
	cout<<ptr[0]<<" HOURS "<<ptr[1]<<" MIN "<<ptr[2]<<" SEC " ;
}

