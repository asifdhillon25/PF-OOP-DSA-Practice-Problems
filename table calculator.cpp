#include<iostream>
 using namespace std;
 
 int main()
 {
 	float num1;
 	float num2;
 	
 	
 	
 	cout<<"from where to where you want a table(eg;2 to 4)"<<endl;
 	cin>>num1;
 	cin>>num2;
 	
 	for (int c=num1; c<num2+1;  c++ )
 	{
 		cout<<c<<"| ";
 		
 		for(int i= 1; i<11; i++)
 		{
 			cout<<i*c<<"\t";	
		 }
		 cout<<"\n";
 		
 		
		 }
 		
 	
 
 }
