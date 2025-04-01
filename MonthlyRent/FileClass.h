#pragma once
#include <iostream>
#include <string>
#include "Rent.h"
#include <vector>
#include "Rentals.h"


class FileClass:public Rentals
{
	string Month;
	string Name;
	double Balncerent;
	double PaidRent;

public:

	FileClass():Rentals()
	{
		GetelectricityBill();
		Calculaterent();
		
	}


	void GetData()
	{
		cout << "Enter Month Name\n";
		cin.ignore();
		getline(cin, Month);
		cout << "Enter Person Name\n";
		getline(cin, Name);
		cout << "Enter rent He Paid\n";
		cin >> PaidRent;
		Balncerent=this->RentPerPerson - PaidRent;
		
	}


	void Printdata()
	{
		cout << "\tName: " << Name<<endl;
		cout << "\tMonth: " << Month<<endl;
		cout << "\tRent that Month: " << GetRentPerPerson();
		cout << "\tElectricity Bill That Month: " << this->BillPerPerson;
		cout << "\tRent Paid: " << PaidRent;
		cout << "\tRemaining Balance: " << Balncerent;
	}

	 void GetelectricityBill()
	{
		Rentals::GetelectricityBill();
	}

};

