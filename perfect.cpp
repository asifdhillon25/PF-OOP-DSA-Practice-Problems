#include<iostream>

using namespace std;
int main()
{
	
	int n,num,k;
	cin>>num;
	n=num;
	int rev=0;
	
	while(num!=0)
	{
		k=num%10;
		rev=(rev*10)+k;
		
	num=num/10;
	}
	cout<<rev;
	
	if(rev==n)
	{
		cout<<"perfect"<<endl;
	}
	else if(rev!=n)
			cout<<"not perfect"<<endl;

		
	
}
