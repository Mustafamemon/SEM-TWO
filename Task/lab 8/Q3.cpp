#include<iostream>
using namespace std ;
class Acc{
protected :
	static float bal ;
public :
	void Deposite(float amo){
		bal = bal + amo ;
	}
	void withdraw(float amo){
		if (amo<=bal){
		bal = bal - amo ;
		cout<<"\n\t\tTHANKYOU!!\n";
		}
		else
		cout<<"\n\t\tINSUFFICIENT\n";
	}
	float check_Bal(){
		return bal ;
	}
};
float Acc::bal = 0 ;
class Interest  :virtual public Acc{
private :
	static float interest ;
public :
	void Deposite(float amo){
		bal = bal + amo + (amo*interest) ;
	}
};
float Interest::interest =0.3 ;
class Charging_Acc:virtual public Acc{
protected :
	static int fee ;
public :
	void withdraw(float amo){
		if ((amo+fee)<=bal){
		bal = bal -(float)fee - amo ;
		cout<<"\n\t\tTHANKYOU!!\n";
		}
		else
		cout<<"\n\t\tINSUFFICIENT\n";
	}
};
int Charging_Acc::fee = 3 ;
class ACI: public Interest ,public Charging_Acc {
public :
	void transfer(double amo , Acc *obj){
		obj->Deposite(amo);
	}
	void transfer (double amo , Interest *obj){
		obj->Deposite(amo);
	}
	void transfer (double amo , Charging_Acc *obj){
		obj->Deposite(amo);
	}
};
int main(){
	Interest obj ;
	Charging_Acc obj1 ;
	Acc obj2 ;
	ACI obj3 ;
	int x,y; 
	float amo ;
	do{
		cout<<"1:TRANSFER\n2:CHECK BALANCE\n3:WITH DRAW\n4:EXIT\n" ;
		cin>>x ;
	switch (x){
		case 1 :
			cout<<"1:ACCOUNT\n2:CHARGING ACCOUNT\n3:INTEREST ACCOUNT\n" ;
			cin>>y ;
			cout<<"ENTER THE AMOUNT : " ;
			cin>>amo ;
			if (y==1){
				obj3.transfer(amo,&obj2) ;	
			}
			else if (y==2){
				obj3.transfer(amo,&obj1);
			}
			else if (y==3){
				obj3.transfer(amo,&obj);
			}
			break ;
		case 2 :
			cout<<"\n\t\tBALANCE : "<<obj.check_Bal()<<"\n";
			break ;
		case 3 :
			cout<<"ENTER THE AMOUNT : " ;
			cin>>amo ;
			if (amo<=1000)
			obj.withdraw(amo);
			else
			obj1.withdraw(amo);
			break ;
	}
	}while(x!=4);
	return 0 ;
}

