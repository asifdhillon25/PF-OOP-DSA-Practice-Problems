#include<iostream>
 using namespace std;
 
 int main()
 {
 	double num;
 	labelasif:
 	cout<<"enter a number to calculate its table\n";
 	cin>>num;
 	
 	
 	for (int i=1;  i<11; ++i )
 	{
 		cout<<num<<" x "<<i<<"= "<<num*i<<"\n";
 		
 		
		 }
		 
	bool x;
	
	cout<<"wanna calculate the table again"<<endl;
	cout<<"press 1"<<endl;
	cout<<"if not press 0\n";
	
	cin>>x;
	
	if(x)
	{
		goto labelasif;
	}
 		
 	
 
 }
