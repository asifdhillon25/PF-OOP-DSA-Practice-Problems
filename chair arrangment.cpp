#include<iostream>
using namespace std;

int main(){
	
	int numguest;
	int chair,n;
	//asking user for values
	cout<<"enter the no of guests\n";
	cin>>numguest;
	cout<<"enter the no of chairs\n";
	cin>>chair;
	
	
	n=numguest;
	int p=1;
	
	//loop for calculating possible arrangements
	for(int i=1; i<=chair; i++){
		
		p=p*n;
		n--;
		
		
	}
	cout<<"they can sit with "<<p<<" different arrangements";
	
}
