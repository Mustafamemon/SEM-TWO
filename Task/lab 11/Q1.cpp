#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std ;
int main()
{
	try{
		try{
			try{
				try{
					throw 1;
				}
				catch(float)
				{
					cout<<"a";
				}
			}
			catch(double)
			{
				cout<<"b";
			}
		}
		catch(char)
		{
			cout<<"Dd";
		}
		cout<<"helo";	
	}
	catch(int)
	{
		cout<<"s";
		throw;
	}
	catch(int)
	{
		cout<<"rr";
	}
	
}
