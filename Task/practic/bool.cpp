#include<iostream>
#include<string.h>
#include<ctype.h>


using namespace std;

class student
{
	char name[100];
	char clss[100];
	char section[100];
	public:
		student()
		{
			for(int i=0; i<100; i++)
			{
				name[i]='\0';
				clss[i]='\0';
				section[i]='\0';
				
			}
		}
		setdata()
		{
			cout<<"\tEnter Name: ";
			gets(name);
			cout<<"\tEnter Class: ";
			gets(clss);
			cout<<"\tEnter Section: ";
			gets(section);
					
		}
		getdata()
		{
			cout<<"\n\tName: ";
			puts(name);
			cout<<"\tClass: ";
			puts(clss);
			cout<<"\tSection: ";
			puts(section);
			
		}
		bool operator > (student &b)
		{
			student a=*this;
			int i=strcmp(a.name , b.name);
			if(i==0)
			{
				return false;
			}
			else if (i>0)
				return true;
			else if (i<0)
				return false;
		}
		void operator =(student &b)
		{
			cout<<"ss";
			student a=*this;
			cout<<a.name<<"\t\t";
			strcpy(a.name, b.name);
			cout<<a.name<<endl;
			strcpy(a.clss, b.clss);
			strcpy(a.section, b.section);
			//return *this;	
		}
};

int main()
{
	student *s= new student[5];
	int i,j;
	for(i=0; i<5;i++)
	{
		s[i].setdata();
	}
	student temp;
	for(i=0; i<5;i++)
	{
		for(j=0; j<4;j++)
		{
			if((s[j] > s[j+1]))
			{
				//cout<<"a->"<<j<<"\n";
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
				
			}
		}
	
	}
	cout<<endl<<endl;
	for(i=0; i<5;i++)
	{
		s[i].getdata();
		cout<<endl;
	}
	
	return 0;
}
