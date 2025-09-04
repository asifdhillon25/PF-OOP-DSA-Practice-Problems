#include<iostream>

using namespace std;
int main()
{
	
	int i,j,k,l,c,num;
    cout<<"enter num\n";
	cin>>num;
	
	c=0;
	j=0;
	l=1;
	
	
	for(i=1; i<=num; i++)
	{
		
		cout<<j<<" "<<endl;	
		k=j+l+c;
		j=l;
		l=c;
		c=k;

	}
}
