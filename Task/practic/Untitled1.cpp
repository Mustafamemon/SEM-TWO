#include<fstream>
#include<cstring>
#include<iostream>
using namespace std;
class combinational{
private:
	char *name;
	int noof_ics;
	float cost;
public:
	combinational(char ch[] , int n , float c){
		int l = strlen(ch);
		name=new char[l+1];
		strcpy(name,ch);
		noof_ics=n;
		cost=c;
	}
	void print()const
	{
		cout<<"\nName: "<<name;
		cout<<"\nNo Of ICs: "<<noof_ics;
		cout<<"\nCost: "<<cost;
	}
	~combinational(){
		delete []name;
	}
	void allocate()
	{
		delete []name;
		name=new char [20];
	}
};
class Mux:public combinational{
private:
	int select[2];
	int input[4];
	int output;
public:
	Mux(char ch[],int n,float c ,int s[],int j[]):combinational(ch , n ,c)
	{
		for(int i=0;i<2;i++)
		select[i]=s[i];
		for(int i=0;i<4;i++)
		input[i]=j[i];
		M_Output();
	}
	void M_Output()
	{
		if(select[0]==0)
		{
			if(select[1]==0)
			output=input[0];
			else if(select[1]==1)
			output=input[1];
		}
		else if(select[0]==1)
		{
			if(select[1]==0)
			output=input[2];
			else if(select[1]==1)
			output=input[3];
		}
	}
	void storedata()
	{
		ofstream fout;
		fout.open("helloworld.dat",ios::app | ios::out | ios::binary);
		fout.write((char*)this,sizeof(*this));
		fout.close();
	}
	void read()
	{
		ifstream fin;
		fin.open("helloworld.dat",ios::in);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			print();
			fin.read((char*)this,sizeof(*this));	
		}
		fin.close();
	}
	void print()const
	{
		combinational::print();
		cout<<"\nSelect: {"<<select[0]<<","<<select[1]<<"}";
		cout<<"\nInput: {"<<input[0]<<","<<input[1]<<","<<input[2]<<","<<input[3]<<"}";
		cout<<"\nOutput: "<<output;
	}
};
class Priority:public combinational{
private:
	int input[4];
	int output[2];
public:
	Priority(char ch[],int n,float c ,int j[]):combinational(ch , n ,c)
	{
		for(int i=0;i<4;i++)
		input[i]=j[i];
		E_output();
	}
	void E_output()
	{
		if(input[0]==1&&input[1]==0&&input[2]==0&&input[3]==0)
		{
			output[0]=0;
			output[1]=0;
		}
		else if(input[0]==0&&input[1]==1&&input[2]==0&&input[3]==0)
		{
			output[0]=0;
			output[1]=1;
		}
		else if(input[0]==0&&input[1]==0&&input[2]==1&&input[3]==0)
		{
			output[0]=1;
			output[1]=0;
		}
		else if(input[0]==0&&input[1]==0&&input[2]==0&&input[3]==1)
		{
			output[0]=1;
			output[1]=1;
		}
		else if(input[0]==0&&input[1]==0&&input[2]==0&&input[3]==0)
		{
			output[0]=2;
			output[1]=2;
		}
	}
	void print()const
	{
		combinational::print();
		cout<<"Input: {"<<input[0]<<","<<input[1]<<","<<input[2]<<","<<input[3]<<"}";
		if(output[0]!=2)
		cout<<"\nnOutput Q Q': "<<output[0]<<" "<<output[1];
		else
		cout<<"\nOutput Q Q': "<<"x x";
	}
}; 
int main()
{
	int i[]={1,0,1,0};
	int s[]={1,0};
	char ch[]={"Multiplexer"};
	Mux obj(ch,10,1500,s,i);
	obj.print();
	obj.storedata();
	obj.read();
	int i1[]={1,0,1,0};
	char ch1[]={"Priority Encoder"};
	Priority obj1(ch1,18,900,i1);
	obj1.print();
	return 0;	
}
