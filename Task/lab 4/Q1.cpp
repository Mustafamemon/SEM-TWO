#include<iostream>
using namespace std ;
int cnt = 0 ;
class shopping{
private :
	int codeno[50];
	float price[50];
	int qty[50];
	float total ;
public :
	~shopping(){
		cout<<"\nINFORMATION IS DELTETED" ;
	}
	shopping(){
		codeno[cnt] = 0 ;
		price[cnt] = 0 ;
		qty[cnt] = 0;
		total = 0 ;
		
	}
	void add_data(int c ,float p ,int q ){
		codeno[cnt] = c ;
		price[cnt] = p ;
		qty[cnt] = q ;
		total = total + (price[cnt]*qty[cnt]);
	}
	void delete_data(int c){
		int i , j ;
		for(i=0;i<cnt;i++){
			if (codeno[i]==c){
				total = total - (price[i]*qty[i]);
				for (j=i;j<cnt;j++){
					codeno[j]=codeno[j+1];
					price[j]=price[j+1];
					qty[j]=qty[j+1];
				}
				--cnt ;
				break ;
			}
		}
	}
	void show_data(){
		cout<<"CODE No\tPRICE\tQUANTITY\n" ;
		int i = 0 ;
		for(i=0;i<cnt;i++)
		cout<<"\n"<<codeno[i]<<"\t"<<price[i]<<"\t"<<qty[i]<<"\n" ;
	}
	float total_1(){
		return total ;
	}
};
int main(){
	float ap ;
	int ans , aq , ac ;
	shopping c1 ;
	do{
	cout<<"1:ADD DATA\n2:DELETE DATA\n3:SHOW DATA\n4:EXIT\n" ;
	cin>>ans ;
	if(ans==1){
	cout<<"ENTER THE CODE NO : ";
	cin>>ac ;
	cout<<"ENTER THE PRICE : " ;
	cin>>ap;
	cout<<"ENTER THE QUANTITY : " ; 
	cin>>aq ;
	c1.add_data(ac,ap,aq);
	++cnt ;
	}
	else if(ans==2){
	cout<<"ENTER THE CODE NO : ";
	cin>>ac ;
	c1.delete_data(ac);
	}
	else if(ans==3)
	c1.show_data();
	}while (ans!=4);
	cout<<"TOTAL : "<<c1.total_1();
}

