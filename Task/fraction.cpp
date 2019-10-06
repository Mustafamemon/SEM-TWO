#include<iostream>
#include<fstream>
#include<cstring>
using namespace std ;
int main()
{
	string ch="ff";
	char ch1[20]={"ff"};
	fstream f;
	f.open("abcd.txt",ios::in | ios::out);
	f.seekg(0,f.end);
	int a=f.tellp();
	f.seekg(0,f.beg);
	cout<<a;
	f>>ch1;
	while(!f.eof())
	{
		//cout<<ch1<<"\n";
		if(ch==ch1)
		{
			cout<<f.tellg()<<"\n";
			f.seekp((int)f.tellg()-(2));
			f<<"ab\n";
		}
		
		f>>ch1;
	}
	f.close();
}
