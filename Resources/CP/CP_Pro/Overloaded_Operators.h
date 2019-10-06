#include<iostream>
#include<iomanip>
//#include"Classes.h"
using namespace std ;

istream& operator>>(istream &input , CNIC &c)
{
	againcnic:
	input>>c.strt;
	input.ignore();
	input>>c.mid;
	input.ignore();
	input>>c.end;
	if(c.strt>99999 || c.mid>9999999 || c.end>9)
	{
		try
		{
			throw c.strt;
		}
		catch (int x)
		{
			cout<<"\nInvlaid CNIC\n";
			cout<<"\nEnter CNIC Number: \n" ;
			cout<<"     -       - \r";
			goto againcnic;
		}
	}
	return input;
}

bool CNIC::operator==(CNIC c)
{
	if(strt==c.strt)
	{
		if(mid==c.mid)
		{
			if(end==c.end)
			return true;
		}
	}
	return false;
}

ostream& operator<<(ostream &output ,const CNIC &c)
{
	output<<setfill('0')<<setw(5)<<c.strt<<"-"<<setw(7)<<c.mid<<"-"<<c.end;
	return output ;
}

istream& operator>>(istream &input , User &u)
{
	ofstream fout;
	cout<<"\nEnter CNIC Number: \n" ;
	cout<<"     -       - \r";
	input>>u.c;
	if(!u.CheckUser(u.c))
	{
		fflush(stdin);
		cout<<"\nEnter first name : \n" ;
		getline(input,u.name);
		cout<<"\nEnter father name : \n" ;
		getline(input,u.F_name);
		cout<<"\nEnter nationality : \n" ;
		getline(input,u.nationality); 
		cout<<"\nEnter passport number : \n" ;
		getline(input,u.passport);
		fout.open("User_Data.txt",ios::out | ios::app);
		fout<<u.name<<"\t"<<u.F_name<<"\t\t"<<u.c<<"\t"<<u.nationality<<"\t"<<u.passport<<"\n";
	}
	else
	cout<<"\nAlready Registered\n";
	fout.close();
	return input;
}

istream& operator>>(istream &input , Authorizedperson &a)
{
	a.password = new char[30];
	int i=0;
	getline(input,a.login_id);
	cout<<"\n\n\t\t\tEnter password : " ;
	while(1)
	{
		a.password[i] = getch();
		if(a.password[i]=='\r')
		{
			a.password[i] = '\0';
			break;
		}
		else if(a.password[i]=='\b')
		{
			if(i>0)
			{
				i--;
				cout<<"\b \b";
			}	
		}
		else
		{
			cout<<"*";
				i++;
		}
	}
	return input;
}

istream& operator>>(istream &input,Time &t)
{
	againtime:
	input>>t.hour;
	input.ignore();
	input>>t.mint;
	if(t.hour<0 || t.hour>24)
	{
		try
		{
			throw t.hour;
		}
		catch(int x)
		{
			cout<<"\nInvalid Hour\n";
			cout<<"\nRe-Enter: ";
			goto againtime;
		}	
	}
	if(t.mint<0 || t.mint>59)
	{
		try
		{
			throw t.mint;
		}
		catch(int x)
		{
			cout<<"\nInvalid Minute\n";
			cout<<"Re-Enter";
			goto againtime;
		}	
	}
	return input;
}

ostream& operator<<(ostream &output,const Time &t)
{
	output<<setfill('0')<<setw(2)<<t.hour<<":"<<setw(2)<<t.mint;
	return output;
}

ostream& operator<<(ostream &output, date &d)
{
	output<<d.year<<"/"<<setfill('0')<<setw(2)<<d.month<<"/"<<setw(2)<<d.day;
	return output;
}

istream& operator>>(istream &input, date &d)
{
	againdate:
	input>>d.year;
	input.ignore();
	input>>d.month;
	input.ignore();
	input>>d.day;
	if(d.month<1 || d.month>12) 
	{
		try
		{
			throw d.month;
		}
		catch(int x)
		{
			cout<<"\nInvalid Month\n";
			cout<<"\nRe-Enter: ";
			goto againdate;
		}	
	}
	if (d.day<1 || d.day>31)
	{
		try
		{
			throw d.day;
		}
		catch(int x)
		{
			cout<<"\nInvalid Day\n";
			cout<<"\nRe-Enter: ";
			goto againdate;
		}	
	}
	return input;
}
istream& operator>>(istream &input,GroundStaff &g)
{
	g.StaffDetails();
	return input;
}
ostream& operator<<(ostream &output,GroundStaff &g)
{
	g.display();
	return output;
}
istream& operator>>(istream &input,FlightCrew &fc)
{
	fc.StaffDetails();
	return input;
}
ostream& operator<<(ostream &output,FlightCrew &fc)
{
	fc.display();
	return output;
}
/*istream& operator>>(istream & , Domestic &)
{
		double ticket_pric;
		int noofseats;
		float luggage;
		string meal_served;
		CNIC c ;
	}*/
