#include<iostream>

using namespace std;

int main()
{
	int rows,col;
	
	
	cin>>rows>>col;
	int a[rows][col];
	cout<<"enter array value\n";
	for(int i=0;i<rows; i++)
	{
		for(int j=0; j<col; j++)
		{
			
			cin>>a[i][j];
			
		}
	}
	
		for(int i=0;i<rows; i++)
	{
			cout<<"row"<<i+1<<"\t";
		for(int j=0; j<col; j++)
		{
			
			cout<<a[i][j]<<"\t";
			
		}
		cout<<endl;
	}
	
}
