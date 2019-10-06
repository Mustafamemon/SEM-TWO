#include<iostream>
using namespace std ;
class student{
	char *nam ;
	int roll ;
	double mark[5] ;
	float perc ;
	public :
	student()
	{
		/*nam = new char[1] ;
		*nam = '\0';     
		roll = 0 ;
		for (int i=0;i<4;i++){
			mark[i] = 0 ;
		}*/
		perc = 0 ;
		nam = new char[1];
		cout<<"ENTER THE NAME : " ;
		cin>>*nam ;
		fflush(stdin) ;
		cout<<"ENTER THE ROLL NO : " ;
		cin>>roll ;
		for (int i=0;i<5;i++){
			cout<<"ENTER THE "<<i+1<<" SUBJECT MARKS : " ;
			cin>>mark[i];
			perc = perc + mark[i] ;
		}
	}
void percent(){
	perc = (perc/500)*100 ;
	cout<<"PERCENTAGE : "<<perc<<endl ;
}
void grade(){
	percent() ;
	cout<<"GRADE : " ;
	if (perc>=90)
			cout<<"A+" ;
			else if (perc>=86 && perc<=89)
			cout<<"A" ;
			else if (perc>=82 && perc<=85)
			cout<<"A-" ;
			else if (perc>=78 && perc<=81)
			cout<<"B+" ;
			else if (perc>=74 && perc<=80)
			cout<<"B" ;
			else if (perc>=70 && perc<=73)
			cout<<"B-" ;
			else if (perc>=66 && perc<=69)
			cout<<"C+" ;
			else if (perc>=62 && perc<=65)
			cout<<"C" ;
			else if (perc>=58 && perc<=61)
			cout<<"C-" ;
			else if (perc>=54 && perc<=57)
			cout<<"D+" ;
			else if (perc>=50 && perc<=53)
			cout<<"D" ;
			else if (perc>=0 && perc<=49)
			cout<<"F" ;
			}
};
int main (){
	student s ;
	s.grade();
}
