#include<iostream>
#include<ostream>
#include<fstream>
#include<istream>
#include<conio.h>
using namespace std ;
int main()
{
	string ch  ;
	ofstream fout ;
	ifstream fin ;
	/*fout.open("MYFILE.txt");
	getline(cin,ch);
	fout<<ch ;
	fout.close();*/
	fin.open("E:\\newprogram.txt");
	ch = fin.get();
	while(!fin.eof()){
		cout<<ch ;
		ch = fin.get();
	}
	fin.close();
}
