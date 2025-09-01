#include<iostream>
 using namespace std;
 
 int main()
 
 {
 	
 	int pin;
 	cout<<"enter your four digit pin"<<endl;
 	cin>>pin;
 	
 	switch(pin)
 	{
 		case 2023:
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
					 }
			 }
			 break;
		case 1004:
			{
				float amount;
	float balance;
	
	
	balance=5000;
	float tax;
	
	cout<<"Welcome Saad\n";
	cout<<"your balance is 5000RS\n"; 
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
	break;
		case 2002:
			{
							float amount;
	float balance;
	
	
	balance=5000;
	float tax;
	
	cout<<"Welcome asif\n";
	cout<<"your balance is 25000RS\n"; 
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
	
		break;
	default:
		{
			cout<<"you have entered a wrong pin\nTRY AGAIN";
		}
			}
}

