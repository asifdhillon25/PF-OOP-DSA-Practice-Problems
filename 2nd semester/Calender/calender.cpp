#include <iostream>
#include <string>
using namespace std;

class Daytype{

    int Daycount;
    string   NoOfdays[7]={"Monday","Tuesday",
                          "Wednesday","Thursday","Friday","Saturday","Sunday"};

public:

    Daytype(){



        cout<<"Enter the value to set the day\n";

        Daycount=menu();



    }
    int menu(){

        int choice;
        do
        {
            cout<<"\tChoose A DAY To Set\n";
            cout<<"\t1: Monday\n"
                <<"\t2: Tuesday\n"
                <<"\t3: Wednesday\n"
                <<"\t4: Thursday\n"
                <<"\t5: Friday\n"
                <<"\t6: Saturday\n"
                <<"\t7: Sunday\n";
            cout<<"Choose a number : ";
            cin>>choice;
            system("cls");
        }
        while(choice<1 || choice>7);

        return choice;
    }

    void Setday(){

        cout<<"Enter the value to set the day\n";

        Daycount=menu();
        cout<<"Your day has been set\n";

    }

    string GetCurrentday(){

        return NoOfdays[Daycount-1];
    }

    string GetNextday(){

        return NoOfdays[Daycount];
    }

    string GetPreviousday(){
    	
    	if(Daycount>=2)
    	{
    	return NoOfdays[Daycount-2];	
		}
        else if(Daycount==1)
        {
        	return NoOfdays[6];
		}
        
    }



    string bychoice(int choice){

        
        for (int i = 0; i < choice; ++i) {

            
            if(choice<=7)
            {
                break;
            }
            choice-=7;
        }

        if (choice<7)
        {
            return NoOfdays[choice];

        }
        else if(choice==7){
            return GetCurrentday();
        }
    }




};


