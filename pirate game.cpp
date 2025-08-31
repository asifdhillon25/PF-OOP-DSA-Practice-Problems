#include<iostream>
using namespace std;
main(void)
{
	int buddies;
	int afterbattle;
	cout<<"you are pirate anad walking \n"
		<<"in city of havana (1890)\n get some pirates for your journey."
		<<"\n how many pirate you bring along\n";
		
		cin>>buddies;
		
		while (buddies<=50)
		{
			cout<<"enter value greator than 50"<<endl;
			cin>>buddies;
		}
		afterbattle = 1+buddies-33;
	
		cout<<"after battle there are only\n\t"
			<<(1 + buddies - 33)
			<<"\nleft including you";
		
			
			cout<<"they found 4000 gold coins \nafter battle "
				<<"each get  \n"
				<<(4000/afterbattle)
				<<"gold coins\n";
				
				cout<<"they fight for the last  "
				<<(4000 % afterbattle);
				
				cout<<" all died because \n \"greed is a curse\"";
				
	
}			
