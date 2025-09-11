#include<iostream>

using namespace std;
int main()
{
	
	int i,rev,r,k,num;
	
	cout<<"enter a 1 to 9 digit number\n";
	cin>>num;
	
	//this loop will reverse the number
	do
	{
		k=num%10;
		
		rev=(rev*10)+k;
		
		num=num/10;
	}
	while(num!=0);
	
	
	do//this will again reverse number to get exact temp
	{
		k=rev%10;
		
		r=(r*10)+k;
		
		switch(k) //switch case for one to ten in words
		{
			case 1:
				{
					cout<<"one ";
				}
				break;
				
				case 2:
				{
					cout<<"two ";
				}
				break;
				
				case 3:
				{
					cout<<"three ";
				}
				break;
				
			
				
				case 4:
				{
					cout<<"four ";
				}
				break;
				
							case 5:
				{
					cout<<"five ";
				}
				break;
				
							case 6:
				{
					cout<<"six ";
				}
				break;
				
							case 7:
				{
					cout<<"seven ";
				}
				break;
				
							case 8:
				{
					cout<<"eight ";
				}
				break;
				
							case 9:
				{
					cout<<"nine ";
				}
				break;
				
				case 0:
				{
					cout<<"zero ";
				}
				break;	
				
				default:
					break;
			
			
		}
		rev=rev/10;
	}
	while(rev!=0);



}
