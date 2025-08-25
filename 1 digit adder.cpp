#include<iostream>

using namespace std;
int main()
{
	int num,i,rev,l=0,m,count;
	
	rev=0;
	int k =1;
	
	cout<<"enter a number\n";
	cin>>num; 
	
	m=num;
	do
	{
		m=m/10;
		count++;
		
	}
	while(m!=0);
	
	cout<<count<<endl;
	
	
	
	do
	{
		i=num%10;
		i++;
		rev=(rev*10)+i;
		num=num/10;
		k++;	
	}
	while(k<=count);
	
	int x=rev;
	int j,h;
	h=1;
	
	do
	{
		j=x%10;
		
		l=(l*10)+j;
		
		x=x/10;
		h++;
	}
	while(h<=count);
	
	
	cout<<"if we add 1 to each digit of this number the output is "<<endl;
	cout<<l;
	
	
	
	
}
