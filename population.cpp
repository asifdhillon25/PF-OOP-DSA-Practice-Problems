#include<iostream>
using namespace std;

int main()
{
	
	 int pta;
	 int ptb;
	 //asking user to enter town populations
	 cout<<"NOTE: population of town B will be greater than A\n";
	 
	 cout<<"enter the population of town A\n";
	 cin>>pta;
	 cout<<"enter the population of town B \n";
	cin>>ptb;	 
	 
	 int i;
	 
	//this loop will brake when population of town A increase
	 for(i=0;;i++){
	 	
	 	
		pta =pta+(pta/100)*4;
		ptb =ptb+(ptb/100)*2;
		
		if(pta>ptb){
			
			break;
		}
		
		

	 }
	 
	 cout<<"after "<<i<<"years, population of town A will be greator than town B";

	
	
}
