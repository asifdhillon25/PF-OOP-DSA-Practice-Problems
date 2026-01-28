#include<iostream>
#include <stdio.h>
using namespace std;


class Student{
	
	int Admission_num;
	float Eng_Mrk;
	float Math_Mrk;
	float Sci_Mrk;
	float Total_Mrk;
	string Student_name;
	
	
	float ctotal(float eng,float math,float sci)
	{
		
		float total;
		total=eng+math+sci;
		
		return total;
	}
	
	
	public:
		//costructor
		Student(float eng,float math,float sci,string name){
			
			Eng_Mrk=eng;
			Math_Mrk=math;
			Sci_Mrk=sci;
			Student_name=name;
		}
		
		void ShowData()
		{
			
			
			cout<<"   ***Student Information***\n\n\n";

			cout<<"\tStudent Name: "<<Student_name<<endl;
			cout<<"\tEnglish Marks: "<<Eng_Mrk<<endl;
			cout<<"\tMath Marks: "<<Math_Mrk<<endl;
			cout<<"\tScience Marks: "<<Sci_Mrk<<endl;
			cout<<"\n\tTotal Marks: "<<ctotal(Eng_Mrk,Math_Mrk,Sci_Mrk);

			
			
			
		}
	
	
};



int main(){
	
	
	
	Student Asif(34,56,78,"asif");
	Asif.ShowData();
	
	
	Student hm(34,56,78,"hamza");
	hm.ShowData();
	
}
