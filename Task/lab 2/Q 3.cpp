#include<iostream>
using namespace std ;
int func (int n1 , int n2){
	int a  , i ,j ;
	for (i=n1 ; i<=n2 ; i++){
		for (j=2;j<=i/2;j++){
			a = i/j ;
			if ((a*a)==i){
				cout<<i<<endl;
			}
		}
	}
}
int main (){
	int n1 , n2  ;
	cout<<"Enter the Value of n1 And n2 : " ;
	cin>>n1>>n2 ;
	func(n1,n2);
}

