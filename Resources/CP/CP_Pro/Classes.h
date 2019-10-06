#include<iostream>
#include<fstream>
using namespace std;
class date
{
	private:
	int day, month,year;
	public:
		date()
		{
			day=0;
			month=0;
			year=0;
		}
		friend ostream& operator<<(ostream &, date&);
		friend istream& operator>>(istream &, date&);
};
class Time
{
	private:
	int hour, mint;
	public:
		Time()
		{
			hour=0;
			mint=0;
		}
		friend istream& operator>>(istream&,Time&);
		friend ostream& operator<<(ostream&,const Time&);
};
class CNIC
{	
	private:
		int strt;
		long long int mid;
		int  end;
	public:
		CNIC()
		{
			strt=0;
			mid=0;
			end=0;
		}
		bool operator==(CNIC);
		friend istream& operator>>(istream&,CNIC&);
		friend ostream& operator<<(ostream&,const CNIC&);
};
class Authorizedperson
{
	private:
		string login_id;
		char *password;
	public:
		friend istream& operator>>(istream & , Authorizedperson &);
		friend ostream& operator<<(ostream &, const Authorizedperson &);
		bool CheckAuthorized(string,char[]);
		void changepass();
		string get_id()
		{
			return login_id;
		}
		char* get_pass()
		{
			return password;
		}
};
class Employee
{
	protected:
		string name;
		int id;
		CNIC c;
	public:
		Employee()
		{
			id=0;
			name="NULL";
		}
		virtual void StaffDetails()=0;
		virtual void display()=0;
		virtual bool CheckStaff(CNIC)=0;
		virtual void EditDetails()=0;
		virtual void DelDetails()=0;
};
class GroundStaff:public Employee
{
	private:
		double salary;	
		int Duty_Hours;
		string Designation;
	public:
		GroundStaff()
		{
			salary=0;
			Duty_Hours=0;
			Designation="NULL";
		}
		friend istream& operator>>(istream&,GroundStaff&);
		friend ostream& operator<<(ostream&,const GroundStaff&);
		void display();
		bool CheckStaff(CNIC);
		void StaffDetails();
		void EditDetails();
		void DelDetails();
};
class FlightCrew:public Employee
{
	private:
		double salary;	
		int Duty_Hours;
		string Designation;
	public:
		FlightCrew()
		{
			salary=0;
			Duty_Hours=0;
			Designation="NULL";
		}
		friend istream& operator>>(istream &input,FlightCrew &);
		friend ostream& operator<<(ostream&,FlightCrew&);
		void display();
		void StaffDetails();
		bool CheckStaff(CNIC);
		void EditDetails();
		void DelDetails();
};
class Flight
{
	private:
		string to, from;
		Time  arrival, departure;
		string flight_no;
		date da;
	public:
		Flight()
		{
			to="NULL";
			from="NULL";
			flight_no="NULL";
		}
		void show();
		void Add_flight();
		void View_schedule();
		void Delete_flight();
		void Update_flight();
		void Update_Shedule();
		int noof_flights();
		bool Check_Flight(string,string,string,int);
		
};
class User
{
	private:
		string name;
		string F_name;
		string nationality;
		CNIC c ;
		string passport;
		Flight fly;
	public:
		User()
		{
			name="NULL";
			F_name="NULL";
			nationality="NULL";
			passport="NULL";
		}
		friend istream& operator>>(istream&,User&);
		void Book_ticket();
		void Flight_Details();
		bool CheckUser(CNIC);
		bool AddUser(char);
};

