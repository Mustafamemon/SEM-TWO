#include"myfile_Func.h"
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
		cout<<"HHH";
		//article obj1[6] = obj[6] ;//{article(obj[0]),article(obj[1]),article(obj[2]),article(obj[3]),article(obj[4]),article(obj[5])};
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
			cout<<"\nAVG  :"<<tem/cnt ;
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
		obj1[0].Group(obj1);
	break ;
}
}while (x!='G');
}


