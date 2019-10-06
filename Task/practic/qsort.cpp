#include<iostream>
#include<stdlib.h>
using namespace std;
int func(const void *x ,const void *y );
int func1(const void *x ,const void *y );
int main (){
	int n , i ;
	cout<<"Enter the number of array : " ;
	cin>>n ;
	int arr[n] ;
	for (i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"\nBefore Sort  :\n\t";
	for (i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	qsort(arr,n,sizeof(int),func);
	cout<<"\nAfter Sort  :\n\t";
	cout<<"Ascending :\n\t\t\t" ;
	for (i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	qsort(arr,n,sizeof(int),func1);
	cout<<"\n\tDescending :\n\t\t\t" ;
	for (i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int func(const void *x , const void *y ){
	int *xx , *yy ;
	xx=(int *)x;
	yy=(int *)y;
	return (*xx-*yy);
}
int func1(const void *x , const void *y ){
	int *xx , *yy ;
	xx=(int *)x;
	yy=(int *)y;
	return (*yy-*xx);
}
