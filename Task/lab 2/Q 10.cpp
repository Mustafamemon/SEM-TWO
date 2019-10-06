#include<iostream>
using namespace std ;
int main (){
	int *ptr , *ptr1 , temp= 0 , i ,j;
	ptr = new int[10];
	cout<<"ENTER THE 10 NUMBERS : " ;
	for (int i=0;i<10;i++){
		cin>>ptr[i];
	}
	ptr1 = new int[10];
	for (int i=0;i<10;i++){
		ptr1[i]=ptr[i];
	}
	for (i=0;i<10;i++){
		for (j=i+1;j<10;j++){
			if (ptr1[i]>ptr1[j]){
					temp = ptr1[j] ;
					ptr1[j] = ptr1[i] ;
					ptr1[i] = temp ;
			}
		}
	}
	cout<<"		Original Array\n\n" ;
	for (i=0;i<10;i++){
		cout<<ptr[i]<<" ";
	}
	cout<<"\n\n		Ascending Order\n\n" ;
	for (i=0;i<10;i++){
		cout<<ptr1[i]<<" ";
	}
	cout<<"\n\n		Descending Order\n\n" ;
	for (i=9;i>=0;i--){
		cout<<ptr1[i]<<" ";
	}
}
