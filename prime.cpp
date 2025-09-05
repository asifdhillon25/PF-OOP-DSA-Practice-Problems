#include<iostream>

using namespace std;

int main()
{
	int num,count;
	bool x=true;
	
	count=0,
	
	
	cin>>num;
	
	for(int i=2; i<=num/2; i++)
	{
	
	   int n=num%i;
	   
	   
		if(n==0){
			
			count++;
		}	

	
}




		
		
	if(count==0){
			cout<<num<<" is  a prime no";
		}
	else if(count==1){
		
		cout<<num<<" is not a prime no";
	}
			


}
