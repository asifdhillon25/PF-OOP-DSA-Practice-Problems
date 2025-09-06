#include<iostream>
 using namespace std;
 
 int main()
 {
 	
 	
 	//array
 	int a[10]={20,30,20,70,7,30,25,12,25,90};
 	
 	//loop for printing original array
 	cout<<"original array with index no\n";
 	 for(int i =0; i<10; i++)
	 {
	 	cout<<i<<") "<<a[i]<<endl;
	 }
 	
 	
 	//asking user for value and index
 	int value,index;
 	cout<<"enter a value to swap\n";
 	cin>>value;
 	cout<<"enter index no from 0 to 9\n";
 	cin>>index;
 	
 	
 	//nested loops for swapping
 	for(int i =0; i<10; i++)
 	{
 		if(i==index)
 		{
 			
 			for(int i=9; i>index; i--)
 			{
 				a[i]=a[i-1];
			 }
 			a[i]=value;
		 }	
	 }
	 
	 
	 
	 //loop for showing array with swapped values
	 cout<<"your value is swapped at "<<index<<" index\n";
	 for(int i =0; i<10; i++)
	 {
	 	cout<<i<<") "<<a[i]<<endl;
	 }
}
