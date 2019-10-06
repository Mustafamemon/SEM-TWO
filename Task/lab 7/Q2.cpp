#include<iostream>
using namespace std ;
class employee{
private  :
	string name ;
	int number ;
public :
	employee(string aname , int anumber ){
		name = aname ;
		number = anumber ; 
	}
	string getname(){
		return name ;
	}
	int getnum(){
		return number ;
	}
};
class manager : public employee{
private :
	string title ;
	int clubdues ;
public :
	manager (string atitle , int aclubdues,string aname ,int anumber):employee(aname,anumber){
		title = atitle ;
		clubdues = aclubdues ;
	}
	void Display(){
		cout<<"\n\tL-NAME\tNUMBER\tTITLE\tCLUDDUES\n" ;
		cout<<"\t"<<getname()<<"\t"<<getnum()<<"\t"<<title<<"\t"<<clubdues ;
	}
};
class scientist : public employee{
private :
	string title ;
	int publ ;
public :
	scientist (string atitle , int apubl,string aname ,int anumber):employee(aname,anumber){
		title = atitle   ;
		publ = apubl ;
	}
	void Display(){
		cout<<"\n\tL-NAME\tNUMBER\tTITLE\tPUBLICATION\n" ;
		cout<<"\t"<<getname()<<"\t"<<getnum()<<"\t"<<title<<"\t"<<publ ;
	}
};
class laborer : public employee{
private :
	string title ;
public :
	laborer(string atitle,string aname ,int anumber):employee(aname,anumber){
		title = atitle ;
	}
	void Display(){
		cout<<"\n\tL-NAME\tNUMBER\tTITLE\n" ;
		cout<<"\t"<<getname()<<"\t"<<getnum()<<"\t"<<title ;
	}
};
int main(){
	string name ,title;
	int num , a ,pub,clubdues;
	cout<<"ENTER THE LAST NAME  : " ;
	cin>>name ;
	cout<<"ENTER THE NUMBER : " ;
	cin>>num ;
	do{
	cout<<"\n1:MANAGER\n2:SCIENTSIST\n3:LABORER\n5:EXIT\n" ;
	cin>>a ;
	if (a!=4 && a!=5){
	cout<<"ENTER THE TITLE : " ;
	cin>>title ;
	}
	if (a==1){
	cout<<"ENTER THE CLUB DUES : " ;
	cin>>clubdues ;
	manager obj2(title,clubdues,name,num);
	cout<<"\n4:FOR DISPLAY  : " ; 
	cin>>a ;
	if (a==4)
	obj2.Display();
	}
	else if (a==2){
	cout<<"ENTER THE PUBLICATION : " ;
	cin>>pub ;
	scientist obj1(title,pub,name,num) ;
	cout<<"\n4:FOR DISPLAY  : " ; 
	cin>>a ;
	if (a==4)
	obj1.Display();
	}
	else if (a==3){
	laborer obj(title,name,num) ;
	cout<<"\n4:FOR DISPLAY  : " ; 
	cin>>a ;
	if (a==4)
	obj.Display();
	}
	}while (a!=5);
}

