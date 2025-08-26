#include<iostream>

using namespace std;

void menu();
	
int account(int code);	
int balance(int code);
int withdraw(int a);
int deposit(int b);


bool x=true;
double saadb=12340;
double saeedb=25460;


int main(){
	int pin;
	
	cout<<"*********************Welcome to DHILLON ATM*********************\n";
	
	labela:
	cout<<"enter your four digit pin\n";
	cin>>pin;
	
	
	
	if(x){
		account(pin);			
	}
	else if(x=false) goto labela;
	
	
	int numb,n;

	do
	{
		
			cout<<"\n\n\n\n\n"; menu();
		
		cout<<"enter no of your choice\n";
		cin>>numb;
		
		n=numb;
		
		switch(n){
			
			case 1:
				{
					balance(pin);
					break;
				}
			case 2:
				{
				withdraw(pin);		
				}
			case 3:
				{
					deposit(pin);
				}
			
		}
		}	
		while(n!=5);			
	
}



void menu(){
	cout<<"*********************Menu of DHILLON ATM*********************\n"
	<<"\n1) Balance Check\n"
	<<"2) cash withdraw\n"
	<<"3) Cash depposit\n"
	<<"4) Transfer funds\n"
	<<"5) Exit\n"
	<<"*******************************************************************\n";
}


int account(int code){
	
	switch(code){
		
		case 1003:cout<<"Welcome Saad\n";break;		
		case 2023:cout<<"Welcome Saeed\n";break;	
		
		default:{
			
			cout<<"you have entered a wrong pin\n";
			
			::x=false;
			 break;
			
			
		}
}
}

int balance(int code){
	
	switch(code){
		
		case 1003: {
			
			cout<<"your balnce is "<<saadb<<endl;
			return saadb;
			break;
		}
		break;
		
				
		case 2023:{
			
			cout<<"your balnce is "<<saeedb<<endl;
			
			return saeedb;
		} break;
			
}

}

int withdraw(int a)
{
		cout<<"enter the amount you want \n";
					double amount;
					cin>>amount;
					
					if(a==1003)
					{
						
						if(amount>saadb){
							cout<<"you have insufficient balance\n";
						}
						else if(amount<=saadb){
							
						saadb-=amount;
						cout<<amount<<" Rs has been with drawn\n";	
						}
						
					}
					else if(a==2023){
						
							if(amount>saeedb){
							cout<<"you have insufficient balance\n";
						}
						else if(amount<=saeedb){
							
						saeedb-=amount;
						cout<<amount<<" Rs has been with drawn\n";
						saeedb-=amount;	
						}
						
						
					}
					
					
					
					
	
}

int deposit(int b)
{
	if(b==1003)
	{
		cout<<"enter the amount you wanna deposit\n";
		double amount;
		cin>>amount;
		saadb+=amount;
		cout<<amount<<" has been deposited in your account\n";		
	}
	else if(b==2023)
	{
		cout<<"enter the amount you wanna deposit\n";
		double amount;
		cin>>amount;
		saeedb+=amount;
		cout<<amount<<" has been deposited in your account\n";		
	}
	


	
	
}




