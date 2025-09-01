#include<iostream>
#include<catm.h>
using namespace std;




int main()
{
	
	Catm saad("saad",2000,1003);
	
	Catm Saeed("Saeed",3000,2004);
	
	Catm hamza("hamza",5000,1221);
	
	Catm usama("usama",1000000,7172);
	
	
	Catm waqar("waqar",23450,1234);	
	
	cout<<"*********************Welcome to DHILLON ATM*********************\n";
	
	
	

	cout<<"please enter your four digit pin\n";
	

	
	
	
	int p;
	wpin:
	cin>>p;
	asif:
	if( p==saad.cpin())
	{
		saad.intro();
			
		saad.choice();
		
		
	}
	else if(p==Saeed.cpin())
	{
		Saeed.intro();
		
		Saeed.choice();
		
	}
	else if(p==hamza.cpin())
	{
	hamza.intro();
		
	hamza.choice();
	}
	else if(p==usama.cpin())
	{
				usama.intro();	
	usama.choice();
		
	}
	else if(p==waqar.cpin())
	{
						waqar.intro();	
		
	waqar.choice();
	}
	else
	{
		cout<<"you enter a wrong pin\nTry again\n";
		goto wpin;
		
	}
	
	
	cout<<"press 1 for menu\nprees 2 for exit";
	
		bool f;
		
		cin>>f;
		
		if(f)
		{
			goto asif;
		}
		else if(!f)
		{
			cout<<"thanks for using the atm";
		}
	
	
	
	

	}
