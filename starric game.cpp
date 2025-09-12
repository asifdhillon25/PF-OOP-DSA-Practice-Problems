#include<iostream>

using namespace std;

int main()
{ 
	cout<<"This is a shape making game with this starric *  symbols"<<endl;
	cout<<"here are some models of some shapes"<<endl;
	
	cout<<"\n\n(a)\n"
		<<"*\n"
		<<"**\n"
		<<"***\n";
		
		
		cout<<"\n(b)\n"
		<<"***\n"
		<<"**\n"
		<<"*\n";
		
		cout<<"\n(c)\n"
		<<"  *\n"
		<<" ***\n"
		<<"*****\n"
		<<" ***\n"
		<<"  *\n";
		
		
		
			cout<<"\n(d)\n"
		<<"  *\n"
		<<" * *\n"
		<<"* * *\n"
		<<" * *\n"
		<<"  *\n";
		
	
	
	cout<<"\nevery shape is having a alphabet\n";
	
		labelasif:
		cout<<"enter a shape alphabet to make that shape\n";
		char x;
		cin>>x;
		
		switch(x)
		{
			case'a':
			{	int num;
			cout<<"enter number of rows\n";
			cin>>num;
			
				for(int i=1; i<=num; i++)
				{
				for(int j=1;j<=i; j++)
				{
				cout<<"*";
				}
						cout<<endl;
				}
				
			
			}
				break;
			
			case 'b':
				{
					
						int num;
				cout<<"enter number of rows\n";

					cin>>num;
					
					
					for(int i=1;i<=num; i++)
					{
						for(int j=num; j>=i; --j)
						{
							cout<<"*";
						}
						cout<<endl;
					}
				}
			
				break;			
			case 'c':
				{
							int num,row;
			cout<<"enter number of rows\n";
					cin>>row;
					num=row;
					
					int x,y,z;
					x=num-1;
					z=(x*2)+1;
					y=z-2;
					
					
					
					for(int i=1;i<=num; i++)//for upper pyramid of diomand
					{
						for(int j=num; j>=i; --j)
						{
							cout<<" ";
						}
						for(int k=1; k<=2*i-1; k++)
						{
							cout<<"*";
						}
						cout<<endl;
					}
					
					for(int i=1;i<=num; i++)//for lower pyramid of diomand
					{
						for(int j=1; j<=i+1; j++)
						{
							cout<<" ";
						}
						
						
						for(int k=y; k>=1; k--)
						{
							
							cout<<"*";
							
						}
						cout<<endl;
						y=y-2;
						}
	

				}
				
			break;
			case 'd':
				{
							int num;
			cout<<"enter number of rows\n";
					cin>>num;
					
					
					for(int i=1;i<=num; i++)//for upper pyramid of diomand
					{
						for(int j=num; j>=i; --j)
						{
							cout<<" ";
						}
						for(int k=1; k<=i; k++)
						{
							cout<<" *";
						}
						cout<<endl;
					}
					
					for(int i=1;i<=num; i++)//for lower pyramid of diomand
					{
						for(int j=1; j<=i+1; j++)
						{
							cout<<" ";
						}
						for(int k=num-1; k>=i; k--)
						{
							cout<<" *";
						}
						cout<<endl;
					}
				}
				break;
				default:
					{
						cout<<"\ninvalid input\n\n";
					}
				
		
			
}
		bool a;
		cout<<"if you want to play the game again\n"
			<<"press 1\n"
			<<"press 0\n";
		cin>>a;
		
		if(a) 
		{
			goto labelasif;
		}
		else
		{
			cout<<"Thanks for playing the game";
		}
}
