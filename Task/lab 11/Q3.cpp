#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class person{
private:
	char name[100] ;
	int age;
public:
	person()
	{
	}
	person(char aname[], int aage)
	{
		strcpy(name,aname);
		age=aage;
		write();
	}
	void show()
	{
		cout<<"\nNAME :"<<name; 
		cout<<"\nAGE: "<<age;
	}
	void read()
	{
		ifstream fin ;
		fin.open("Myfile1.txt",ios::in);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			show();
			fin.read((char*)this,sizeof(*this));
		}
		fin.close();
	}
	void write()
	{
		ofstream fout ;
		fout.open("Myfile1.txt",ios::out|ios::app);
		fout.write((char*)this,sizeof(*this));
		fout.close();
	}
};
int main()
{
	char name[100];
	int age,i;
	do{
		cout<<"\n1:Write\n2:Read\n3:exit\n";
		cin>>i;
		if(i==1)
		{
			fflush(stdin);
			cout<<"\nEnter name : ";
			cin.getline(name,100);
			cout<<"\nEnter age :";
			cin>>age;
			person person1(name,age);
		}
		else if(i==2)
		{
			person p;
			p.read();
		}
		
	}while(i!=3);
}
