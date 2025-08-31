#include<iostream>
#include<ctime>
#include<time.h>
#include<cstdlib>
 using namespace std;

 int main(){

 	int pl;

 	cout<<"******welcome to rabbit racing game******\n"<<endl;
 	cout<<"Here you can place bets and win exciting amounts\n"<<endl;

	
	
	
 	cout<<"How many players are playing"<<endl;
 	cin>>pl;
 	string names[pl];
 	cout<<"enter your names"<<endl;
	for(int i=0;i<pl; i++){

		cin>>names[i];

	}
	system("cls");
	asif:

			 //random number
		srand(time(0));
 		int random=(rand()%4+1);

	int money[pl];
	for(int i=0;i<pl; i++){

		cout<<names[i]<<" enter your bet money"<<endl;
		cin>>money[i];


	}
	



	system("cls");
	
 	cout<<"there are four rabbits racing\n"
 		<<"****(1 maju\n"
 		<<"****(2 kala\n"
 		<<"****(3 jugnu\n"
 		<<"****(4 shablo\n\n";

 		string rabbits[]={"sdfdf","maju","kala","jugnu","shablo"};



 		cout<<"on which rabbit you wanna bet\n";

 		int choice[pl];
 		for(int i=0;i<pl; i++)
 		{
 			cout<<names[i]<<" enter your choice"<<endl;
 			cin>>choice[i];
		 }




	system("cls");

 		cout<<"***************RESULTS***************\n";
 			cout<<"\n\n\n";
 		cout<<"******"<<"no "<<random<<" "<<rabbits[random]<<" won the race "<<"******"<<endl;
 			cout<<"\n\n\n";
 		
 		string rank[]={"first","fourth","second","third","fourth"};
 		
 		
 		
 	
 		
 		
 		
		for (int i=1;i<=4; i++)
		{
			
			
			
			if(i==random)
			{
				cout<<rabbits[random]<<" has got "<<rank[0]<<" positon\n";	
			}
			else if(i!=random)
			{
				cout<<rabbits[i]<<" has got "<<rank[i]<<" positon\n";
				
			}
		
		}
		
 		
 		cout<<"\n\n\n";
 		



 		int i=0;

    for(int i=0;i<pl; i++)
 	{
 	 			if(choice[i]==random)
 	 			{
					 cout<<"******"<<names[i]<<" congrats you won "<<money[i]*2<<" Rs "<<"******\n\n\n"<<endl;
				}
				else if(choice[i]!=random)
				{
					cout<<names[i]<<" your rabbit lose"<<endl;
					cout<<"you lose "<<money[i]<<endl<<endl;
				}

 	 	 }





 		cout<<"if you want to play again\npress 1\nif you want to exit\npress 0\n";
 		bool x;
 		cin>>x;
 		if(x)
 		{
 				system("cls");

 			goto asif;

		 }
		 else
		 {
		 	cout<<"*****************Thanks for playing*****************\n";
		 }
			  }






