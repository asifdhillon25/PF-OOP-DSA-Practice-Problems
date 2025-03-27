#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "Screen.h"
#include "Movies.h"
#include "Customer.h"

class Cinema
{
public:
	Cinema();
	void AddCustomer();
	void ShowCustomer();
	void AddNewMovie(string MovieTitle);
	void RemoveMOvie();
	void RemoveCustomer();
	void SHowAvailableSeats();
	void SetScreenMovie();
	void ShowMenu();
	void ShowAllMovies();
	int GEtScreenviaID(int id);
	void ShowScreenMOvies();
	
private:
	vector<Customer*> CustomerList;
	vector<Screen*> ScreenList;
	vector <Movies*> MoviesList;
};

