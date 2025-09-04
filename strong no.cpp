#include<iostream>
 using namespace std;
 
 void strong(int num)
 {
 		int m,n,rev,r,l=1,j,sum=0,k;
 	//145
 	cin>>num;
 	n=num;
 	
 	do
 	{
 		m=n%10;
 		l=1;
 		j=1;
 		
 		for(int i=1; i<=m; i++)
 		{
 			
 			k=l*j;
 			
 			l=k;
 			
 			j++;
 			
 			
 			
		 }
		 
		 cout<<l<<endl;
		 
		 sum=sum+l;
 		n=n/10;
 		
 		
	 }
	 while(n!=0);
	 cout<<sum;
	 if(sum==num)
	 cout<<"strong";
	 else
	 cout<<"not strong";
 	
 }
 
 
 int main()
 {
 	int n;
 	
 	cin>>n;
 	
 	
 	strong(n);
 	
 	
 
 }
