#include<iostream>
using namespace std;

int main()
{
		//start of program
		//initializing variables
	float tpd; 	//tpd=toll per day
	float pfd; 	//pfd=parking fee per day
	float ampg;   //average miles per gallon
	float mdpd;	//mdpd=total miles driven per day
	float cpgg;	//cpgg=cost per gallon of gasoline
	float cfpd;	//total cost of fuel per day
	float totalcost;
		//taking value from user
	cout<<"enter the price of 1 litre of petrol"<<endl;
	cin>>cpgg;
	
	cout<<"enter the value of parking fee per day"<<endl;
	cin>>pfd;
	
	cout<<"enter the value of total kilometres driven per day"<<endl;
	cin>>mdpd;

	cout<<"enter the average of your vehicle"<<endl;
	cin>>ampg;

	cout<<"enter the value of no of tolls per day"<<endl;
	cin>>tpd;
	
	//initializing formulas
	
	cfpd=(mdpd/ampg)*cpgg;//cfpd=cost of fuel per day
	
	totalcost=tpd+pfd+cfpd;
	//total cost of driving
	cout<<"your total cost of driving per day is ="<<totalcost;
	
			//end of code


}
