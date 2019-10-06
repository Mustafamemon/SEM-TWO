#include"myfile_HEADER.h"
article::article(const article &a){
	jour = new char[4] ;
	auth = new  char [20];
	ID = a.ID ;
	tit = a.tit ;
	jour = a.jour ;
	issu = a.issu ;
	year = a.year ;
	sp = a.sp ;
	ep 	= a.ep ;
	auth = a.auth ;
}
article::article(int id):ID(id){}
	
	void article::input(){
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
	
	int article::check(int f){
		if(!strcmp(auth,"Robert Tarjan"))
		{
			strcpy(auth,"Robert Lafore") ;
			f=1 ;
		}
		return f  ;
	}
	
	int article::AVG(int f){
		if(!strcmp(jour,"JCAM")){
			if(issu==55){
				tem = tem + year ;
				++cnt ;
				f=1 ;
			}
		}
		return f ;
	}
	
	void article::Display(){
		cout<<endl;
		cout<<ID<<"\t"<<tit<<"\t"<<jour<<"\t"<<issu<<"\t"<<year<<"\t"<<sp<<"\t"<<ep<<"\t"<<auth<<endl ;
	}
	
	int article::Check_Starting(int f){
		if (tit[0]=='C'){
			strcpy(jour,"SICO");
			f = 1 ;
		}
		return f ;
	}
	
	void article::Group(article *a){
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
