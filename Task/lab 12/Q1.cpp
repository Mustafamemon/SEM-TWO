#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class Inventory{
private:
	int code;
	char desp[20];
	float rate;
	float tunits;
public:
	Inventory(int acode , char adesp[] , float arate , float atunits)
	{
		code=acode;
		strcpy(desp,adesp);
		rate=arate;
		tunits=atunits;
		file();
	}
	void edit(int acode)
	{
		fstream fin;
		fin.open("FILE.txt",ios::in|ios::out);
		if(fin.is_open())
		{
			fin.read((char *)this,sizeof(*this));
			while(!fin.eof())
			{
				if(acode==code)
				{
					fin.seekp((int)fin.tellg()-sizeof(*this));
					cout<<"\nENTER THE TOTAL UNITS IN STOCK :";
					cin>>tunits;
					fin.write((char *)this,sizeof(*this));
				}
				fin.read((char *)this,sizeof(*this));
			}
			fin.close();
		}
	}
	void file()
	{
		ofstream fout;
		fout.open("FILE.txt",ios::out | ios::app);
		fout.write((char *)this,sizeof(*this));
		fout.close();
	}
	void display(int acode)
	{
		ifstream fin;
		fin.open("FILE.txt",ios::in);
		if(fin.is_open())
		{
			cout<<"CODE"<<"\t"<<"DESCRITION"<<"\t"<<"RATE"<<"\t"<<"T-Unit\n" ;
			fin.read((char *)this,sizeof(*this));
			while(!fin.eof())
			{
				if(acode==code)
				cout<<code<<"\t"<<desp<<"\t\t"<<rate<<"\t"<<tunits<<"\n";
				fin.read((char *)this,sizeof(*this));
			}
			fin.close();
		}
	}
	void display()
	{
		ifstream fin;
		fin.open("FILE.txt",ios::in);
		if(fin.is_open())
		{
			cout<<"CODE"<<"\t"<<"DESCRITION"<<"\t"<<"RATE"<<"\t"<<"T-Unit\n" ;
			fin.read((char *)this,sizeof(*this));
			while(!fin.eof())
			{
				cout<<code<<"\t\t"<<desp<<"\t"<<rate<<"\t"<<tunits<<"\n";
				fin.read((char *)this,sizeof(*this));
			}
			fin.close();
		}
	}
};
int main()
{
	int ans,ans1,a;
	char ch[]={"ABCD"},ch1[]={"abcd"},ch2[]={"Kol"},ch3[]={"lmn"},ch4[]={"efg"};
	Inventory obj(113,ch,11.0,20.0),obj1(123,ch1,12.0,30.0),obj2(133,ch2,13.0,40.0),obj3(143,ch3,14.0,50.0),obj4(163,ch4,15.0,60.0);
	do
	{
		MENU:
		cout<<"\n1.Object 1\n2.Object 2\n3.Object 3\n4.Object 4\n5.Object 5\n6.Exit\n";
		cin>>ans;
		if(ans==1)
		{
			while(1)
			{
				cout<<"\n1.Edit\n2.Display\n3:Display Particular Data\n4.Back to main\n";
				cin>>ans1;
				if(ans1==1)
				{
					cout<<"Enter The Code No : ";
					cin>>a;
					obj.edit(a);
				}
				else if(ans1==2)
				{
					obj.display();		
				}
				else if(ans1==3)
				{
					cout<<"Enter The Code No : ";
					cin>>a;
					obj.display(a);
				}
				else if(ans1==4)
				{
					goto MENU;
				}
			}
		}
		else if(ans==2)
		{
			while(1)
			{
				cout<<"\n1.Edit\n2.Display\n3:Display Particular Data\n4.Back to main\n";
				cin>>ans1;
				if(ans1==1)
				{
					cout<<"Enter The Code No : ";
					cin>>a;
					obj1.edit(a);
				}
				else if(ans1==2)
				{
					obj1.display();		
				}
				else if(ans1==3)
				{
					cout<<"Enter The Code No : ";
					cin>>a;
					obj1.display(a);
				}
				else if(ans1==4)
				{
					goto MENU;
				}
			}
		}
		else  if(ans==3)
		{
			while(1)
			{
				cout<<"\n1.Edit\n2.Display\n3:Display Particular Data\n4.Back to main\n";
				cin>>ans1;
				if(ans1==1)
				{
					cout<<"Enter The Code No : ";
					cin>>a;
					obj2.edit(a);
				}
				else if(ans1==2)
				{
					obj2.display();		
				}
				else if(ans1==3)
				{
					cout<<"Enter The Code No : ";
					cin>>a;
					obj2.display(a);
				}
				else if(ans1==4)
				{
					goto MENU;
				}
			}
		}
		else if(ans==4)
		{
			while(1)
			{
				cout<<"\n1.Edit\n2.Display\n3:Display Particular Data\n4.Back to main\n";
				cin>>ans1;
				if(ans1==1)
				{
					cout<<"Enter The Code No : ";
					cin>>a;
					obj3.edit(a);
				}
				else if(ans1==2)
				{
					obj3.display();		
				}
				else if(ans1==3)
				{
					cout<<"Enter The Code No : ";
					cin>>a;
					obj3.display(a);
				}
				else if(ans1==4)
				{
					goto MENU;
				}
			}
		}
		else if(ans==5)
		{
			while(1)
			{
				cout<<"\n1.Edit\n2.Display\n3:Display Particular Data\n4.Back to main\n";
				cin>>ans1;
				if(ans1==1)
				{
					cout<<"Enter The Code No : ";
					cin>>a;
					obj4.edit(a);
				}
				else if(ans1==2)
				{
					obj4.display();		
				}
				else if(ans1==3)
				{
					cout<<"Enter The Code No : ";
					cin>>a;
					obj4.display(a);
				}
				else if(ans1==4)
				{
					goto MENU;
				}
			}
		}
	}while(ans!=6);
	return 0;
}
