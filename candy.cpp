#include<iostream>
using namespace std;
int main()
{
	float candy,gch,gsonc,gdrc;
	
	cout<<"in this family ther are 5 childs\n"
		<<"3 daughters and 2 sons.Each daughter\n get double amount of candies than boys\n";
	label1:
	cout<<"enter the no of candies\n";
	cin>>candy;
	
	
	
	gch=5;
	gsonc=2;
	gdrc=3;
	
	float equalcandy,gdr,gson;
	equalcandy= candy/7;
	
	gdrc=(equalcandy*6/3);
	gsonc=equalcandy;
	
	cout<<"each grand daughter will get "<<gdrc<<" candies\n";
	cout<<"each grand son will get "<<gsonc<<" candies\n";

	bool x;
	cout<<"press 1 for contiue\n";
	cout<<"press 0 for exit\n";
	cin>>x;
	
	if(x)
	{
		goto label1;
	}
	
	
	
	

	


	

		
}
