#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
using namespace std;
class participant{
private:
	char name[20];
	char id[10];
	int score;
public:
	void input()
	{
		fflush(stdin);
		cout<<"Enter name: ";
		cin.getline(name,20);
		cout<<"Enter id: ";
		cin>>id;
		cout<<"Enter score: ";
		cin>>score;
		ofstream fout ;
		fout.open("Participant.dat",ios::binary | ios::app |  ios::out);
		fout.write((char*)this,sizeof(*this));
		fout.close();
	}
	void output()
	{	
		ifstream fin;
		fin.open("Participant.dat",ios::in);
		if(fin.is_open())
		{
			cout<<setw(15)<<"Name"<<setw(20)<<"ID"<<setw(20)<<"Score\n";
			cout<<"******************************************************\n";
			fin.read((char*)this,sizeof(*this)); 
			while(!fin.eof())
			{
				show();
				fin.read((char*)this,sizeof(*this));
			}
		}
		else
		cout<<"File not found!";
		fin.close();
	}
	void show()
	{
		cout<<setw(15)<<name<<setw(20)<<id<<setw(20)<<score<<endl;
	}
	void max()
	{
		ifstream fin;
		int temp=0;
		fin.open("Participant.dat",ios::in);
		if(fin.is_open())
		{
			while(!fin.eof())
			{
				fin.read((char*)this,sizeof(*this));
				if(temp<score)
				temp=score ;
			}
		}
		else
		cout<<"File not found!";
		fin.close();
		fin.open("Participant.dat",ios::in);
		cout<<setw(15)<<"Name"<<setw(20)<<"ID"<<setw(20)<<"Score\n";
		cout<<"******************************************************\n";
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(temp==score)
			{
				show();
			}
			fin.read((char*)this,sizeof(*this));
		}
		fin.close();
	}
};
int main()
{
	participant p,p1;
	int ans;
	do
	{
		cout<<"1:For Input\n2:For Output\n3:For Max score\n4:Exit\n";
		cin>>ans;
		if(ans==1)
		p.input();
		else if(ans==2)
		p1.output();
		else if(ans==3)
		p.max();
		cout<<endl;
	}while(ans!=4);
}
