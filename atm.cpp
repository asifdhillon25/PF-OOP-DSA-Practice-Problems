#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include""
using namespace std;

int main()
{
	
	
	
		cout<<"WELCOME in DHILLON BANK"
		<<"\n       ATM\n\n";
		
		int pin;
	label1:
	cout<<"enter your 4 digit pin\n";
	cin>>pin;
	
	if(pin==1004)
	{
	float amount;
	float balance;
	
	
	balance=5000;
	float tax;
	
	cout<<"Welcome Saad\n";
	cout<<"your balance is 5000RS\n"; 
	label2:
	cout<<"enter the amount you want\n";
	cin>>amount;
	
		float atax;
		float mtax;
	
	atax=(amount/100);
	mtax=(atax*5);
	
	if(amount>balance)
	{
		cout<<"you have insufficient amount\n";
		cout<<"enter amount less than account balance";
		goto label2;
	}
	if(amount<=300)
	{
		cout<<amount<<"has been transfer to your account";
		
		cout<<"if you want to use the atm again\n"
			<<"prees 1 for yes"
			<<"press 0 for no";
			bool yes;
			if(yes)
			{
				goto label2;
			}
		
	}
	
	if(amount>300 && amount<=500)
	{
		cout<<"you will get your money with 4% tax\n"
			<<"if agree type 1"
			<<"\nif not type  0\n";
			bool x;
			cin>>x;
		
						
			if(x)
			{
				cout<<(amount-(amount/100)*4)<<"Rs has been transfered to your account";
			
			
			cout<<"if you want to use the atm again\n"
			<<"prees 1 for yes"
			<<"press 0 for no";
			bool yes;
			cin>>yes;
			if(yes)
			{
				goto label2;
			}
			}
			else if(x=='n')
			{
				cout<<"\nthanks for using the atm";
			}
			else
				cout<<"you have typed wrong alphabet ";
			
		
	}
	
		if(amount>500 && amount<=balance)
		{
			cout<<"we are having shortage of funds"
				<<" but you can take money more than 500 "
				<<"with 5%per 100RS tax \n";
		
			cout<<"if agree type y"
			<<"\nif not type  n\n";
			char x;
			cin>>x;
	
						
			if(x=='y')
			{
				cout<<(amount-mtax)<<"Rs has been transfered to your account";
				
				
			}
			else if(x=='n')
			{
				cout<<"\nOk so plz enter amount less than 500";
				
			}
			else
				{
				cout<<"you have typed wrong alphabet. ";
				
				cout<<"\n\nThanks for using the atm.";
				
			cout<<"if you want to use the atm again\n"
			<<"prees 1 for yes"
			<<"press 0 for no";
			bool yes;
			if(yes)
			{
				goto label2;
			}
		}
				
		}
	
	
		
	}
	if(pin==2023)
	{
		
		float amount;
	float balance;
	
	
	balance=20000000;
	float tax;
	
	cout<<"welcome Saeed\n";
				cout<<"your balance is RS 20000000\n"; 
	cout<<"enter the amount you want\n";
	cin>>amount;
	
		float atax;
		float mtax;
	
	atax=(amount/100);
	mtax=(atax*5);
			if(amount>balance)
	{
		cout<<"you have insufficient amount\n";
	}
	if(amount<=300)
	{
		cout<<amount<<"has been transfer to your account";
	}
	
	if(amount>300 && amount<=500)
	{
		cout<<"you will get your money with 4% tax\n"
			<<"if agree type y"
			<<"\nif not type  n\n";
			char x;
			cin>>x;
						
			if(x=='y')
			{
				cout<<(amount-(amount/100)*4)<<"Rs has been transfered to your account";
				
			}
			else if(x=='n')
			{
				cout<<"\nthanks for using the atm";
			}
			else
				cout<<"you have typed wrong alphabet ";
			
		
	}
	
		if(amount>500 && amount<=balance)
		{
			cout<<"we are having shortage of funds"
				<<" but you can take money more than 500 "
				<<"with 5%per 100RS tax \n";
		
			cout<<"if agree type y"
			<<"\nif not type  n\n";
			char x;
			cin>>x;
						
			if(x=='y')
			{
				cout<<(amount-mtax)<<"Rs has been transfered to your account";
				
				
			}
			else if(x=='n')
			{
				cout<<"\nOk so plz enter amount less than 500";
				
			}
			else
				cout<<"you have typed wrong alphabet. ";
				
				cout<<"\n\nThanks for using the atm.";
				
		}
	
	
		
	}
		
	
	
	else if(pin!=1004 && pin!=2023)
	{
			cout<<"you have entered a wrong pin\nTRY AGAIN\n";
				goto label1;
	}
	
	
	
	
	

	
	
}
