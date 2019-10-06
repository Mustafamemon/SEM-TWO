#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include<windows.h>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<string.h>

using namespace std;

class person
{
	private:
		char name[100];
	public:
		virtual void getData(char[],double)=0;
		virtual bool isOutstanding()=0;
		void setname(char a[])
		{
			strcpy(name,a);	
		}
		void getname()
		{
			cout<<name;
		}
		
};

class student: public person
{
	private:
		char name[100];
		double gpa;
	public:	
		void getData(char a[], double g)
		{
			setname(a);
            gpa=g;
		}
		bool isOutstanding()
		{
			if(gpa>=3.5)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
};

class professor:public person
{
	private:
		char name[100];
		double pub;
		
		double gpa;
	public:
		void getData(char a[],double p)
		{
			setname(a);
            pub=p;
		}
		bool isOutstanding()
		{
			if(pub>=100)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		
};

int main()
{
	person * p=new student;
    int i=0;
    char name[100];
	double gpa;
	int pub;
    while(i!=3)
    {       
		
		cout<<"\n\n\t\t\t1.Enter Student\n";
		cout<<"\n\t\t\t2.Enter Professor\n";
		cout<<"\n\t\t\t3.Exit\n";
		cout<<"\n\n\t\t\tEnter Your Choice: ";
		cin>>i;
		if(i==1)
		{ 	
			student * s;
	    	s=static_cast<student*>(p);
	    	cout<<"\n\n\t\t\tEnter Name: ";
			fflush(stdin);
			gets(name);
	    	cout<<"\n\n\t\t\tEnter GPA: ";
			cin>>gpa;
	    	s->getData(name,gpa);
	    	int a=s->isOutstanding();
	    	cout<<a;
	    
	    }
	    else if(i==2)
	    {	
			professor * pr;
	        pr=static_cast<professor*>(p);
	        cout<<"\n\n\t\t\tEnter Name: ";
			fflush(stdin);
			gets(name);
	    	cout<<"\n\n\t\t\tEnter Publi: ";
			cin>>pub;
	    	pr->getData(name,pub);
			int a=pr->isOutstanding();
	    	cout<<a;
	    } 
		else if(i==3)
		{
			return 0;
		} 
		   
    }	
    
    
}

