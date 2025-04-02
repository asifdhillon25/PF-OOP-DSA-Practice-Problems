#pragma once
#include <iostream>
#include <string>
#include "Rent.h"
#include <vector>

class Rentals:public Rent
{
protected:
	vector <string> NameofRental;
	int numRent = 5;

public:

	Rentals() :Rent(numRent)
	{
		
		NameofRental.push_back("ASIF") ;
		NameofRental.push_back("FAHAD");
		NameofRental.push_back("HamzaUMT");
		NameofRental.push_back("HAMZA");
		NameofRental.push_back("TALHA");
		
	}


	void AddNewRental(string Name)
	{
		NameofRental.push_back(Name);
		this->numberOfRentals++;
	}


	virtual void GetelectricityBill()
	{
		Rent::GetelectricityBill();
	}

};

