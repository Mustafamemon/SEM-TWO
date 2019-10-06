#include<iostream>
#include<time.h>
#include<cstdlib>
#include<cstring>
using namespace std ;
int tem=0 , cnt=0 ;
class article {
private :
	int ID;
	string tit ;
	char *jour ;
	int issu;
	int year ;
	int sp ;
	int ep ;	
	char *auth ;
public :
	article(const article &a);
	article(int id);
	void input();
	void Display();
	void Group(article *a);
	int AVG(int f);
	int check(int f);
	int Check_Starting(int f);
};
