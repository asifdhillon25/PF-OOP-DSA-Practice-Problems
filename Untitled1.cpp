#include<iostream>
using namespace std;



int fibinacci(int a);
int main()
{

int res;

res=fibinacci(4);


cout<<res;



}

int fibinacci(int a)
{
	if (a==1 || a==0)
	{
		
		return 1;
		
	}
	
	else
	{
		return fibinacci(a-1)+fibinacci(a-2);
		
	}
	
	
}

