#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
using namespace std ;
int main(){
	int n ;
	cin>>n ;
	char **str,**str1 ;
	str = new char*[n];
	str1 = new char*[n];
	for (int i=0;i<n;i++){
		str[i] = new char[20];
		str1[i] = new char[20];
		fflush(stdin) ;
		cin>>str[i] ;
		fflush(stdin) ;
		cin>>str1[i];
	}
	/*for (int i=0;i<n;i++){
		cout<<str[i] ;
		cout<<str1[i];
	}*/
	int f=1,h ;
		for (int i=0;i<n;i++){
			int a = strlen(str[i]);
			int b = strlen(str1[i]);
			if (a>b)
			h = b;
			else
			h = a ;
			for (int j=0;j<h;j++){
				for(int k=0;k<h;k++){
					if (str[i][j]==str1[i][k]){
						f=0 ;
						break ;
					}
				}
				if (f==0)
				break ;
			}
			if (f==0){
			cout<<"YES"<<endl ;
			f=1 ;}
			else if (f==1)
			cout<<"NO"<<endl ;
	}
	delete str ;
	delete str1 ; 
	return  0 ;
}
