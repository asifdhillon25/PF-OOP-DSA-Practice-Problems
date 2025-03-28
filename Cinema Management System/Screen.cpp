#include "Screen.h"

Screen::Screen(int noOFSeats)
{
	for (int i = 0; i < noOFSeats; i++)
	{
		Seat* newSeat = new Seat();

		newSeat->SeatSeatNo(i + 1);

		SeatList.push_back(newSeat);
	}
}

void Screen::ShowSeats()
{
	cout << "\n\n\t\t  ==============================Screen=====================================\n\n\n\n";

	cout << "\t\t";
	for (int i = 0; i < SeatList.size(); i++)
	{
		if (SeatList[i]->GEtActive())
		{
			cout << ANSI_COLOR_RED << "Seat" << i << ANSI_COLOR_RESET << "\t";
		}
		else
		{
			cout << ANSI_COLOR_GREEN << "Seat" << i << ANSI_COLOR_RESET << "\t";
		}

		if ((i + 1) % 10 == 0)
		{
			cout << "\n\t\t";
		}
	}
}

void Screen::ChangeSeatActiveness(int seatno, bool activevalue)
{
	if (seatno >= 0 && seatno < SeatList.size())
	{
		SeatList[seatno]->SetActive(activevalue);
		cout << "seat changed\n";
	}
}

bool Screen::getSeatActiveness(int seatno)
{
	if (seatno<0 || seatno>SeatList.size())
	{
		cerr << "\t\t\nWrong Seat NO......\a\n";
		
	}

	return SeatList[seatno]->GEtActive();
}

// Setter functions

void Screen::setMovieShowing(const std::string& newMovieShowing) {
	MovieShowing = newMovieShowing;
}
