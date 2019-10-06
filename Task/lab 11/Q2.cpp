#include<iostream>
#include<fstream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
using namespace std ;
int main()
{
	string name;
	char n;
	cout<<"Enter the string: ";
	getline(cin,name);
	fstream f ;
	f.open("Myfile.txt",ios::out|ios::app);
	for(int i=0;i<=name.length();i++)
	{
		f.put(name[i]);	
	}
	f.put('\n');
	fstream fi ;
	f.close();
	f.open("Myfile.txt",ios::in);
	fi.open("Copied.txt",ios::out);
	while(!f.eof())
	{
		f.get(n);
		fi.put(n);
		cout<<n;
	}
	f.close();
	fi.close();
	getche();
	system("CLS");
	cout<<"Copying data...";
	Sleep(2000);
	cout<<"Copied";
	system("CLS");
	fi.open("Copied.txt",ios::in);
	while(!fi.eof())
	{
		fi.get(n);
		cout<<n;
	}
	fi.close();
}
