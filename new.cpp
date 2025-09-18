#include<iostream>
#include<ctime>
#include<time.h>
#include<cstdlib>
 using namespace std;

 int main(){

 	int pl;

 	cout<<"******welcome to dog racing game******\n"<<endl;
 	cout<<"Here you can place bets and win exciting amounts\n"<<endl;

 	cout<<"How many players are playing"<<endl;
 	cin>>pl;
 	string names[pl];
 	cout<<"enter your names"<<endl;
	for(int i=0;i<pl; i++){

		cin>>names[i];

	}
	asif:

			 //random number
		srand(time(0));
 		int random=(rand()%4+1);

	int money[pl];
	for(int i=0;i<pl; i++){

		cout<<names[i]<<" enter your bet money"<<endl;
		cin>>money[i];


	}




 	cout<<"there are four dogs racing\n"
 		<<"(1  maju\n"
 		<<"(2 kala\n"
 		<<"(3 jugnu\n"
 		<<"(4 shablo\n\n";

 		string dogs[]={"maju","kala","jugnu","shablo"};



 		cout<<"on which dog you wanna bet\n";

 		int choice[pl];
 		for(int i=0;i<pl; i++)
 		{
 			cout<<names[i]<<" enter your choice"<<endl;
 			cin>>choice[i];
		 }





 		cout<<"***************RESULTS***************\n";
 		cout<<dogs[random]<<" won the race\n"<<endl;



 		int i=0;


 	while(i<pl){


 	 			if(choice[i]==random)
 	 			{
					 cout<<names[i]<<" congrats you won "<<money[i]*2<<" Rs\n"<<endl;
				}
				else if(choice[i]!=random)
				{
					cout<<names[i]<<" your dog lose"<<endl;
					cout<<"you lose "<<money[i]<<endl<<endl;
				}
				   i++;
 	 	 }





 		cout<<"if you want to play again\npress 1\nif you want to exit\npress 0\n";
 		bool x;
 		cin>>x;
 		if(x)
 		{
 			goto asif;

		 }
		 else
		 {
		 	cout<<"*****************Thanks for playing\n*****************";
		 }
			  }





