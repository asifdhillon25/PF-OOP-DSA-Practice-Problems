#include<iostream>
#include <stdio.h>
using namespace std;



class Flight{
	
	int Flight_num;
	float Distance;
	float Fuel_req;
	string Destination;
	string FlightName;
	
	
	float Calfuel(int distance)
	{
		if(distance<=1000)
		{
			return 500;
		}
		else if(distance>1000 && distance<=1800)
		{
			return 900;
		}
		else if(distance>1800 && distance<=2200)
		{
			return 1100 ; 
		}
		else if(distance>2200)
		{
			return 1300;
		}
	}
	
	public:
		
		
		Flight(int flightnum,float distance,string fname,string destination)
		{
			Destination=destination;
			Distance=distance;
			Flight_num=flightnum;
			FlightName=fname;
			Fuel_req=Calfuel(distance);
		}
		
		void ShowData()
		{
			
			cout<<"   ***Flight Information***\n\n\n";

			cout<<"Flight Name: "<<FlightName<<endl;
			cout<<"Flight Number: "<<Flight_num<<endl;
			cout<<"Flight Distance: "<<Distance<<endl;
			cout<<"Flight Destination: "<<Destination<<endl;
			cout<<"Fuel required: "<<Fuel_req<<endl;
		}
};


class heapoint{
	
	
	public:
	
	Flight* onheap;
	
	Flight* getvalue(){
		
		return onheap;
	}
	
	
	void setter(int flightnum,float distance,string fname,string destination){
		
		
		onheap=new Flight(flightnum,distance,fname,destination);
	}
	
	~heapoint(){
		
		delete onheap;
		onheap=0;
	}
};

int main(){
	
		heapoint a;
		
		a.setter(23,3000,"asif","pakistan");
		
		Flight* f1;
		f1=a.getvalue();
		
		f1->ShowData();
		
	
		
		
		
		
	
	
}
