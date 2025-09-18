#include<iostream>
 using namespace std;
 
 int main()
 {
 	int a[10]={20,30,300,279,9,38,25,12,120,90};
 	
 	
 	
 	cout<<"*******Program to find maximum and minimum differ of array*******\n\n\n";
 	

	 
	 
	 
	 //code for sorting array	 
	 for(int i=0;i<10; i++)
	{
    for(int i=0;i<10; i++)
     {
         if(a[i]>a[i+1])
         {
             int c,b;

            c= a[i];
             b=a[i+1];
             a[i+1]=c;
             a[i]=b;

         }

     }
	 
}
//     showing value of array
	  cout<<"sorted value of array with index\n";
	  for(int i=0;i<10; i++)
	 {
	 	cout<<i<<") "<<a[i]<<endl;
	 }
	 
	 
	 
	 
//code for maximumm and minimum of array
	 int min,min1,index;
	 
	 min=a[1]-a[0];
	 for(int i=1;i<9; i++){
	 	
	 	min1=a[i+1]-a[i];
	 	if(min1<min)
	 	{	index=i;
	 		min=min1;
		 }
	 	
	 }
	 
	 cout<<"\n\nmaximum differ is "<<a[9]-a[0]<<" between "<<a[9]<<" and "<<a[0]<<endl;
	 cout<<"minimum differ is "<<min<<" between "<<a[index+1]<<" and "<<a[index]<<endl;
	 
 }
 
