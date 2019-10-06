#include<iostream>
using namespace std ;
class bank{
private:
	string Name ;
	int Acc_num ;
	string Type_acc ;
	static float Balance  ;
	static float Rate_int ;
public :
	bank(){
		Name ='\0' ;
		Acc_num = 0 ;
		Type_acc = '\0' ;
		Balance = 0.0 ;
		Rate_int = 0.0 ;
	}
	bank(string Nam , int Acc ,string Type){
		Name = Nam ;
		Acc_num = Acc ;
		Type_acc = Type ; 
		Balance = 0.0 ;
	}
	~bank(){
		cout<<"OBJ IS KILLED" ;
	}
	void with_draw(float amo){
		cout<<"ENTER THE AMOUNT  :" ;
		cin>>amo ;
		if (amo<=Balance){
			cout<<"THANKYOU!!!!!!!!!" ;
			Balance  = Balance - amo ;
		}
		else
		cout<<"INSUFFICIENT BALANCE" ;
	}
	void deposite(float amo){
		cout<<"ENTER THE AMOUNT  :" ;
		cin>>amo ;
		Balance  = Balance + amo +(amo*Rate_int) ;
	}
	void Display(){
		cout<<"\nNAME :"<<Name<<"\nACCOUNT NUMBER :"<<Acc_num<<"\nACCOUNT TYPE :"<<Type_acc<<"\nBALANCE :"<<Balance ;
	}
	static void Rate_Int(){
		cout<<"RATE OF INTEREST : "<<Rate_int;
	}
};
float bank::Rate_int = 0.15 ;
float bank::Balance  ;
int main(){
	float amo ;
	int a ,acc ;
	string name , type ;
	cout<<"ENTER THE NAME : ";
	cin>>name ;
	cout<<"ENTER THE ACCOUNT NUMBER :" ;
	cin>>acc  ;
	cout<<"ENTER THE ACCOUNT TYPE " ;
	cin>>type ; 
	bank b(name,acc,type);
	do{
	cout<<"\n1:To Deposit Amount\n2:To Withdraw Amount\n3:To Display\n4:Display Rate of Interest\n5:EXIT :";
	cin>>a ;	
	switch (a){
		case 1 :
			b.deposite(0);
			break ;
		case 2:
			b.with_draw(0);
			break ;
		case 3:
			b.Display();
			break ;
		case 4:
			b.Rate_Int();
			break ;
	}
	}while(a!=5);
}
