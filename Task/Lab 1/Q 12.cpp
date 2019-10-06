#include<iostream>
using namespace std ;
int main (){
	int  num , x ;
	cout<<"ENTER THE 3-digit NUMBER ";
	cin>>num ;
	char ones[9][10]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"},tens[9][10]={"Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninty"},ten[9][10]={"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Ninteen"};
	x=num/100; 
	num=num-(x*100);
	x-- ;
	if (x>-1)
	cout<<ones[x]<<" Hundred";
	if (x>-1 && num > 0)
	cout<<" and ";
	x=num/10;
	num=num-(x*10);
	if (x==1 && num >0){
		num--;
		if (num>-1)
		cout<<ten[num];	
	}
	else if (x>-1){
		x--;
		cout<<tens[x] ;
		num--;
		if (num>-1)
		cout<<ones[num];	
	}

}
