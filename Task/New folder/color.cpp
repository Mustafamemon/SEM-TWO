#include<cstdlib>
#include<fstream>
#include<iostream>
#include<time.h>
#include<conio.h>
using namespace std;
class BankAcc{
private:
	string name;
	string acctype;
	int acno;
	float balance;
	string pass ;
public:
	void AddData()
	{
		cout<<"NAME :";
		cin>>name;
		cout<<"ACC Type: ";
		cin>>acctype;
		acno=10000000+rand()%100000;
		cout<<"\nYour accno is: "<<acno;
		cout<<"NEW PASSWORD: ";
		cin>>pass;
		balance=0.0;
	}
	void store_date()
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
		while(!fin.eof())
		{
			fin.read((char*)this,sizeof(*this));
			show();
		}
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
	obj.Read_data();
}
