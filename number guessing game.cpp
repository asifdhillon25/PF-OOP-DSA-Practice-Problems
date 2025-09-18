#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	
	int num=rand() % 5+5;
	int guess=0;
	int guessnum;
	
	
	
	for(guessnum=0; guess!=num; guessnum++)
	{
		cin>>guess;
		if(guess<num)
		cout<<"you picked a low value\n";
		
		else if(guess>num)
		cout<<"you picked a higher value\n";
		
	}
	cout<<"you guessed it right";
	
	cout<<"it takes "<<guessnum<<" attempts";
	
}
