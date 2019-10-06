#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class Student{
	private:
		char* name; int age; string roll_no;
	public:
		Student(){
			name= new char[20];
			strcpy(name,"NULL");
			age=0;
			roll_no="NULL";
		}
		void set_name(){
			fflush(stdin);
			cout<<"Enter Student's Name: ";
			name= new char[20];
			cin.getline(name,15);	
		}
		void set_age(){
			cout<<"Enter Student's Age: ";
			cin>>age;
		}
		void set_rollno(){
			fflush(stdin);
			cout<<"Enter Student's Roll No: ";
			getline(cin,roll_no);
		}
		char* get_name(){
			return name;
		}
		void show_data(){
			cout<<"Student's Name: "<<name<<endl;
			cout<<"Student's Age: "<<age<<endl;
			cout<<"Student's Roll No: "<<roll_no;
			}
		void swap_descending(char* name1, char* name2){
			char* str = new char[20];			
			strcpy(str,name1);
			strcpy(name1,name2);
			strcpy(name2,str);
		}
};

main(){
	Student *stuarr= new Student[5];
	for(int i=0;i<5;i++){
		cout<<"ENTER DATA FOR STUDENT "<<i+1<<endl<<endl;
		stuarr[i].set_name();
	}
	for (int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			int r = strcmp(stuarr[j].get_name(),stuarr[j+1].get_name());
			if(r>0)
				stuarr->swap_descending(stuarr[j].get_name(),stuarr[j+1].get_name());
		}	
	}
		cout<<"___________"<<endl<<endl;
	system("CLS");
	for(int i=0;i<5;i++){
		cout<<"DATA OF STUDENT "<<i+1<<endl<<endl;
		stuarr[i].show_data();
		cout<<"\n_____________"<<endl<<endl;
	}
}
