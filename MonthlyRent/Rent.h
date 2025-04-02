#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <ctime>

class Rent
{
protected:
	const double TotalRent = 25000;
	double TotalElecricityBill;
	double BillPerPerson;
	int numberOfRentals=5;
	double RentPerPerson;
	char Month[10];
	char Name[20];
	double Balncerent;
	double PaidRent;
	string Rnames[5] = { "Asif","Hamza","Hamza Umt","Talha","Fahad"};
	

public:



	void GetData()
	{
		cout << "Enter Month Name\n";
		cin.ignore();
		cin.getline( Month,10);
		cout << "\n***Enter Specific no for Person Name***\n";
		ShowRentalNames();
		int num; cin >> num;
		strcpy_s( Name,Rnames[num].c_str());
		cout << "Enter rent He Paid\n";
		cin >> PaidRent;
		
		

		

	}

	void Printdata()
	{
		cout << "\tName: " << Name << endl;
		cout << "\tMonth: " << Month << endl;
		cout << "\tRent that Month: " << GetRentPerPerson() << endl;;
		cout << "\tElectricity Bill That Month: " << BillPerPerson << endl;;
		cout << "\tRent Paid: " << PaidRent << endl;;
		
	}

	void Calculaterent()
	{
		

		BillPerPerson = (TotalElecricityBill / 2) / numberOfRentals;

		RentPerPerson = (TotalRent / numberOfRentals) + BillPerPerson;

		Balncerent = RentPerPerson - PaidRent;

	}

	double GetRentPerPerson()
	{
		return RentPerPerson;
	}

	 void GetelectricityBill()
	{
		cout << "Enter This month Electricity Bill\n";
		cin >> TotalElecricityBill;
	}

	void GetNoOfRentals()
	{
		cout << "Enter no of rentals living this month\n";
		cin >> numberOfRentals;
	}

	void ShowRentalNames()
	{
		cout << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << Rnames[i] << " , ";
		}
		cout << endl;
	}
	
};

