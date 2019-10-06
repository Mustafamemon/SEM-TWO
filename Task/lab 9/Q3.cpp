#include<iostream>
using namespace std ;
class Time{
private :
	int sec ;
	int min ;
	int hr ;
public :
	Time(int s , int m , int h){
		sec = s ;
		min = m ;
		hr= h ;
	}
	void Display(){
		cout<<"\n\n"<<hr<<':' <<min<<':'<<sec ;
	}
	Time operator +(Time obj){
		Time temp(0,0,0) ;
		int a=0;
		temp.sec=sec+obj.sec;
		if(temp.sec>=60){
			a=temp.sec/60 ;
			temp.sec=temp.sec-(a*60) ;
		}	
		else
		a=0 ;
		temp.min=min+obj.min+a;
		if(temp.min>=60){
			a=temp.min/60 ;
			temp.min=temp.min-(a*60) ;
		}
		temp.hr=hr+obj.hr+a;
		if (temp.hr>=23){
			temp.hr=temp.hr-24 ;
		}
		temp.Display();
	}
	bool operator <(Time obj){
		if (hr<obj.hr)
		return true ;
		else if(hr==obj.hr){
			if (min<obj.min)		
				return true ;
			else if (min==obj.min){
				if(sec<obj.sec)
				return true ;
				else
				return false ;
			}
			else
			return false ;
			
		}
		else
		return false ;
	}
};
int main(){
	Time t1(53,56,14),t2(55,54,13);
	Time t3 (0,0,0);
	t3 = t1+t2 ;
	if (t1<t2){
		cout<<"\nt1<t2" ;	
	}
	else
	cout<<"\nt1>t2" ;
}
