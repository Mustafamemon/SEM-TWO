#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include <cwchar>
using namespace std;

void front()
{
//	CONSOLE_FONT_INFOEX cfi;
//	cfi.cbSize = sizeof(cfi);
//	cfi.nFont = 0;
//	cfi.dwFontSize.X = 0;                   // Width of each character in the font
//	cfi.dwFontSize.Y = 24;                  // Height
//	cfi.FontFamily = FF_DONTCARE;
//	cfi.FontWeight = FW_NORMAL;
//	wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
//	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
//	cout << "Font: Consolas, Size: 24\n";
	system("color 30");
	char a=219;
	cout<<"\n\n\n\n\n\n\n\n\t\t\t        LOADING! \n";
	cout<<"\t\t\t  ";
	for(int i=0;i<=18;i++)
	{
		cout<<a;
		Sleep(50);
	}
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\t\t\tAirline Management System";
	cout<<"\n\n\n\t\t\tDesigned By:\n\n\t\t\tHuzaifa Abid\t17K-3807\n\t\t\tDanish Abdullah\t17K-3720\n\t\t\tMustafa Manga\t17K-3795\n\n\n\n\n";
	cout<<"\t\t\tPress Any Key To Begin";
	getch();
	
}
void menu()
{
	front();
	char ch;
	User u;
	Authorizedperson a;
	Flight f;
	Employee *Eptr;
	GroundStaff gs;
	FlightCrew fc;
	string username;
	system("color 30");
	again:
	system("cls");
	cout<<"\n\n\n\n\n\n\t\t\t-------------------------\n";
	cout<<"\t\t\t| A. User\t\t|\n\t\t\t-------------------------\n\t\t\t| B. Authorized Person\t|";
	cout<<"\n\t\t\t-------------------------\n";
	cout<<"\t\t\t| Esc. Exit\t\t|\n";
	cout<<"\t\t\t-------------------------\n\n";
	cout<<"\t\t\tEnter a choice: ";
	ch=getche();
	if (ch=='a' || ch=='A')
	{
		usermain:
		system("cls");
		cout<<"\n\n\n\n\n\n\t\t\t--------------------------\n";
		cout<<"\t\t\t| A. Book Ticket\t |\n\t\t\t--------------------------\n\t\t\t| B. View Schedule\t |";
		cout<<"\n\t\t\t--------------------------\n";
		cout<<"\t\t\t| C. Flight Details\t |\n";
		cout<<"\t\t\t--------------------------\n";
		cout<<"\t\t\t| R. Return to main menu |\n";
		cout<<"\t\t\t--------------------------\n";
		cout<<"\t\t\t| Esc. Exit\t\t |\n";
		cout<<"\t\t\t--------------------------\n\n";
		cout<<"\t\t\tEnter a choice: ";
		ch=getche();
		if (ch=='a' || ch=='A')
		{
			
			user:
			system("cls");
			cout<<"\n\n\n\n\n\n\t\t\t------------------------------\n";
			cout<<"\t\t\t| A. New User\t\t     |\n\t\t\t------------------------------\n\t\t\t| B. Existing User\t     |";
			cout<<"\n\t\t\t------------------------------\n";
			cout<<"\t\t\t| R. Return to previous menu |\n";
			cout<<"\t\t\t------------------------------\n";
			cout<<"\t\t\t| M. Return to main menu     |\n";
			cout<<"\t\t\t------------------------------\n";
			cout<<"\t\t\t| Esc. Exit\t\t     |\n";
			cout<<"\t\t\t------------------------------\n\n";
			cout<<"\t\t\tEnter a choice: ";
			ch=getche();
			if (ch=='a' || ch=='A')
			{
				system("cls");
				u.AddUser(ch);
				u.Book_ticket();
				cout<<"\nPress Any Key to Continue...";
				getche();
				goto usermain;
			}
			else if (ch=='b' || ch=='B')
			{
				system("cls");
				adduser:
				if (u.AddUser(ch))
				{
					u.Book_ticket();
					cout<<"\nPress Any Key to Continue...";
					getche();
					goto usermain;
				}
				else
				{
					cout<<"Not Registered!";
					Sleep(1500);
					system("cls");
					goto adduser;
				}
			}
			else if (ch=='r' || ch=='R')
			{
				goto usermain;
			}
			else if (ch=='m' || ch=='M')
			{
				goto again;
			}
			else if ((int)ch==27)
			{
				exit(0);
			}
			else
			{
				system("cls");
				cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tInvalid Input!";
				Sleep(1500);
				system("cls");
				goto user;
			}
		}
		else if (ch=='b' || ch=='B')
		{
			system("cls");
			f.View_schedule();
			cout<<"\nPress Any Key to Continue...";
			getche();
			goto usermain;
		}
		else if (ch=='c' || ch=='C')
		{
			system("cls");
			u.Flight_Details();
			cout<<"\nPress Any Key to Continue...";
			getche();
			goto usermain;
		}
		else if (ch=='r' || ch=='R')
		{
			goto again;
		}
		else if ((int)ch==27)
		{
			exit(0);
		}
		else
		{
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tInvalid Input!";
			Sleep(1500);
			system("cls");
			goto usermain;
		}
	}
	else if (ch=='b' || ch=='B')
	{
		login_again:
		system("cls");
		cout<<"\n\n\n\n\n\n\t\t\t"<<"Enter Username: ";
		cin>>a;
		cout<<a.get_id();cout<<a.get_pass();
		if(a.CheckAuthorized(a.get_id(),a.get_pass()))
		{
			
		}
		else
		{
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\n\t\t\tInvalid User Name or Password!";
			Sleep(1500);
			system("cls");
			goto login_again;
		}
		authorize:
		system("cls");
		cout<<"\n\n\n\n\n\n\t\t\t--------------------------\n";
		cout<<"\t\t\t| A. Add Flight\t\t |\n\t\t\t--------------------------\n\t\t\t| B. Delete Flight \t |";
		cout<<"\n\t\t\t--------------------------\n";
		cout<<"\t\t\t| C. Update Schedule\t |\n";
		cout<<"\t\t\t--------------------------\n";
		cout<<"\t\t\t| D. Refresh Schedule\t |\n";
		cout<<"\t\t\t--------------------------\n";
		cout<<"\t\t\t| E. Staff Details\t |\n\t\t\t--------------------------\n\t\t\t| F. Flight Details \t |";
		cout<<"\n\t\t\t--------------------------\n";
		cout<<"\t\t\t| G. Change Passwaord\t |\n";
		cout<<"\t\t\t--------------------------\n";
		cout<<"\t\t\t| R. Return to main menu |\n";
		cout<<"\t\t\t--------------------------\n";
		cout<<"\t\t\t| Esc. Exit\t\t |\n";
		cout<<"\t\t\t--------------------------\n\n";
		cout<<"\t\t\tEnter a choice: ";
		ch=getche();
		if (ch=='a' || ch=='A')
		{
			system("cls");
			f.Add_flight();
			goto authorize;
		}
		else if (ch=='b' || ch=='B')
		{
			system("cls");
			f.Delete_flight();
			goto authorize;
		}
		else if (ch=='c' || ch=='C')
		{
			system("cls");
			f.Update_flight();
			goto authorize;
		}
		else if (ch=='d' || ch=='D')
		{
			system("cls");
			f.Update_Shedule();
			goto authorize;
		}
		else if (ch=='e' || ch=='E')
		{
			Staff_Details:
			system("cls");
			cout<<"\n\n\n\n\n\n\t\t\t------------------------------\n";
			cout<<"\t\t\t| A. Ground Staff\t     |\n";
			cout<<"\t\t\t------------------------------\n";
			cout<<"\t\t\t| B. Flight Crew\t     |\n";
			cout<<"\t\t\t------------------------------\n";
			cout<<"\t\t\t| R. Return to previous menu |\n";
			cout<<"\t\t\t------------------------------\n";
			cout<<"\t\t\t| M. Return to main menu     |\n";
			cout<<"\t\t\t------------------------------\n";
			cout<<"\t\t\t| Esc. Exit\t\t     |\n";
			cout<<"\t\t\t------------------------------\n\n";
			cout<<"\t\t\tEnter a choice: ";
			ch=getche();
			if (ch=='a' || ch=='A')
			{
				Eptr = &gs;
				Ground_Staff:
				system("cls");
				cout<<"\n\n\n\n\n\n\t\t\t------------------------------\n";
				cout<<"\t\t\t| A. Add Details\t     |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| B. Edit Details\t     |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| C. View Details\t     |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| D. Delete Details\t     |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| R. Return to previous menu |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| M. Return to main menu     |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| Esc. Exit\t\t     |\n";
				cout<<"\t\t\t------------------------------\n\n";
				cout<<"\t\t\tEnter a choice: ";
				ch=getche();
				if (ch=='a' || ch=='A')
				{
					system("cls");
					Eptr->StaffDetails();
					goto Ground_Staff;
				}
				else if (ch=='b' || ch=='B')
				{
					system("cls");
					Eptr->EditDetails();
					goto Ground_Staff;
				}
				else if (ch=='c' || ch=='C')
				{
					system("cls");
					Eptr->display();
					cout<<"\nPress Any Key to Continue...";
					getche();
					goto Ground_Staff;
				}
				else if(ch=='d'||ch=='D')
				{
					system("cls");
					Eptr->DelDetails();
					goto Ground_Staff;
				}
				else if (ch=='r' || ch=='R')
				{
					goto Staff_Details;
				}
				else if (ch=='m' || ch=='M')
				{
					goto again;
				}
				else if ((int)ch==27)
				{
					exit(0);
				}
				else
				{
					system("cls");
					cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tInvalid Input!";
					Sleep(1500);
					system("cls");
					goto Ground_Staff;
				}
			}
			else if (ch=='b' || ch=='B')
			{
				Eptr = &fc;
				Flight_Crew:
				system("cls");
				cout<<"\n\n\n\n\n\n\t\t\t------------------------------\n";
				cout<<"\t\t\t| A. Add Details\t     |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| B. Edit Details\t     |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| C. View Details\t     |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| D. Delete Details\t     |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| R. Return to previous menu |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| M. Return to main menu     |\n";
				cout<<"\t\t\t------------------------------\n";
				cout<<"\t\t\t| Esc. Exit\t\t     |\n";
				cout<<"\t\t\t------------------------------\n\n";
				cout<<"\t\t\tEnter a choice: ";
				ch=getche();
				if (ch=='a' || ch=='A')
				{
					system("cls");
					Eptr->StaffDetails();
					goto Flight_Crew;
				}
				else if (ch=='b' || ch=='B')
				{
					system("cls");
					Eptr->EditDetails();
					goto Flight_Crew;
				}
				else if (ch=='c' || ch=='C')
				{
					system("cls");
					Eptr->display();
					cout<<"\nPress Any Key to Continue...";
					getche();
					goto Flight_Crew;
				}
				else if (ch=='d' || ch=='D')
				{
					system("cls");
					Eptr->DelDetails();
					goto Flight_Crew;
				}
				else if (ch=='r' || ch=='R')
				{
					goto Staff_Details;
				}
				else if (ch=='m' || ch=='M')
				{
					goto again;
				}
				else if ((int)ch==27)
				{
					exit(0);
				}
				else
				{
					system("cls");
					cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tInvalid Input!";
					Sleep(1500);
					system("cls");
					goto Flight_Crew;
				}
			}
			else if (ch=='r' || ch=='R')
			{
				goto authorize;
			}
			else if (ch=='m' || ch=='M')
			{
				goto again;
			}
			else if ((int)ch==27)
			{
				exit(0);
			}
			else
			{
				system("cls");
				cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tInvalid Input!";
				Sleep(1500);
				system("cls");
				goto Staff_Details;
			}
		}
		else if (ch=='f' || ch=='F')
		{
			system("cls");
			f.View_schedule();
			cout<<"\nPress Any Key to Continue...";
			getch();
			goto authorize;
		}
		else if(ch=='g' || ch=='G')
		{
			system("cls");
			a.changepass();
			goto authorize;
		}
		else if (ch=='r' || ch=='R')
		{
			goto again;
		}
		else if ((int)ch==27)
		{
			exit(0);
		}
		else
		{
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tInvalid Input!";
			Sleep(1500);
			system("cls");
			goto authorize;
		}
	}
	else if ((int)ch==27)
	{
		exit(0);
	}
	else
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tInvalid Input!";
		Sleep(1500);
		system("cls");
		goto again;
	}
}
