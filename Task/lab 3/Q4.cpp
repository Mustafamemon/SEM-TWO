#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std ;
class Game{
	int cnt ;
	int cnt1 ;
public :
	Game(){
		cnt=0 ;
		cnt1=0; 
	}
	int player(){
		srand(time(NULL));
		int a = rand()%10 ;
		cout<<"No of Player in your team : "<<a ;
		return a ;
	}
	void pair(){
		cout<<"\nPAIR OF NUMBES : \n" ;
		int b , c ;
		b=rand()%10;
		c=rand()%10 ;
		cout<<"NUMBER 1 : "<<b ;
		cout<<"\nNUMBER 2 : "<<c ;
		if (b==c)
		{
			cnt++ ;
			cout<<"\n\nEnemy got hit by your team!\n";
		}
		else
		{
			cnt1++ ;
			cout<<"\n\nYou got hit by the enemy team!\n" ;
		}
	}
	void result(){
		if (cnt>cnt1)
	cout<<"\n\n\tYOU WON!" ;
	else if (cnt<cnt1)
	cout<<"\n\n\tENEMY WON!" ;
	else if(cnt==cnt)
	cout<<"\n\n\tDRAW" ;
}
};
int main (){
	int i ;
	Game g ;
	i=g.player();
	while(i>0){
		g.pair();
		--i ;
	}
	cout<<"\t\tGAME OVER" ;
	g.result();
}
