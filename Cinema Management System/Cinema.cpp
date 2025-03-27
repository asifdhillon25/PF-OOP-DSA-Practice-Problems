#include "Cinema.h"


Cinema::Cinema()
{
	std::vector<std::string> movies = { "Interstellar", "Inception", "Tenet" };
	for (int i = 0 ; i < movies.size(); i++)
	{
		MoviesList.push_back(new Movies(i + 1, movies[i]));
	}

	for (int i = 0; i < movies.size(); i++)
	{
		ScreenList.push_back(new Screen(100));
		ScreenList.back()->setMovieShowing(movies[i]);
	}

}

void Cinema::AddCustomer()
{
	ShowAllMovies();

	std::cout << "Enter number to select Movie: ";
	std::string SelectedMovie;
	cin.ignore();
	std::getline(std::cin, SelectedMovie);


	// Convert string to integer using atoi
	int ID = std::atoi(SelectedMovie.c_str());
	cout << "id is" << ID << endl;
	int ScreenID = GEtScreenviaID(ID); //function to show available seat on respective screen
	

	
	ScreenList[ScreenID]->ShowSeats();

	cout << "\n\t\tEnter Seat no to select\n";
	int seatno;
	cin >> seatno;
	if (ScreenList[ScreenID]->getSeatActiveness(seatno) == true)
	{
		cout << "\t\t\nSeat Already occupied.......\n";
		return;
	}

	ScreenList[ScreenID]->ChangeSeatActiveness(seatno , true);

	cout << "\n\t\tYour Seat HAs Been Selected........\a\n";

	
		CustomerList.push_back(new Customer);
		int Cid = CustomerList.size();
		CustomerList.back()->setID(Cid);
		CustomerList.back()->setSeatno(seatno);
		CustomerList.back()->SetCustomerScreen(ScreenID);

}

void Cinema::ShowCustomer()
{
	if (CustomerList.empty())
	{
		cout << "\n\t\t\aNo customers....\n";
	}

	for (auto& C : CustomerList)
	{
		cout << "\t\t" << C->getID() << "  " << C->getSeatno() << "\n";
	}
}

void Cinema::AddNewMovie(string MovieTitle)
{
	int MovieID = MoviesList.size() + 1;
	Movies* newmovie = new Movies(MovieID,MovieTitle);
	MoviesList.push_back(newmovie);
}

void Cinema::RemoveMOvie()
{
	ShowAllMovies();
	cout << "\t\tEnter ID to Remove That Movie\n";
	int MID;
	cin >> MID;

	for (auto it = MoviesList.begin(); it != MoviesList.end(); it++)
	{
		if ((*it)->getID() == MID)
		{
			delete (*it);
			it = MoviesList.erase(it);
			cout << "\n\t\tRecord Deleted Successfully.......\n";
			return;
		}
	}

	cout << "\t\nNo Data with this Id\n";
}

void Cinema::RemoveCustomer()
{
	ShowCustomer();

	cout << "\n\t\tEnter Customer Id to Delete\n";

	int CID;
	cin >> CID;

	for (auto it = CustomerList.begin(); it != CustomerList.end(); it++)
	{
		if ((*it)->getID() == CID)
		{
			delete (*it);
			it = CustomerList.erase(it);
			cout << "\n\t\tRecord Deleted Successfully.......\n";
			return;
		}
	}

	cout << "\t\nNo Data with this Id\n";


}

void Cinema::SHowAvailableSeats()
{
	for (auto& Scr : ScreenList)
	{
		Scr->ShowSeats();
	}
}

void Cinema::SetScreenMovie()
{
	ShowAllMovies();
	ShowScreenMOvies();

	cout << "\n\t\tEnter Movie Id to Add\n";

	int MID;
	cin >> MID;

	cout << "\n\t\tEnter Screen Id to Add\n";

	int SID;
	cin >> SID;


	//to check if not out of bound
	if ((MID >= 0 && MID < MoviesList.size()) && (SID >= 0 && SID < ScreenList.size()))
	{
		ScreenList[SID - 1]->setMovieShowing(MoviesList[MID - 1]->getMovieTitle());
		cout << "\n\t\t SET successfully.....\n";
		return;

	}


	cout << "\t\nInvalid Index\n";

}



int Cinema::GEtScreenviaID(int ID)
{
	for (int i = 0; i < ScreenList.size(); i++)
	{
		if (ScreenList[i]->getMovieShowing() == MoviesList[ID - 1]->getMovieTitle())
		{
			return i;
		}
	}

	return -1;
}

void Cinema::ShowScreenMOvies()
{
	for (int i = 0; ScreenList.size(); i++)
	{
		cout << "\n\t\t" << i + 1 << ScreenList[i]->getMovieShowing() << "\n";
	}
}


void Cinema::ShowMenu() {
	cout << "\t\tMenu:\n\n";
	cout << "\t\t1. Add Customer\n\n";
	cout << "\t\t2. Show Customers\n\n";
	cout << "\t\t3. Add New Movie\n\n";
	cout << "\t\t4. Remove Movie\n\n";
	cout << "\t\t5. Remove Customer\n\n";
	cout << "\t\t6. Show Available Seats\n\n";
	cout << "\t\t7. Set Screen Movie\n\n";
	cout << "\t\t8. Get Screen via ID\n\n";
	cout << "\t\t9. Exit\n\n";
}

void Cinema::ShowAllMovies()
{
	for (auto& MOVIES : MoviesList)
	{
		cout << "\t\tID: " << MOVIES->getID() << "  " << "NAme: " << MOVIES->getMovieTitle() << endl;
	}
}
