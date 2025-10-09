#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	
	srand((unsigned int)time(0));
	string name;
	bool end =false;
	bool lost;
	int menu;
	
	//starting units
	int archers = 50;
	int catapults = 25;
	int swordsmen =100;
	
	//german units
	int g_archers = rand()% (51) + 20;
	
	int g_catapults= rand()% (41) + 10;
	int g_swordsmen= rand()% (101) + 50;
	
	//correspond menu
	int archers_menu;
	int catapults_menu;
	int swordsmen_menu;
	int fight_menu;
	
	cout<<"enter your name\n";
	cin>> name;
	
	cout<<"well "<<name<<" WELCOME to roman commander game "
		<<"you are a commander of Pakarmy "
		<<"fighting india";
		
	
	while(!end)
	{
		int archers_sent=0;
		int catapults_sent=0;
		int swordsmen_sent=0;
		
		cout<<"you have\n"
		<<archers<<"archers.\n";
		cout<<swordsmen<<"swordsman.\n";
		cout<<catapults<<"catapults.\n";
		
			cout<<"india has\n"
		<<g_archers<<"archers.\n";
		cout<<g_swordsmen<<"swordsman.\n";
		cout<<g_catapults<<"catapults.\n";
		
			do //pre battle loop
			{
				int i=1;
				
				
				if(archers>0 && ((archers-archers_sent) !=0 ))
				{
					archers_menu=i;
					cout<<"["<< i <<"]" "send archers\n";
				}
				else archers_menu=0;
				
					if(catapults>0 && ((catapults-catapults_sent) !=0 ))
				{
					catapults_menu=i;
					cout<<"["<< i <<"] send catapults\n";
				}
				else catapults_menu=0;
				
					if(swordsmen>0 && ((swordsmen-swordsmen_sent) !=0 ))
				{
					swordsmen_menu=i;
					cout<<"["<< i <<"] send swordsmen\n";
				}
				else swordsmen_menu=0;
				
				fight_menu=i;
				cout<<"["<< i <<"] go fight \n";
				cin>> menu_choice;
				
				if(menu_choice==archers_menu)
				{
					
				}
				
		}
	}
		
		
	
		
		
}

