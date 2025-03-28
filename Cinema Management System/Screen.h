#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Seat.h"
using namespace std;

// ANSI escape codes for text color
constexpr auto ANSI_COLOR_GREEN = "\x1b[32m";
constexpr auto ANSI_COLOR_RED = "\x1b[31m";
constexpr auto ANSI_COLOR_WHITE = "\x1b[37m";
constexpr auto ANSI_COLOR_RESET = "\x1b[0m";





class Screen
{

public:


	Screen(int noOFSeats);
	void ShowSeats();
	void ChangeSeatActiveness(int seatno, bool activevalue);
	bool getSeatActiveness(int seatno);

	std::string getMovieShowing() const {
		return MovieShowing;
	}

	// Setter functions
	void setMovieShowing(const std::string& newMovieShowing);

private:
	string MovieShowing;
	
	vector <Seat*> SeatList;

};

