/*/*#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class Participant
{
	private:
		long long int id,score;
		char name[100];
	public:
		Participant()
		{
			
		}
		void set(long long int i,int s,char c[])
		{
			id = i;
			score = s;
			strcpy(name,c);
			input();
		}
		void input()
		{
			ofstream outfile;
			outfile.open("participant.dat",ios::app|ios::out);
			outfile.write((char*)this,sizeof(*this));
			outfile.close();
		}
		void show()
		{
			cout<<"\n"<<name<<"\t"<<id<<"\t"<<score<<"\n";		
		}
		void Output(int userid)
		{
			ifstream infile;
			infile.open("paticipant.dat");
			infile.read((char*)this,sizeof(*this));
			while(!infile.eof())
			{
				show();
				infile.read((char*)this,sizeof(*this));
			}
			infile.close();
		}	
};
int main ()
{
	int user;
	char c[]={"Muhammad Junaid Shaikh"};
	Participant p1;
	p1.set(173895,120,c);//,p;
	cout<<"Enter id which data you want to see: "<<endl;
	cin>>user;
	p1.Output(user);
}*/
/*#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
using namespace std;
class participant{
private:
	char name[20];
	int id;
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
	void output(int aid)
	{
		ifstream fin;
		fin.open("Participant.dat",ios::in);
		fin.read((char*)this,sizeof(*this)); 
		while(!fin.eof())
		{
			if(aid==id)
			cout<<name<<"\t"<<id<<"\t"<<score<<endl;
			fin.read((char*)this,sizeof(*this));
		}
		fin.close();
	}
};
int main()
{
	participant p;
	p.input();
	p.output(173795);
}*/
#include<iostream>
#include<fstream>
using namespace std;
class participant
{
	private:
		int id,	score;
		char name[30];
	public:
		participant()
		{
		}
		void input()
		{
			cout<<"Enter ID: ";
			cin>>id;
			fflush(stdin);
			cout<<"Enter name: ";
			cin.getline(name, 29);
			cout<<"Enter score: ";
			cin>>score;
			ofstream fout;
			fout.open("participant.dat", ios::binary);
			fout.write((char*)this, sizeof(*this));
			fout.close();
		}
		int output()
		{
			int id1;
			cout<<"Enter an ID: ";
			cin>>id1;
			ifstream fin;
			fin.open("participant.dat", ios::in);
			fin.read((char*)this, sizeof(*this));
			while(!fin.eof())
			{
				if(id1==id)
				{
					cout<<"ID: "<<id<<endl;
					cout<<"Name: "<<name<<endl;
					cout<<"Score: "<<score<<endl;
					fin.close();
					return 0;
				}
				fin.read((char*)this, sizeof(*this));
			}
			fin.close();
			cout<<"No such participant found!"<<endl;
		}
		Max()
		{
			int temp;
			ifstream fin;
			fin.open("participant.dat", ios::binary);
			fin.read((char*)this, sizeof(*this));
			while(!fin.eof())
			{
				if(temp<score)
					temp=score;
				fin.read((char*)this, sizeof(*this));
			}
			fin.close();
			cout<<"The highest score is "<<temp<<endl;
		}
};
main()
{
	participant p;
	int a;
	while(1)
	{
		cout<<"1- Add participant\n2- Search participant\n3- Max\n4- Exit ";
		cin>>a;
		if (a==1)
		{
			p.input();
		}
		else if (a==2)
		{
			p.output();
		}
		else if (a==3)
		{
			p.Max();
		}
		else if (a==4)
		{
			exit(0);
		}
	}
}
