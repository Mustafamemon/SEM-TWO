#include<iostream>
using namespace std ;
class PrimeNumber{
private:
	int prime ;
public: 
	PrimeNumber(){
		prime = 1 ;
		 
	}
	PrimeNumber(int a){
		prime = a ;  
	}
	void get_prime(int a){
		prime = a ;
	}
	//pre
	PrimeNumber operator ++(){
		int i ;
		++prime;
		for(i=2;i<prime;i++){
			if (prime%i==0){
				++prime;
				i=2;  
			}
		}
		return *this ;
	}
	//post
	PrimeNumber operator ++(int){
		PrimeNumber P=(*this);
		int i;
		prime++ ;
		for(i=2;i<prime;i++){
			if (prime%i==0){
				prime++;
				i=2;
			}
		}
		return P;
	}
	//post
	PrimeNumber operator --(int){
		PrimeNumber P=(*this);
		int i;
		if (prime>1){
			prime-- ;
			for(i=(prime-1);i>=2;i--){
				if (prime%i==0){
					--prime;
					i=prime ;
				}
			}
		}
		return P ;
	}
	//pre 
	PrimeNumber operator --(){
		int i ;
		if (prime>1){
			--prime ;
			for(i=(prime-1);i>=2;i--){
				if (prime%i==0){
					--prime;
					i=prime ;
				}
			}
		}		
		return *this ;
	}
	void Display(){
		cout<<prime ;
	}
};
int main(){
	PrimeNumber p ;
	int a ; 
	do{
	cout<<"\n1:POST-INCREMENT\n2:PRE-INCREMENT\n3:POST-DECREMENT\n4:PRE-DECREMENT\n5:EXIT\n" ;
	cin>>a ;
	if (a==1)
	p++ ;
	else if(a==2)
	++p ;
	else if(a==3)
	p--;
	else if(a==4)
	--p ; 
	p.Display() ;
	}while(a!=5);
	
}
