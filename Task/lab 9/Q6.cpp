#include<iostream>
using namespace std ;
class meal{
private :
	string name ;
	int calorie ;
public :
	meal(string n="DAILY-TOTAL",int c = 1){
		name = n;
		calorie = c; 
	}
	meal operator +(meal&c){
		meal temp ;
		temp.calorie=calorie+c.calorie ;
		return temp ;
	}
	friend ostream& operator<<(ostream&,const meal&);
	friend istream& operator>>(istream&,meal&);
};
ostream& operator<<(ostream&output,const meal&c){
	output<<"NAME : "<<c.name ;
	output<<"\nCALORIE :"<<c.calorie ;
}
istream& operator>>(istream&input,meal&c){
	cout<<"ENTER NAME : " ;
	input>>c.name ;
	cout<<"ENTER CALORIE :";
	input>>c.calorie ; 	
}
int main(){
	meal breakfast,lunch,dinner,total ;
	cout<<"\nFOR BREAKFAST\n";
	cin>>breakfast;
	cout<<"\nFOR LUNCH\n";
	cin>>lunch;
	cout<<"\nFOR DINNER\n";
	cin>>dinner;
	total=breakfast+lunch+dinner ;
	cout<<"\nREAKFAST\n";
	cout<<breakfast;
	cout<<"\nLUNCH\n";
	cout<<lunch;
	cout<<"\nDINNER\n";
	cout<<dinner;
	cout<<"\nTOTAL\n";
	cout<<total;
}
