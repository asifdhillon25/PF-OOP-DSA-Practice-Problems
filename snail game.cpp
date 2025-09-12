#include<iostream>
#include<ctime>
#include<time.h>
 using namespace std;
 int money;
 bool x=true;
 
 
 int userres();
 
 int race(int, int);
 
 int main(){
 	
 	
 	int pl;
 	
 	
 	
 	cout<<"welcome to dog racing game"<<endl;
 	cout<<"here you can place bets and win exciting amounts"<<endl;
 	
 	cout<<"how many players are playing"<<endl;
 	cin>>pl;
 	string names[pl];
 	cout<<"enter your names"<<endl;
	for(int i=0;i<pl; i++){
		
		cin>>names[i];
		
	} 
	
	int money[pl];
	for(int i=0;i<pl; i++){
			
		cout<<names[i]<<"enter your bet money"<<endl;
		cin>>money[i];
			
			
	}
	
	
	
	 	
 	cout<<"there are four dogs racing\n"
 		<<"(1  maju\n"
 		<<"(2 kala\n"
 		<<"(3 jugnu\n"
 		<<"(4 shablo\n\n";
 		
 		cout<<"on which dog you wanna bet\n";
 		
 		int choice[pl];
 		for(int i=0;i<pl; i++)
 		{
 			cout<<names[i]<<"enter your choice"<<endl;
 			cin>>choice[i];
		 }
	
	
		
 	
 	
 	
 	
 	
 	int n;
 	//called a function
 	
 	
 	
 	userres();
 	
 	switch(n){
 		
 		case 1:
 			{
 				cout<<"maju is a great choice";
			 }
			 break;
 		case 2:
 			{
 				cout<<"kala is a great choice";
			 }
			 break;
			 			 
 		case 3:
 			{
 				cout<<"jugnu is a great choice";
			 }
			 break;
 		case 4:
 			{
 				cout<<"shablu is a great choice";
			 }
			 break;			  		
	 }
 	
	 cout<<"\nplace your bet\n";
	 
	 int bet;
	 
	 cin>>bet;
	 
	 cout<<n;
	 
	 race(bet,n);
	 
	 if(x)
	 {
	 	cout<<"you total money is "<<(bet)+money;
	 }
	 else if(!x){
	 	cout<<"your money is "<<-bet+money;
	 }
	 
	 	
 	
	 
	 	
	 
 	
 
 	
 }
 

 
 int race(int bet,int user){
 	
 	int winner= 3;
 	
 	if (user==winner){
 		cout<<"cograts\nyou won";
 		cout<<"you get "<<bet*2<<" Rs\n";
 		return ::x=true;
 		
	 }
	 else if(user!=winner){
	 	
	 	cout<<"you lose\nbetter luck next time\n";
	 	cout<<"you lost "<<bet<<" Rs\n";
	 	return ::x=false;
	 	
	 }
 }
 
 
 
 
