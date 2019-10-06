#include<iostream>
using namespace std ;
class vehicle{
private :
	string type_of_car ;
	string make ;
	string model ;
	string color ;
	int year ;
	float miles ;
public :
	vehicle (string atype , string amake , string amodel , string acolor , int ayear , float amiles){
		type_of_car = atype ;
		make = amake;
		model = amodel ;
		color = acolor;
		year = ayear ;
		miles = amiles;	
	}
	string get_type(){
		return type_of_car ;
	}
	string get_make(){
		return make ;
	}
	string get_model(){
		return model ;
	}
	string get_acolor(){
		return color ;
	}
	int get_year(){
		return year ;
	}
	int get_miles(){
		return miles ;
	}
};
class Gas : virtual public vehicle{
private :
	int fueltanksize ;
public :
	Gas(int fuel,string atype , string amake , string amodel , string acolor , int ayear , float amiles): vehicle(atype , amake , amodel , acolor , ayear , amiles){
		fueltanksize = fuel ;
	}
	int get_fuel(){
		return fueltanksize ;
	}
};
class electric : virtual public vehicle{
private :
	float energystorage ;
public :
	electric (float energy,string atype , string amake , string amodel , string acolor , int ayear , float amiles):vehicle ( atype , amake ,amodel ,acolor ,ayear , amiles){
		energystorage  = energy ;
	}
	float get_energy(){
		return energystorage ;
	}
};
class high_perfomance : public Gas{
private :
	float hp ;
	float topspeed ;
public :
	high_perfomance(float ahp ,float atopspeed,string atype , string amake , string amodel , string acolor , int ayear , float amiles,int fuel):vehicle ( atype , amake ,amodel ,acolor ,ayear , amiles),Gas(fuel,atype , amake ,amodel , acolor ,ayear , amiles){
		hp = ahp ;
		topspeed = atopspeed ;
	}
};
class heavy_vehicle: public Gas ,public electric{
private :
	float max_weight ; 
	int no_of_wheel ;
	float length ;
public :
	heavy_vehicle(float amax  , int ano , float alen,string atype , string amake , string amodel , string acolor , int ayear , float amiles,float energy,int fuel):Gas(fuel,atype , amake ,amodel , acolor ,ayear , amiles),electric (energy,atype ,amake ,  amodel , acolor ,ayear , amiles),vehicle ( atype , amake ,amodel ,acolor ,ayear , amiles){
		max_weight = amax ;
		no_of_wheel = ano ;
		length = alen ;
	}
	int get_wheels(){
		return no_of_wheel;
	}
	float get_weight(){
		return max_weight ;
	}
	float get_length(){
		return length ;
	}
};
class sport_car : public high_perfomance {
private :
	string gearbox ;
	string drive_system ;
public :
	sport_car(string agear ,string adrive,float ahp ,float atopspeed,string atype , string amake , string amodel , string acolor , int ayear , float amiles,int fuel):high_perfomance(ahp ,atopspeed,atype , amake ,amodel ,acolor , ayear ,amiles,fuel),vehicle ( atype , amake ,amodel ,acolor ,ayear , amiles){
		gearbox = agear ;
		drive_system = adrive ;
	}
};
class construction_Truck  :public heavy_vehicle{
private :
	string cargo ;
public :
	construction_Truck(string acargo ,string atype , string amake , string amodel , string acolor , int ayear , float amiles,float energy,int fuel,float amax  , int ano , float alen):heavy_vehicle(amax  ,ano ,alen,atype ,amake ,amodel ,acolor , ayear ,amiles,energy,fuel),vehicle ( atype , amake ,amodel ,acolor ,ayear , amiles){
		cargo =  acargo ;
	}
};
class Bus : public heavy_vehicle{
private :
	int noofseats ;
public :
	Bus(int aano,float amax  , int ano, float alen,string atype , string amake , string amodel , string acolor , int ayear , float amiles,float energy,int fuel):heavy_vehicle(amax  ,ano ,  alen,atype , amake ,amodel , acolor , ayear ,amiles,energy, fuel),vehicle (atype , amake ,amodel ,acolor ,ayear , amiles){
		noofseats = aano ;
	}
	void Display(){
		cout<<"TYPE\tMAKE\tMODEL\tCOLOR\n\n";
		cout<<get_type()<<"\t"<<get_make()<<"\t"<<get_model()<<"\t"<<get_acolor() ;
		cout<<"\n\nWHEELS\tYEAR\tMILES DRIVEN\tFUEL TANK SIZE\n";
		cout<<"\n"<<get_wheels()<<"\t"<<get_year()<<"\t"<<get_miles()<<" KM\t\t"<<get_fuel();
		cout<<"\n\nENERGY STORAGE\tMAX-WEIGHT\tLENGTH\tNO OF SEATS\n" ;
		cout<<"\n"<<get_energy()<<"J\t\t"<<get_weight()<<" TON\t\t"<<get_length()<<" M\t"<<noofseats<<"\n";
	}
};
int main(){
	Bus obj(10,2,4,11,"ABCD","XYZ","IJK","RED",2001,12.8,34,15);
	obj.Display();
	return 0 ;
}
