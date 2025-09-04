#include<iostream>

using namespace std;
int main()
{
	
	int i,j,k,l,c,num;
	cin>>num;
	
	
	j=0;
	l=1;
	
	
	for(i=1; i<=num; i++)
	{
		
		cout<<j<<" "<<endl;	
		k=j+l;
		j=l;
		l=k;
		

	}
}
