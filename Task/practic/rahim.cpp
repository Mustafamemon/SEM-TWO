#include<iostream>
#include<cstring>
using namespace std;
template <typename T>
void my_cast(T* t, T* u){
	T temp;
	temp=*t;
	*t=*u;
	*u=temp;
}
template<>
void my_cast(char a[],char b[]){
	char temp[7];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}
int main(){
	char a[4],b[5];
	strcpy(a,"You");
	strcpy(b,"Love");
	my_cast<char>(a,b);
	cout<<a<<"\t"<<b;
	return 0;
}
