#include<iostream>
#include <stdio.h>
using namespace std;


class Batsman{
	
	private:
		int Batcode;
		int Notout_innings;
		int Totalinnings;
		int Runs;
		int Bestscore;
		string Batsman_Name;
		float Batsman_average;
		
		float Calcavg(int runs,int innings)
		{
//			cout<<"Batsman Average: "<<Runs/Notout_innings;

			float average;
			average=runs/innings;
			
			return average;
		}
		
		public:
			
			void Read_data(int batcode,int runs,int innings,int bestscore,
			string name,int totalinning){
				
				Batcode=batcode;
				Bestscore=bestscore;
				Runs=runs;
				Totalinnings=totalinning;
				Notout_innings=innings;
				Batsman_Name=name;
				Batsman_average=Calcavg(runs,totalinning);
				
				
				
			}
			
			void display_data()
			{
				cout<<"***Batsman Information***\n\n\n";
				
				cout<<"\tBatsman Name: "<<Batsman_Name<<endl;
				cout<<"\tBatsman Bestscore: "<<Bestscore<<endl;
				cout<<"\tBatsman Batcode: "<<Batcode<<endl;
				cout<<"\tBatsman Average: "<<Batsman_average<<endl;
				cout<<"\tBatsman Runs: "<<Runs<<endl;
				cout<<"\tBatsman Total innings: "<<Totalinnings<<endl;
				cout<<"\tBatsman Notout innings: "<<Notout_innings<<endl;
				
				}	
				
			
	
	
};



int main(){
	
	Batsman Asif;
	
	
	
	Asif.Read_data(1004,3087,25,105,"Asif",73);
	
	Asif.display_data();
	
	Batsman hmza;
	
	hmza.Read_data(3456,3215,78,23,"HAMZA",54);
	
	hmza.display_data();
	
	
}
