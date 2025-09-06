#include<iostream>
 using namespace std;
 
 int main()
 {
 	
 	//original array
 	int a[10]={25,30,25,70,30,25,12,25,90};
 
 
 	//loop for sorting array
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


	//loop for printing original array
	  cout<<"sorted value of array with index\n";
	  for(int i=0;i<10; i++)
	 {
	 	cout<<i<<") "<<a[i]<<endl;
	 }
	 cout<<endl<<endl;
 	
 	
 	
 	//loop to find repeated numbers
 	for(int i =0; i<10; i++)
 	{
 		int count=0;
 		
 		for(int j=i; j<10; j++ )
 		{
 			if(a[i]==a[j])
 			{
 				
 				count++;	
			 }	
		 }
		 if(count>1)
		 {
		 	//showing repeated elements
		 	cout<<a[i]<<" is repeated "<<count<<" times"<<endl;
		 }
		 
		 i=i+(count-1);
		 
 		
	 }
 
 
 
 
 
 }
