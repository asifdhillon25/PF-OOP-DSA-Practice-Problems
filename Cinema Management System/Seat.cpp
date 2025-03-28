#include "Seat.h"

Seat::Seat()
{
	SeatNo = 0;
	isActive = false;
	Type = "sofa";
}

void Seat::SeatSeatNo(int No)
{
	SeatNo = No;
}

int Seat::GEtSeatNo()
{
	return SeatNo;
}

void Seat::SetActive(bool activeness)
{
	isActive = activeness;
}

bool Seat::GEtActive()
{
	return isActive;
}

void Seat::SetType(string type)
{
	Type = type;
}

string Seat::GetTYPE()
{
	return Type;
}