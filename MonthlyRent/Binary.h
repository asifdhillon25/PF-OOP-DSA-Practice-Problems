#pragma once
#include <iostream>
#include <string>
#include "Rent.h"
#include <fstream>


using namespace std;

class Binary
{

public:


	void Write()
	{
		fstream File;

		File.open("rent.dat", ios::binary | ios::app | ios::out);

			if(!File)
			{
				cout << "Cant open file\n";
				return;
			}

			Rent myobj;
			myobj.GetelectricityBill();
			myobj.GetData();
			myobj.Calculaterent();

			File.write(reinterpret_cast<char*>(&myobj), sizeof(myobj));
			File.close();
			
	}

	void Read()
	{
		fstream File;
		File.open("rent.dat", ios::binary | ios::in);

		if (!File)
		{
			cout << "Cant open file\n";
			return;
		}
		Rent myobj;
		while (File.read(reinterpret_cast<char*>(&myobj), sizeof(myobj)))
		{
			

			myobj.Printdata();
		}
		
		
		File.close();

	}


	void Modify()
	{


	}

};




//
//#include <iostream>
//#include <fstream>
//#include <ctime>
//#include <string>
//
//int main() {
//	std::string userData;
//	std::cout << "Enter some data: ";
//	std::getline(std::cin, userData);
//
//	std::time_t currentTime = std::time(nullptr);
//	std::string timeStr = std::ctime(&currentTime);
//
//	std::ofstream outFile("data_with_time.txt", std::ios::app);
//
//	if (outFile.is_open()) {
//		outFile << "Data: " << userData << "\n";
//		outFile << "Timestamp: " << timeStr << "\n";
//		outFile.close();
//		std::cout << "Data and timestamp written to the file." << std::endl;
//	}
//	else {
//		std::cerr << "Failed to open the file for writing." << std::endl;
//	}
//
//	return 0;
//}
