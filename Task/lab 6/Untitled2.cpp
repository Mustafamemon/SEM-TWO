#include<iostream>
#include<time.h>
#include<cstdlib>
#include<cstring>
using namespace std ;
int temp=0,cnt=0 ;
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
	article(int id){
		ID = id ;
	}
	void input(){
		jour = new char[4];
		auth = new char[20];
		fflush(stdin);
		cout<<"ENTER THE TITLE : " ;
		getline(cin,tit);
		fflush(stdin);
		cout<<"ENTER JOURNAL : " ;
		cin>>jour ;
		cout<<"ENTER THE ISSUE : ";
		cin>>issu ;
		cout<<"ENTER THE YEAR : " ;
		cin>>year ;
		cout<<"ENTER THE STARTING PAGE : " ;
		cin>>sp ;
		cout<<"ENTER THE ENDING PAGE : " ;
		cin>>ep ;
		while(sp>ep)
		{
			cout<<"ERROR" ;
			cout<<"\nAGAIN ENTER THE ENDING PAGE : " ;
			cin>>ep ;
		}
		fflush(stdin);
		cout<<"ENTER THE AUTHOR : " ;
		cin.getline(auth,20);
	} 
	int check(int f){
		if(!strcmp(auth,"Robert Tarjan"))
		{
			strcpy(auth,"Robert Lafore") ;
			f=1 ;
		}
		return f  ;
	}
	int AVG(int f){
		if(!strcmp(jour,"JCAM")){
			if(issu==55){
				temp = temp + year ;
				++cnt ;
				f=1 ;
			}
		}
		return f ;
	}
	void Display(){
		cout<<endl;
		cout<<ID<<"\t"<<tit<<"\t"<<jour<<"\t"<<issu<<"\t"<<year<<"\t"<<sp<<"\t"<<ep<<"\t"<<auth<<endl ;
	}
	int Check_Starting(int f){
		if (tit[0]=='C'){
			strcpy(jour,"SICO");
			f = 1 ;
		}
		return f ;
	}
	char *j(){
		return jour ;
	}
	void Group(article *a){
	cout<<"ID\tTITLE\tJOURNAL\tISSUE\tYEAR\tS-PAGE\tE-PAGE\tAUTHOR"<<endl ;
	int i , j , temp1;
	char temp[20] ;
	string temp2 ;
	for(i=0;i<6;i++){
		for(j=0;j<5;j++){
			if (strcmp(a[j].jour,a[j+1].jour)>0){
				strcpy(temp,a[j].jour);strcpy(a[j].jour,a[j+1].jour);strcpy(a[j+1].jour,temp);
				strcpy(temp,a[j].auth);strcpy(a[j].auth,a[j+1].auth);strcpy(a[j+1].auth,temp);
				temp2=a[j].tit; a[j].tit=a[j+1].tit;  a[j+1].tit=temp2;
				temp1=a[j].sp;  a[j].sp=a[j+1].sp;	  a[j+1].sp=temp1;
				temp1=a[j].ep;  a[j].ep=a[j+1].ep;	  a[j+1].ep=temp1;
				temp1=a[j].ID;  a[j].ID=a[j+1].ID;	  a[j+1].ID=temp1;
				temp1=a[j].issu;a[j].issu=a[j+1].issu;a[j+1].issu=temp1;
				temp1=a[j].year;a[j].year=a[j+1].year;a[j+1].year=temp1;
			}
		}
	}
	for (i=0;i<6;i++){
		a[i].Display();
	}
}
};
int main(){
	srand(time(NULL));
	int id = rand()%100 ;
	int i , f=0 ;
	char x ;
	article obj[6]={article(id),article(id+1),article(id+2),article(id+3),article(id+4),article(id+5)};
	//input
	do {
	cout<<"\nA : INPUT\nB : CHECK_AUTHOR\nC : AVG_YEAR\nD : CHECK_STARTING\nE : DISPLAY\nF : SORT BY JOURNAL\nG : EXIT\n" ;
	cin>>x ;
	switch(x){
	case 'A' :
		for(i=0;i<6;i++)
			obj[i].input();
	break ;
	//check
	case 'B' :
		f=0 ;
		for(i=0;i<6;i++)
			f=obj[i].check(f);
		if(f==0)
			cout<<"RESULT NOT FOUND " ;
		break ;
	//AVG
	case 'C' :
		f=0 ;
		for(i=0;i<6;i++)
			f=obj[i].AVG(f);
		if(f==0)
			cout<<"\nRESULT NOT FOUND " ;
		else if(f==1)
			cout<<"\nAVG  :"<<temp/cnt ;
	break ;
	//Check_Starting
	case 'D' :
		f=0 ;
		for(i=0;i<6;i++)
			f=obj[i].Check_Starting(f);
		if(f==0)
			cout<<"\nRESULT NOT FOUND " ;
		break ;
	//DISPLAY
	case 'E' :
		cout<<"ID\tTITLE\tJOURNAL\tISSUE\tYEAR\tS-PAGE\tE-PAGE\tAUTHOR"<<endl ;
		for(i=0;i<6;i++)
			obj[i].Display();
	break ;
	case 'F':
		obj[0].Group(obj);
	break ;
}
}while (x!='G');
}


