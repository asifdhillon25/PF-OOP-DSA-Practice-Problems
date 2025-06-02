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
	string  Month;
	string Name;
	double Balncerent;
	double PaidRent;
	string Rnames[5] = { "Asif","Hamza","Hamza Umt","Talha","Fahad"};
	std::string months[12] = {
	   "JANUARY",
	   "FEBRUARY",
	   "MARCH",
	   "APRIL",
	   "MAY",
	   "JUNE",
	   "JULY",
	   "AUGUST",
	   "SEPTEMBER",
	   "OCTOBER",
	   "NOVEMBER",
	   "DECEMBER"
	};
	
	

public:
	static int ID;

	const char* GetName() { return Name.c_str(); }
	const char* GetMonth() { return Month.c_str(); }
	double GetPaidRent() { return PaidRent; }
	double GetBalanceRent() { return Balncerent; }
	


	void GetData()
	{
		
		cout << "Enter Month Name\n";
		Month=Monthcheck();
		
		cout << "\n***Enter Specific  Person Name***\n";
		ShowRentalNames();
		Name = NameCheck();
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

	double GetTotalRent() { return RentPerPerson; }
	double GetBill() { return TotalElecricityBill; }


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
	

	int GetId()
	{
		
		

		 return ID;
	}
	
	
	string Monthcheck()
	{ 
		string mont;
		label1:
		getline(cin, mont);



		for (int i = 0; i < 12; i++)
		{
			if (mont == months[i])
			{
				return months[i];
			}

		}

		cout << "plaease enter valid month name in Capital letters\n ";
		goto label1;


	}

	string NameCheck()
	{
		string nam;
	label1:
		getline(cin, nam);



		for (int i = 0; i < 5; i++)
		{
			if (nam == Rnames[i])
			{
				return Rnames[i];
			}

		}

		cout << "plaease enter valid Name in Capital letters\n ";
		goto label1;
	}

};

