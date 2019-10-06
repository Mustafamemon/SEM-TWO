#include<iostream>
using namespace std ;
class Toto{
private :
	int age;
public :
	int GetAge(int);
};
int Toto::GetAge(int){
return age;
}
int main (){
	Toto t ;
	int aage ;
	cin>>aage; 
	cout<<t.GetAge(aage);
}
