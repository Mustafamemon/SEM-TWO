#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Name{
	private:
		char name[20];
		int age[10];
	public:
		Name(char *s , int a[])
		{
			strcpy (name , s);
			age[1] = a[1];
			cout<<age[1];
		}
		/*void setData(char *s , int a)
		{
			strcpy (name , s);
			age = a;
		}*/
		void display()
		{
			cout << "Name: " << name << " " << "Age: " << age << endl;
		}
		int storeName()
		{
			ofstream fout;
			fout.open("MyName.dat" , ios :: app | ios :: binary);
			fout.write( (char*)this , sizeof (*this) );
			fout.close();
		}
		void readName()
		{
			ifstream fin;
			fin.open("MyName.dat" , ios::in);
			if(!fin)
			{
				cout << "File is not available" << endl;
			}
			else 
			{
				fin.read((char*)this , sizeof(*this));
				while (!fin.eof())
				{
					display();
					fin.read((char*)this , sizeof(*this));
				}
				fin.close();
			}
		}
};
main()
{
	char ch[] = "Vishesh";
	int h[]={1,2};
	Name n(ch , h);
	n.storeName();
	n.readName();
}
