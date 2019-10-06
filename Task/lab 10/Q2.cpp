#include<iostream>
using namespace std ;
class Employee{
private:
	string F_name;
	string L_name;
	int ssn;
public:
	Employee(string fname="\0",string lname="\0",int assn=0):F_name(fname),L_name(lname),ssn(assn)
	{}
	void setdata(string fname,string lname,int assn)
	{
		F_name=fname;
		L_name=lname;
		ssn=assn;
	}
	string get_fname()
	{
		return F_name; 
	}
	string get_lname()
	{
		return L_name; 
	}
	int get_ssn()
	{
		return ssn;
	}
	virtual void print()
	{
		cout<<"\nFirst name: "<<F_name;
		cout<<"\nLast name: "<<L_name;
		cout<<"\nSocial security number: "<<ssn;
	}
	virtual double earning()=0;
};
class Salaried:public Employee{
private:
	double salary;
public:
	Salaried(double asal):salary(asal)  
	{}
	double earning()
	{
		return salary;
	}
	void print()
	{
		Employee::print();
		cout<<"\nSalary: "<<salary;
	}
};
class hour:public Employee{
private:
	double wage;
	int hr ;
public:
	hour(double awage , int ahr):wage(awage),hr(ahr)
	{}
	double earning()
	{
		return (wage*hr);
	}
	void print()
	{
		Employee::print();
		cout<<"\nSalary: "<<earning();
	}
};
class comission:public Employee{
private:
	double com_rate;
	double gross_sale;
public:
	comission(double acom_rate, double agross_sale):com_rate(acom_rate),gross_sale(agross_sale)
	{}
	double earning()
	{
		return(double) gross_sale*(com_rate/100);
	}
	void print()
	{
		Employee::print();
		cout<<"\nSalary: "<<earning();
	}
};
class base_comission:public Employee{
private:
	double salary;
public:
	base_comission(float asalary):salary(asalary){}
	double earning()
	{
		return salary+(40000*0.1);
	}
	void print()
	{
		Employee::print();
		cout<<"\nSalary: "<<earning();
	}
};
int main()
{
	Employee *ptr;
	cout<<"\t\tUP CASTING\n\n\n";
	ptr = new Salaried(10000.0);
	ptr->setdata("Mustafa","Rafiq",1234);
	ptr->print();
	cout<<"\n\n\n";
	ptr = new hour(100.0,12);
	ptr->setdata("Mustafa","Rafiq",1234);
	ptr->print();
	cout<<"\n\n\n";
	ptr = new comission(12,20022.2);
	ptr->setdata("Mustafa","Rafiq",1234);
	ptr->print();
	cout<<"\n\n\n";
	ptr = new base_comission(1234.09);
	ptr->setdata("Mustafa","Rafiq",1234);
	ptr->print();
	cout<<"\n\n\t\tDOWN CASTING\n\n\n";
	Salaried obj(1000.0) ;
	ptr=&obj;
	Salaried *sal=static_cast<Salaried*>(ptr);
	sal->setdata("Mustafa","Manga",2345); 
	sal->print();
	cout<<"\n\n\n";
	hour obj1(100.0,12) ;
	ptr=&obj1;
	hour *Hr=static_cast<hour*>(ptr);
	Hr->setdata("Mustafa","Manga",2345);
	Hr->print();
	cout<<"\n\n\n";
	comission obj2(12,20222) ;
	ptr=&obj2;
	comission *com=static_cast<comission*>(ptr); 
	com->setdata("Mustafa","Manga",2345);
	com->print();
	cout<<"\n\n\n";
	base_comission obj3(1234.09) ;
	ptr=&obj3;
	base_comission*bas=static_cast<base_comission*>(ptr);
	bas->setdata("Mustafa","Manga",2345);
	bas->print();
	cout<<"\n\n\n";
}
