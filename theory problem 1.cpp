#include<iostream>
using namespace std;

int main()
{
		//start of program
		//initializing variables
	int tpd; 	//tpd=toll per day
	int pfd; 	//pfd=parking fee per day
	int ampg;   //average miles per gallon
	int mdpd;	//mdpd=total miles driven per day
	int cpgg;	//cpgg=cost per gallon of gasoline
	int cfpd;	//total cost of fuel per day
	int totalcost;
		//taking value from user
	cout<<"enter the value of cost per gallon of gasoline"<<endl;
	cin>>cpgg;
	
	cout<<"enter the value of parking fee per day"<<endl;
	cin>>pfd;
	
	cout<<"enter the value of total miles driven per day"<<endl;
	cin>>mdpd;

	cout<<"enter the value of average miles per gallon"<<endl;
	cin>>ampg;

	cout<<"enter the price you pay on tolls per day"<<endl;
	cin>>tpd;
	
	//initializing formulas
	
	cfpd=float(mdpd/ampg)*cpgg;//cfpd=cost of fuel per day
	
	totalcost=tpd+pfd+cfpd;
	//total cost of driving
	cout<<"your total cost of driving per day is ="<<totalcost;
	
			//end of code


}
