#include<cstdlib>
#include<fstream>
#include<iostream>
#include<time.h>
#include<conio.h>
using namespace std;
class BankAcc{
private:
	char name[20];
	char acctype[20];
	int acno;
	float balance;
	char pass[20];
public:
	void AddData()
	{
		cout<<"NAME :";
		cin>>name;
		cout<<"ACC Type: ";
		cin>>acctype;
		srand(time(NULL));
		acno=10000000+rand()%100000;
		cout<<"\nYour accno is: "<<acno;
		cout<<"\nNEW PASSWORD: ";
		cin>>pass;
		balance=0.0;
		store_dat();
	}
	void store_dat()
	{
		ofstream fout ;
		fout.open("Data.txt",ios::out | ios::app);
		fout.write((char*)this,sizeof(BankAcc));
		fout.close();
	}
	void Read_data()
	{
		ifstream fin;
		fin.open("Data.txt",ios::in);
		if (fin.is_open())
		{
			while(fin.read((char*)this,sizeof(BankAcc)))
			{
				show();	
			}
		}
		else
		cout<<"NOT";
		fin.close();
	}
	void show()
	{
		cout<<endl<<endl<<name<<endl<<pass<<endl<<acno<<endl<<acctype<<endl<<balance<<endl;
	}
};
int main()
{
	BankAcc obj ;
	obj.AddData();
	obj.Read_data();
}
