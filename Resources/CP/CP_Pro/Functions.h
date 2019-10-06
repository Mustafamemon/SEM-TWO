#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;
string currentTime() 
{
    time_t now = time(0);
    struct tm  tstruct;
    char buf[6];
    tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%H:%M", &tstruct);
    return buf;
}
string currentDate() 
{
    time_t now = time(0);
    struct tm  tstruct;
    char buf[20];
    tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y/%m/%d", &tstruct);
	return buf;
}
void Flight::show()
{
	cout<<"\nFlight Number";
	cout<<"\tTo";
	cout<<"\t\tFrom";
	cout<<"\t\tDeparture Time";
	cout<<"\tArrival Time";
	cout<<"\n";
	for(int i=0; i<78; i++)
		cout<<"*";
	cout<<"\n";
}

void Flight::Add_flight()
{
	int flag;
	char ch;
	ofstream fout;
	do
	{
		fflush(stdin);
		cout<<"\nFlight Number: ";
		getline(cin, flight_no);
		fflush(stdin);
		cout<<"To: ";		
		getline(cin, to);
		cout<<"From: ";		
		getline(cin, from);
		fflush(stdin);
		cout<<"Departure Time(HH:MM): ";
		cin>>departure;
		cout<<"Arrival Time(HH:MM): ";
		cin>>arrival;
		cout<<"Date(YYYY/MM/DD): ";
		cin>>da;
		fout.open("Shedule.txt", ios::out | ios::app);
		if(fout.is_open())
			fout<<flight_no<<"\t\t"<<to<<"\t"<<from<<"\t"<<"\t"<<departure<<"\t"<<arrival<<"\t\t"<<da<<endl;
		fout.close();
		cout<<"Do you want to add more? (y/n): ";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');
	
}

int Flight::noof_flights()
{
	int cnt=0;
	ifstream fin;
	fin.open("Shedule.txt", ios::in);
	if (fin.is_open())
	{
		fin>>flight_no>>to>>from>>departure>>arrival>>da;
		while(!fin.eof())
		{
			++cnt;
			fin>>flight_no>>to>>from>>departure>>arrival>>da;
		}
		fin.close();
		return cnt;
	}	
	return 0;	
}

void Flight::View_schedule()
{
	int cnt1=0,cnt = noof_flights(),flag=0;
	char date1[30][11],date[11];
	ifstream fin;
	show();
	while(cnt!=0)
	{
		fin.open("Shedule.txt", ios::in);
		date:
		fin>>flight_no>>to>>from>>departure>>arrival>>date;
		for(int i=0;i<cnt1;i++)
		{
			if(strcmp(date1[i],date)!=0)
			{
				flag=1;
			}
			else
			{
				flag=0;
				goto date;	
			}
		}
		if (flag==1||cnt1==0)
		{
			strcpy(date1[cnt1],date);
		}
		flag=0;
		while(!fin.eof())
		{
			if(strcmp(date1[cnt1],date)==0)
			{
				--cnt;
			}
			fin>>flight_no>>to>>from>>departure>>arrival>>date;
		}
		fin.close();	
		++cnt1;
	}
	char temp[11];
	for(int i=0;i<cnt1;i++)
	{
		for(int j=i+1;j<cnt1;j++)
		{
			if(strcmp(date1[i],date1[j])>0)
			{
				strcpy(temp,date1[i]);
				strcpy(date1[i],date1[j]);
				strcpy(date1[j],temp);
			}
		}
	}	
	for(int i=0;i<cnt1;i++)
	{
		fin.open("Shedule.txt", ios::in);
		cout<<"\t\t\tDate->"<<date1[i]<<endl<<endl;
		fin>>flight_no>>to>>from>>departure>>arrival>>date;
		while(!fin.eof())
		{
			if(strcmp(date1[i],date)==0)
			{
				cout<<flight_no<<"\t\t"<<to<<"\t\t"<<from<<"\t\t"<<departure<<"\t\t"<<arrival<<"\n";
			}
			fin>>flight_no>>to>>from>>departure>>arrival>>date;
		}
		fin.close();
		for(int i=0; i<78; i++)
		cout<<"*";
		cout<<"\n";	
	}
}

void Flight::Delete_flight()
{
	int flag=1;
	string f_no,dat1,dat,arrival_t1,arrival_t,departure_t1;
	ifstream fin;
	ofstream f1;
	fin.open("Shedule.txt", ios::in);
	f1.open("Temp.txt", ios::out);
	cout<<"Enter flight number: ";
	cin>>f_no;
	cout<<"Enter the date: " ;
	cin>>dat; 
	cout<<"Enter the arrival time: ";
	cin>>arrival_t;
		fin>>flight_no>>to>>from>>arrival_t1>>departure>>dat1;
	while(!fin.eof())
	{
		if (flight_no!=f_no||arrival_t!=arrival_t1||dat!=dat1)
		{
			f1<<flight_no<<"\t\t"<<to<<"\t"<<from<<"\t"<<"\t"<<departure<<"\t\t"<<arrival_t1<<"\t\t"<<dat1<<endl;
		}
		else
		flag=0;
		fin>>flight_no>>to>>from>>departure>>arrival_t1>>dat1;	
	}
	fin.close();
	f1.close();
	remove("Shedule.txt");
	rename("Temp.txt", "Shedule.txt");
	if (flag==1)
	cout<<"\nFlight not exist\n";
}

void Flight::Update_flight()
{
	string f_no;
	cout<<"Enter flight number: ";
	cin>>f_no;
	ifstream fin;
	ofstream f1;
	fin.open("Shedule.txt", ios::in);
	f1.open("Temp.txt", ios::out);
	fin>>flight_no>>to>>from>>departure>>arrival>>da;
	while(!fin.eof())
	{
		if (flight_no!=f_no)
		{
			f1<<flight_no<<"\t\t"<<to<<"\t"<<from<<"\t"<<"\t"<<departure<<"\t\t"<<arrival<<"\t\t"<<da<<endl;
		}
		else
		{
			fflush(stdin);
			cout<<"To: ";		
			getline(cin, to);
			cout<<"From: ";		
			getline(cin, from);
			fflush(stdin);
			cout<<"Departure Time: ";
			cin>>departure;
			cout<<"Arrival Time: ";
			cin>>arrival;
			cout<<"Date:";
			cin>>da;
			if(f1.is_open())
			{	
				f1<<flight_no<<"\t\t"<<to<<"\t"<<from<<"\t"<<"\t"<<departure<<"\t\t"<<arrival<<"\t\t"<<da<<endl;
			}
		}
		fin>>flight_no>>to>>from>>departure>>arrival>>da;
	}
	fin.close();
	f1.close();
	remove("Shedule.txt");
	rename("Temp.txt", "Shedule.txt");
}

void Flight::Update_Shedule()
{
	string dat1,dat,arrival_t1,arrival_t,departure_t,departure_t1;
	ifstream fin;
	ofstream f1;
	fin.open("Shedule.txt", ios::in);
	f1.open("Temp.txt", ios::out);
	arrival_t1=currentTime();
	dat1=currentDate();
	fin>>flight_no>>to>>from>>departure>>arrival_t>>dat;
	while(!fin.eof())
	{
		if (dat1.compare(dat)<0)
		{
			f1<<flight_no<<"\t\t"<<to<<"\t"<<from<<"\t"<<"\t"<<departure<<"\t\t"<<arrival_t<<"\t\t"<<dat<<endl;
		}
		else if (dat1.compare(dat)==0)
		{
			if (arrival_t1.compare(arrival_t)<=0)
			{
				f1<<flight_no<<"\t\t"<<to<<"\t"<<from<<"\t"<<"\t"<<departure<<"\t\t"<<arrival_t<<"\t\t"<<dat<<endl;
			}
		}
		fin>>flight_no>>to>>from>>departure>>arrival_t>>dat;
	}
	fin.close();
	f1.close();
	remove("Shedule.txt");
	rename("Temp.txt", "Shedule.txt");
}

bool Flight::Check_Flight(string f_no,string departure_t,string arrival_t,int a)
{
	ifstream fin;
	fin.open("Shedule.txt", ios::in);
	string arrival_t1,departure_t1;
	fin>>flight_no>>to>>from>>departure_t1>>arrival_t1>>da;
	while(!fin.eof())
	{
		if (flight_no==f_no&&arrival_t1==arrival_t&&departure_t1==departure_t)
		{
			if (a==1)
			{
				show();
				cout<<flight_no<<"\t\t"<<to<<"\t"<<from<<"\t"<<departure_t1<<"\t\t"<<arrival_t1<<"\t\t"<<da<<"\n";
			}
			fin.close();
			return 1;
		}
		fin>>flight_no>>to>>from>>departure_t1>>arrival_t1>>da;
	}	
	fin.close();
	return 0;
}

void User::Book_ticket()
{
	ofstream fout;
	string arrival_t,departure_t,f_no;
	int flag=0;
	long long ticket;
	fout.open("Ticket_No.txt",ios::out | ios::app);
	tick:
	system("cls");
	fly.View_schedule();
	cout<<"\nEnter Flight Number: ";
	cin>>f_no;
	cout<<"Enter Departure Time: ";
	cin>>departure_t;
	cout<<"Enter Arrival Time: ";
	cin>>arrival_t;
	flag = fly.Check_Flight(f_no,departure_t,arrival_t,0);
	if(flag==1)
	{
		srand(time (0));
		ticket = 100000+ rand()%999999;
		fout<<ticket<<"\t"<<f_no<<"\t"<<departure_t<<"\t"<<arrival_t<<"\n";
		cout<<"\nTicket Number: "<<ticket;
	}
	else if(flag==0)
	{
		system("cls");
		cout<<"\nNo Flight Found\n";
		Sleep(1000);
		goto tick;
	}
	fout.close();
}

void User::Flight_Details()
{
	int flag=1;
	ifstream fin;
	fin.open("Ticket_No.txt",ios::in);
	string t_no,ticket,arrival_t,departure_t,f_no1;
	cout<<"Enter Ticket Number: ";
	cin>>t_no;
	fin>>ticket>>f_no1>>departure_t>>arrival_t;
	while(!fin.eof())
	{
		if (t_no==ticket)
		{
			fin.close();
			flag=fly.Check_Flight(f_no1,departure_t,arrival_t,1);
			if(flag==0)
				cout<<"Flight Not Exist!"<<endl;
			return;
		}
		fin>>ticket>>f_no1>>departure_t>>arrival_t;
	}
	cout<<"\nTicket No. not exist\n";
}

bool User::AddUser(char ch)
{
	User u=*this;
	if(ch=='a'||ch=='A')
	{
		cin>>u;
	}
	else if (ch=='b'||ch=='B')
	{
		cout<<"\nEnter CNIC Number: \n" ;
		cout<<"     -       - \r";
		cin>>c;
		if(CheckUser(c))
		{
			return true;
		}
		else
		return false;
	}
}
bool User::CheckUser(CNIC Cnic)
{
	ifstream fin;
	CNIC cnic;
	fin.open("User_Data.txt",ios::in);
	fin>>name>>F_name>>cnic>>nationality>>passport;
	if(fin.is_open())
	{
		while(!fin.eof())
		{
			if(cnic==Cnic)
			{
				fin.close();
				return true;
			}
			fin>>name>>F_name>>cnic>>nationality>>passport;
		}
		fin.close();
		return false;
	}
	return false;
}
void GroundStaff::display()
{
	ifstream fin;
	fin.open("Ground_Staff.txt", ios::in);
	if(fin.is_open())
	{
		cout<<"\n\t\tGround Staff Details\n\n";
		cout<<"Name\t\tCNIC\t\t\tDesignation\tSalary\n";
		fin>>c>>name>>Designation>>salary;
		while(!fin.eof())
		{
			cout<<name<<"\t\t"<<c<<"\t\t"<<Designation<<"\t\t"<<salary<<"\n";
			fin>>c>>name>>Designation>>salary;
		}
	}
	else
	{
		cout<<"File not found!";	
	}	
	fin.close();
}
bool GroundStaff::CheckStaff(CNIC Cnic)
{
	ifstream fin;
	CNIC cnic;
	fin.open("Ground_Staff.txt",ios::in);
	fin>>cnic>>name>>Designation>>salary;
	while(!fin.eof())
	{
		if(Cnic==cnic)
		{
			fin.close();
			return true;
		}
		fin>>cnic>>name>>Designation>>salary;
	}
	fin.close();
	return false;
}
void GroundStaff::StaffDetails()
{
	ofstream fout;
	fout.open("Ground_Staff.txt",ios::out | ios::app);
	cnic:
	cout<<"\nEnter CNIC Number: \n" ;
	cout<<"     -       - \r";
	cin>>c;
	if(!CheckStaff(c))
	{
		fflush(stdin);
		cout<<"\nEnter name: ";
		getline(cin, name);
		cout<<"Enter designation: ";
		cin>>Designation;
		cout<<"Enter duty hours: ";
		cin>>Duty_Hours;
		salary=(1000*Duty_Hours);
		fout<<c<<"\t\t"<<name<<"\t\t"<<Designation<<"\t\t"<<salary<<"\n";
	}
	else
	{
		cout<<"\nAlready Registered!";
		goto cnic;
	}
	fout.close();
}
void GroundStaff::DelDetails()
{
	ifstream fin;
	ofstream fout;
	CNIC cnic;
	cnic:
	int flag=0;
	fin.open("Ground_Staff.txt",ios::in);
	fout.open("Ground_Staff1.txt",ios::out | ios::app);
	cout<<"\nEnter CNIC Number: \n" ;
	cout<<"     -       - \r";
	cin>>cnic;
	fflush(stdin);
	fin>>c>>name>>Designation>>salary;
	while(!fin.eof())
	{
		if(!(cnic==c))
		{
			fout<<c<<"\t\t"<<name<<"\t\t"<<Designation<<"\t\t"<<salary<<"\n";		
		}
		else
		{
			flag=1;
		}
		fin>>c>>name>>Designation>>salary;
	}
	fin.close();
	fout.close();
	remove("Ground_Staff.txt");
	rename("Ground_Staff1.txt","Ground_Staff.txt");
	if(flag==0)
	{
		cout<<"Not Registered!";
		goto cnic;
	}
}
void GroundStaff::EditDetails()
{
	ifstream fin;
	ofstream fout;
	CNIC cnic;
	cnic:
	int flag=0;
	fin.open("Ground_Staff.txt",ios::in);
	fout.open("Ground_Staff1.txt",ios::out | ios::app);
	cout<<"\nEnter CNIC Number: \n" ;
	cout<<"     -       - \r";
	cin>>cnic;
	fflush(stdin);
	fin>>c>>name>>Designation>>salary;
	while(!fin.eof())
	{
		if(cnic==c)
		{
			flag=1;
			cout<<"\nEnter name: ";
			getline(cin, name);
			cout<<"Enter designation: ";
			cin>>Designation;
			cout<<"Enter duty hours: ";
			cin>>Duty_Hours;
			salary=(2000*Duty_Hours);
			fout<<c<<"\t\t"<<name<<"\t\t"<<Designation<<"\t\t"<<salary<<"\n";
		}
		else
		{
			fout<<c<<"\t\t"<<name<<"\t\t"<<Designation<<"\t\t"<<salary<<"\n";	
		}
		fin>>c>>name>>Designation>>salary;
	}
	fin.close();
	fout.close();
	remove("Ground_Staff.txt");
	rename("Ground_Staff1.txt","Ground_Staff.txt");
	if(flag==0)
	{
		cout<<"Not Registered!";
		goto cnic;
	}
}
void FlightCrew::display()
{
	ifstream fin;
	fin.open("Flight_Crew.txt", ios::in);
	if(fin.is_open())
	{
		cout<<"\n\t\tFlight Crew Details\n\n";
		cout<<"Name\t\tCNIC\t\t\tDesignation\tSalary\n";
		fin>>c>>name>>Designation>>salary;
		while(!fin.eof())
		{
			cout<<name<<"\t\t"<<c<<"\t\t"<<Designation<<"\t\t"<<salary<<"\n";
			fin>>c>>name>>Designation>>salary;
		}
	}
	else
	{
		cout<<"File not found!";	
	}	
	fin.close();
}
bool FlightCrew::CheckStaff(CNIC Cnic)
{
	ifstream fin;
	CNIC cnic;
	fin.open("Flight_Crew.txt",ios::in);
	fin>>cnic>>name>>Designation>>salary;
	while(!fin.eof())
	{
		if(Cnic==cnic)
		{
			fin.close();
			return true;
		}
		fin>>cnic>>name>>Designation>>salary;
	}
	fin.close();
	return false;
}
void FlightCrew::StaffDetails()
{
	ofstream fout;
	fout.open("Flight_Crew.txt",ios::out | ios::app);
	cout<<"\nEnter CNIC Number: \n" ;
	cout<<"     -       - \r";
	cin>>c;
	if(!CheckStaff(c))
	{
		fflush(stdin);
		cout<<"\nEnter name: ";
		getline(cin, name);
		cout<<"Enter designation: ";
		cin>>Designation;
		cout<<"Enter duty hours: ";
		cin>>Duty_Hours;
		salary =(2000*Duty_Hours);
		fout<<c<<"\t\t"<<name<<"\t\t"<<Designation<<"\t\t"<<salary<<"\n";
	}
	else
	cout<<"\nAlready Registered!";	
	fout.close();
}
void FlightCrew::EditDetails()
{
	ifstream fin;
	ofstream fout;
	CNIC cnic;
	cnic:
	int flag=0;
	fin.open("Flight_Crew.txt",ios::in);
	fout.open("Flight_Crew1.txt",ios::out | ios::app);
	cout<<"\nEnter CNIC Number: \n" ;
	cout<<"     -       - \r";
	cin>>cnic;
	fflush(stdin);
	fin>>c>>name>>Designation>>salary;
	while(!fin.eof())
	{
		if(cnic==c)
		{
			flag=1;
			cout<<"\nEnter name: ";
			getline(cin, name);
			cout<<"Enter designation: ";
			cin>>Designation;
			cout<<"Enter duty hours: ";
			cin>>Duty_Hours;
			salary=(2000*Duty_Hours);
			fout<<c<<"\t\t"<<name<<"\t\t"<<Designation<<"\t\t"<<salary<<"\n";
		}
		else
		{
			fout<<c<<"\t\t"<<name<<"\t\t"<<Designation<<"\t\t"<<salary<<"\n";	
		}
		fin>>c>>name>>Designation>>salary;
	}
	fin.close();
	fout.close();
	remove("Flight_Crew.txt");
	rename("Flight_Crew1.txt","Flight_Crew.txt");
	if(flag==0)
	{
		cout<<"Not Registered!";
		goto cnic;
	}
}
void FlightCrew::DelDetails()
{
	ifstream fin;
	ofstream fout;
	CNIC cnic;
	cnic:
	int flag=0;
	fin.open("Flight_Crew.txt",ios::in);
	fout.open("Flight_Crew1.txt",ios::out | ios::app);
	cout<<"\nEnter CNIC Number: \n" ;
	cout<<"     -       - \r";
	cin>>cnic;
	fflush(stdin);
	fin>>c>>name>>Designation>>salary;
	while(!fin.eof())
	{
		if(!(cnic==c))
		{
			fout<<c<<"\t\t"<<name<<"\t\t"<<Designation<<"\t\t"<<salary<<"\n";
		}
		else
		{
			flag=1;
		}
		fin>>c>>name>>Designation>>salary;
	}
	fin.close();
	fout.close();
	remove("Flight_Crew.txt");
	rename("Flight_Crew1.txt","Flight_Crew.txt");
	if(flag==0)
	{
		cout<<"Not Registered!";
		goto cnic;
	}
}
bool Authorizedperson::CheckAuthorized(string alogin_id,char pass[])
{
	string pass1;
	ifstream fin;
	fin.open("Authorize_Person.txt",ios::in);
	fin>>login_id>>pass1;
	while(!fin.eof())
	{
		if(alogin_id==login_id)
		{
			if(pass==pass1)
			{
				fin.close();
				return true;	
			}
		}
		fin>>login_id>>pass1;
	}
	fin.close();
	delete[] password;
	return false;
}
void Authorizedperson::changepass()
{
	int i=0,flag=0;
	char pass[20],pass1[20];
	string alogin_id;
	fstream fin, f1;
	againold:
	i=0;
	cout<<"\nEnter the old password: ";
	while(1)
	{
		pass[i] = getch();
		if(pass[i]=='\r')
		{
			pass[i] = '\0';
			break;
		}
		else if(pass[i]=='\b')
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
	fin.open("Authorize_Person.txt",ios::in);
	f1.open("Temp_Password.txt",ios::out);
	fin>>alogin_id>>pass1;
	while(!fin.eof())
	{
		if(alogin_id==login_id)
		{
			if(strcmp(pass,pass1)==0)
			{
				flag=1;
				againpass:
				i=0;
				cout<<"\nEnter the new password: ";
				while(1)
				{	
					pass[i] = getch();
					if(pass[i]=='\r')
					{
						pass[i] = '\0';
						break;
					}
					else if(pass[i]=='\b')
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
				i=0;
				cout<<"\nRenter the new password: ";
				while(1)
				{	
					pass1[i] = getch();
					if(pass1[i]=='\r')
					{
						pass1[i] = '\0';
						break;
					}
					else if(pass1[i]=='\b')
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
				if(strcmp(pass,pass1)!=0)
				{
					cout<<"\nPassword not match!";
					Sleep(2000);
					system("cls");
					goto againpass;
				}
				else
				{
					f1<<alogin_id<<"\t"<<pass1<<"\n";
				}
			}
		}
		else
		{
			f1<<alogin_id<<"\t"<<pass1<<"\n";
		}
		fin>>alogin_id>>pass1;
	}
	if(flag==0)
	{
		cout<<"\nWrong Old Password!";
		fin.close();
		f1.close();
		goto againold;
	}
	fin.close();
	f1.close();
	remove("Authorize_Person.txt");
	rename("Temp_Password.txt", "Authorize_Person.txt");
}
