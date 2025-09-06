#include<iostream>

using namespace std;

int main()
{
	int num1,num2,count;
	
	
	cout<<"enter 2 numbers";
	cin>>num1;
	cin>>num2;
	
	
	
	int x,j;
	j=2;

	for(int i=num1; i<=num2; i++)
	{
		bool x=true;
		
		for(int j=2; j<=i/2; j++)
		{
			if(i%j==0)
			{
				x=false;
			}
			
			
		}
			if(x)
			{
				cout<<i<<endl;
			}
		
		
			
	
	}
}
