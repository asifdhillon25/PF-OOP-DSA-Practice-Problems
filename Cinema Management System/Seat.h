#pragma once
#include <iostream>
#include <string>
using namespace std;

class Seat
{
public:
	Seat();
	void SeatSeatNo(int no);
	int GEtSeatNo();
	void SetActive(bool activeness);
	bool GEtActive();
	void SetType(string type);
	string GetTYPE();




private:
	int SeatNo;
	string Type;
	int isActive;

	

};

