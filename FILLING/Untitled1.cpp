#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;
class Product
{
	private:
		string barcode;
		string name;
	public:
		Product()
		{
			barcode = '\0';
			name = '\0';	
		}
		void setcode(string barc,string aname)
		{
			ofstream f ;
			f.open("MYFILE.txt",ios::out | ios::app);	
			barcode = barc;
			name = aname ;
			if (f.is_open()){
			f<<name<<"\t\t"<<barcode<<"\n";
			f.close();
			}
		}
		void printer()
		{
			ifstream f;
			f.open("MYFILE.txt",ios::in) ;
			f>>name>>barcode;
			while (!f.eof())
    		{
			    show();
			    f>>name>>barcode;
       		}
			f.close();
		}	
		void show(){
			cout<<"NAME : "<<name<<endl<<"BAROCDE : "<<barcode<<endl;
		}
		void del(){
			string line ;
			fstream f,f1 ;
			int i = 0 ; 
			cout<<"ENTER THE BARCODE FOR DELETING THE RECORD : " ;
			cin>>line ;
			f.open("MYFILE.txt",ios::in);
			f1.open("temp.txt",ios::in|ios::out |ios::app);
			f>>name>>barcode ;
			while(!f.eof()){
				if (barcode!=line){
					f1<<name<<"\t\t"<<barcode<<"\n";
				}
				else
				i=1;
				f>>name>>barcode ;
			}
			f.close();
			f1.close();
			remove("MYFILE.txt");
			rename("temp.txt","MYFILE.txt");
			if (i==1){
			cout<<"\nDeleting....\n";
			Sleep(1500);
			system("cls");
			cout<<"\t\t\tDeleted\n" ;
			}
			else
			cout<<"\nNOT FOUND\n" ;	
		}
		void Update(){
			string line ;
			fstream f,f1 ;
			int i=0 ;
			f.open("MYFILE.txt",ios::in);
			f1.open("temp.txt",ios::in|ios::out |ios::app);
			cout<<"ENTER THE BARCODE TO UPDATE THE RECORD : " ;
			cin>>line ;
			f>>name>>barcode ;
			while(!f.eof()){
				if (barcode!=line){
					f1<<name<<"\t\t"<<barcode<<"\n";
				}
				else
				{
					i=1; 
					cout<<"ENTER THE NAME : " ;
					cin>>name ;
					f1<<name<<"\t\t"<<barcode<<"\n";
				}
				f>>name>>barcode ;
			}
			f.close();
			f1.close();
			remove("MYFILE.txt");
			rename("temp.txt","MYFILE.txt");
			if(i==1){
			cout<<"\nUpdating....\n";
			Sleep(1500);
			system("cls");
			cout<<"\t\t\tUpdated\n" ;
			}
			else
			cout<<"\nNOT FOUND\n" ;
		}
	};
int main ()
{
	int a; 
	Product p ;
	string name,bar ;
	do{
		cout<<"1:ADD\n2:DEL\n3:UPDATE\n4:DISPLAY\n5:EXIT\n" ;
		cin>>a ;
		if (a==1){
			cout<<"ENTER THE NAME : ";
			cin>>name ;
			cout<<"ENTER THE BARCODE : ";
			cin>>bar ;
			p.setcode(bar,name);
		}
		else if(a==4)
			p.printer();
		else if(a==2)
			p.del();
		else if(a==3)
			p.Update();
	}while(a!=5);
	return 0 ;
}
