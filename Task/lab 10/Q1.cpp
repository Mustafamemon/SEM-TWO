#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std ;
class Person{
private:
	string name;
public:
	virtual void getdata()=0;
	virtual bool isOutstanding()=0;
	void getname()
	{
		cout<<"Enter the name: ";
		cin>>name;
	}
	void putname()
	{
		cout<<"Name: "<<name;
	}
};
class Student:public Person{
private:
	float gpa;
public:
	void getdata()
	{
		cout<<"\nEnter the Gpa : ";
		cin>>gpa;
	}
	bool isOutstanding()
	{
		if(gpa>3.5)
		return true;
		else
		return false ;
	}
};
class Professor:public Person{
private:
	int publication; 
public:
	void getdata()
	{
		cout<<"Enter the no of Publication: ";
		cin>>publication;
	}
	bool isOutstanding()
	{
		if(publication>100)
		return true;
		else
		return false ;
	}
};
int main()
{
	Person *ptr;
	int i=0; 
	do{
		cout<<"\n1:To add data in student\n2:To add data in professor\n3:exit\n";
		cin>>i;
		if(i==1)
		{
			ptr=new Student;
			ptr->getname();
			ptr->getdata();
			ptr->putname();
			if(ptr->isOutstanding())
			cout<<"\nGPA is greater than 3.5";
			else
			cout<<"\nGPA is less than 3.5";
		}
		else if(i==2)
		{
			ptr=new Professor;
			ptr->getname();
			ptr->getdata();
			ptr->putname();
			if(ptr->isOutstanding())
			cout<<"\nNo of Publication is greater than 100";
			else
			cout<<"\nNo of Publication is less than 100";
		}
	}while(i!=3);
}
