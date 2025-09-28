#include<iostream>
using namespace std;

int main()
{
					//start of program
	//body mass index calculator
	cout<<"BMI CALCULATOR\n";
	
	//initializing values
	float height;
	float weight;
	float BMI;
	
	//taking input from user
	cout<<"enter your height in meters\n";
	cin>>height;
	cout<<"\nenter your weight in KG\n";
	cin>>weight;
	//assigning formula of bmi
	BMI=weight/(height*height);
	
	cout<<"your BMI is =  "
		<<BMI<<endl;
		
	//displaying health condition according to BMI
	if(BMI<18.5)
	{
		cout<<"you are underweight.";
		
	}
	if(BMI >=18.5 && BMI<= 24.9)
	{
		cout<<"you are normal.";
	}
	
	if(BMI>=25 && BMI<=29.9)
	{
		cout<<"you are overweight";
	}
	
		if(BMI>=30)
	{
		cout<<"you are obese";
	}
	
	//end of program
	
	
	
}
