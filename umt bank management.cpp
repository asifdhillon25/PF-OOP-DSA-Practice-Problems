#include<iostream>
#include<string>
using namespace std;

//global variable for counting accounts
int n=0;

//global arrays for account holder details
string name [10];
int deposit[10];
int accountpin[10];

//function prototypes
void create_account(int n);
void showaccount(int n,int ac);
void depositm(int n,int ac);
void withdraw(int n,int ac);
void showall(int n);
void modifyaccount(int n,int ac);
void intro();
void outro();


//main function

int main()
{
	
//	calling intro function

	char choice;
	intro();
	system("cls");
	
	
	do
	{
		
		
//		menu of atm
		
	    cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. New Account";
		cout<<"\n\n\t02. Account detail";
		cout<<"\n\n\t03. Amount deposit";
		cout<<"\n\n\t04. Amount withdraw";
		cout<<"\n\n\t05. Show all accounts";
		cout<<"\n\n\t06. Modify Account";
		cout<<"\n\n\t07. Exit\n";
		cout<<"\n\n\tSelect Your Option (1-7) \n";

	cin>>choice;
	system("cls");
	
//	switch for selecting different different options

	 switch(choice)
	 {
	 	case '1':
	 		{
	 			create_account(n);
	 			cout<<"Your account has been created!\n\a";
	 			n++;
	 			cin.ignore();
                cin.get();
                system("cls");
			 }
	 	break;

	 		case '2':
	 		{
	 			int ac;
	 			cout<<"enter your account pin\n";
	 			cin>>ac;
	 			showaccount(n,ac);
	 			cin.ignore();
                cin.get();
                system("cls");
			 }
	 	break;

	 		case '3':
	 		{
	 			int ac;
	 			cout<<"enter your account pin\n";
	 			cin>>ac;
	 			
	 			depositm(n,ac);
	 			
	 			cin.ignore();
                cin.get();
                system("cls");
			 }
	 	break;

	 	case '4':
	 		{
	 			int ac;
	 			cout<<"enter your account pin\n";
	 			cin>>ac;
	 			
	 			withdraw(n,ac);
	 			cin.ignore();
                cin.get();
                system("cls");
			 }
	 	break;

	 	case '5':
	 		{
	 			cout<<"Enter your Master key\n";
	 			int key;
	 			cin>>key;
	 			if(key==1337)
	 			{
	 				if(n>0)
	 				{
	 				showall(n);
	 				cin.ignore();
	 				cin.get();
	 				system("cls");
					 }
					 else if( n==0)
					 {
					 	cout<<"There is no account in this bank\n";
					 	cin.ignore();
					 	cin.get();
	 					system("cls");
					 }

				 }
				 else
				 {
				 	cout<<"you entered wrong master key\n";
				 	cin.ignore();
                    cin.get();
                    system("cls");
				 }

			 }
			 break;
			 
			 case '6':
			{
				int ac;
	 			cout<<"enter your account pin\n";
	 			cin>>ac;
				modifyaccount(n,ac);
				cin.ignore();
                cin.get();
                system("cls");
			}
			break;

		case '7':
		{
			outro();

			 }

		cin.ignore();
        cin.get();
        system("cls");

	 }


	}
	while(choice!='7');







}



    void create_account(int n)
    {
        cout<<"\nEnter your Name: (without space)"<<endl;
        cin>>name[n];
        cout<<"Enter your 4 digit account pin\n";
        cin>>accountpin[n];


        cout<<"You should have to deposit 500 rupees initially\n";
        int checkdeposit;
        ag:
        cin>>checkdeposit;
        if(checkdeposit<500)
        {
        	cout<<"Please enter amount greater than 500\n";
        	goto ag;
		}
		else if(checkdeposit>=500)
		{
			deposit[n]=checkdeposit;
		}
        
        


    }

    void showaccount(int n,int ac)
	{
		
		int counter=0;
		
//		loop for checking if account exist or not

			for (int i=0;i<n; i++)
			{
				if(accountpin[i]!=ac)
				{
					counter++;	
				}
			}
			if(counter==n)
			{
			cout<<"there is no account with this pin\n";
			}
			else
			{
				
				//			loop for showing account if exist

				for(int i=0;i<n;i++)
				{
					if(accountpin[i]==ac)
					{
						system("cls");
					cout<<"=================\n";
					cout<<" Account details\n";
					cout<<"=================\n";
				    cout<<"Name         "<<name[i]<<endl;
				    cout<<"Account pin   "<<accountpin[i]<<endl;
				    cout<<"Balance       "<<deposit[i]<<endl;
				    break;
					}
				}
		}
		

	
}

	void depositm(int n,int ac)
	{
			int counter=0;
			
			//		loop for checking if account exist or not
			for (int i=0;i<n;i++)
				{
				if(accountpin[i]!=ac)
				{
					counter++;	
					}
				}
			
			
			if(counter==n)
			{
			cout<<"there is no account with this pin\n";
				
			}
			else
			{
//			loop for showing account if exist				
				for (int i=0;i<n;i++)
				{
					if(accountpin[i]==ac)
					{
						int depo;
						cout<<"enter the money you want to deposit\n";
						cin>>depo;
	   					deposit[i]+=depo;
	   					cout<<"Your money has been deposited!\n";
					}
					
			}
		
	}
}


	void withdraw(int n,int ac)
	{
		 int counter=0;
//		loop for checking if account exist or not
		
			for (int i=0;i<n;i++)
				{
				if(accountpin[i]!=ac)
				{
					counter++;	
					}
				}
			
			
			if(counter==n)
			{
			cout<<"there is no account with this pin\n";
				
			}
			else
			{
//			loop for showing account if exist			
		for(int i=0;i<n;i++)
		{
			if(accountpin[i]==ac)
			{
				int depo;
				cout<<"enter the money you want to withdraw (account balance:"<<deposit[i]<<" rs)\n";
				cin>>depo;
				if(depo>deposit[i])
				{
					cout<<"Insufficient Balance\n";
				}
				else if(depo<=deposit[i])
				{
					deposit[i]-=depo;
					cout<<"Your money has been withdrawn!\n";
				}
	   			break;
			}	
		}

	
	}
}

	void showall(int n)
	{
		 cout<<"=============================================\n";
        cout<<"AccountHolder    Accountpin     Balance\n";
        cout<<"==============================================\n";

		for(int i=0;i<n;i++)
		{
			cout<<"  "<<name[i]<<"            "<<accountpin[i]<<"        "<<deposit[i]<<"Rs"<<endl;

		}

	}
	
	 void modifyaccount(int n,int ac)
	{
			int counter=0;
//		loop for checking if account exist or not
		
			for (int i=0;i<n;i++)
		{
				if(accountpin[i]!=ac)
				{
					counter++;
					
				}

			}
			
			if(counter==n)
			{
			cout<<"there is no account with this pin\n";
				
			}
			else
			{
//			loop for showing account if exist		
		for (int i=0;i<n;i++)
		{
				if(accountpin[i]==ac)
			{
		   		cout<<"Enter new details for your account\n";
		   		cout<<"\nEnter your new Name: (without space)"<<endl;
       			 cin>>name[i];
        		cout<<"Enter your new account pin\n ";
        		cin>>accountpin[i];	
        		cout<<"Your account has been modified\n";
        		break;
			}
		}

	}
}
//		outro function
		void intro()
		{
			cout<<"\n\n\n\t\t \t\t \t    UMT Bank";
			cout<<"\n\t\t\t\t\t     MANAGEMENT";
			cout<<"\n\t \t\t\t\t      SYSTEM\n";
			cout<<"\n\t\t \t \t\t      MADE BY";
			cout<<"\n  \t \t\t\t      Muhammad Asif Dhillon";
			cout<<"\n  \t\t\t \t  \t   Hamza Saeed";
			cout<<"\n  \t\t\t  \t\t Mahibah Zubair";
			cout<<"\n\n \t \t\t  \t\t  Section : C2";
			
			cout<<"\n\n\n\t Press Enter to continue........";
			cin.get();
		}
		//outro function
		void outro()
		{
		    cout<<"\n\n\tThanks for using our Bank\n";
		    cout<<"\n\tFor suggestions";
		    cout<<"\n\tEmail:    asifdhillon25@gmail.com";
		    cout<<"\n\tContact: 03166588770\n";

		}

