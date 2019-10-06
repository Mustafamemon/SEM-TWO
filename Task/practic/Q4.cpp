#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std ;
int cnt = 0  , cnt1 = 0 ;
class game {
public :
int yteam(){
	srand(time(NULL)) ;
	int i=rand()%10 ;
	cout<<"TOTAL NO OF PLAYER IN YOUR TEAM : "<<i  ;
	return i ;	
}
void pair(){
	int x , y ;
	x=rand()%10; y=rand()%10 ;
	cout<<"\nPAIR OF NUMBERS :\n" ;
	cout<<"NUMBER 1 : "<<x ;
	cout<<"\nNUMBER 2 : "<<y ;
	if (x==y)
	{
		cout<<"\n\nEnemy got hit by your team!\n" ;
			cnt++ ;
	}
	else
	{
		cout<<"\n\nYou got hit by the enemy team!\n" ;
		cnt1++ ;	
	}
}
};
int main (){
	game k ;
	int a , i ;  
	a=k.yteam() ;
	for (i=0;i<a;i++){
		k.pair();
	}
	cout<<"\t\tGAME OVER : " ;
	if (cnt>cnt1)
	cout<<"\n\n\tYOU WON!" ;
	else if (cnt<cnt1)
	cout<<"\n\n\tENEMY WON!" ;
	else
	cout<<"DRAW" ;
}
