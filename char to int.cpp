#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;


int atoi(const char* p);
int ctoi()
{
		int x=0;
	do
	{
	
	char s[100];
	cin>>s;
	x=atoi(s);
	
	if(x==0)
	{
		cout<<"try entering only numbers\n";
	}
	else
	{
		cout<<"\n";
	}
}
while(x==0);

return x;
}
//int main()
//{
//	int d=function();
//	cout<<d;
//}
