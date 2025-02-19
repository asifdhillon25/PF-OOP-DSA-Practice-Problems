

#include <iostream>
#include <fstream>
#include <string>

#include "dvdListType.h"
#include "linkedlist.h"
#include "linkedListIterator.h"
#include "linkedListType.h"
#include"unorderedLinkedList.h"

#include"unorderedLinkedList.cpp"
#include "linkedListType.cpp "
using namespace std;

void createDVDList (ifstream& infile,dvdListType& dvdList);
void displayMenu();
void enterNewDVDInfo(dvdListType& dvdList);

int main()
{
	dvdListType dvdList;

	int choice;
	char ch;
	string title;
	ifstream infile;
	//open the input file

	infile.open("dvdDat.txt");

	if (!infile)
	{
		cout << "The input file does not exist. "
			<< "The program terminates!!!" << endl;
		return 1;
	}
	//create the DVD list
	createDVDList(infile, dvdList);
	infile.close();
	//show the menu
	displayMenu();

	cout << "Enter your choice: ";
	cin >> choice; //get the request
	cin.get(ch);
	cout << endl;




		
		//process the requests
		while (choice != 9)
		{
			switch (choice)
			{
			case 1:
				cout << "Enter the title: ";
				getline(cin, title);
				cout << endl;
				if (dvdList.dvdSearch(title))
					cout << "The store carries " << title
					<< endl;
				else
					cout << "The store does not carry "
					<< title << endl;
				break;
			case 2:
				cout << "Enter the title: ";
				getline(cin, title);
				cout << endl;
				if (dvdList.dvdSearch(title))
				{
					if (dvdList.isDVDAvailable(title))
					{
						dvdList.dvdCheckOut(title);
						cout << "Enjoy your movie: "
							<< title << endl;
					}
					else
						cout << "Currently " << title
						<< " is out of stock." << endl;
				}
				else
					cout << "The store does not carry "
					<< title << endl;
				break;
			case 3:
				cout << "Enter the title: ";
				getline(cin, title);
				cout << endl;
				if (dvdList.dvdSearch(title))
				{
					dvdList.dvdCheckIn(title);
					cout << "Thanks for returning "
						<< title << endl;
				}
				else
					cout << "The store does not carry "
					<< title << endl;
				break;
			case 4:
				cout << "Enter the title: ";
				getline(cin, title);
				cout << endl;
				if (dvdList.dvdSearch(title))
				{
					if (dvdList.isDVDAvailable(title))
						cout << title << " is currently in "
						<< "stock." << endl;
					else
						cout << title << " is currently out "
						<< "of stock." << endl;
				}
				else
					cout << "The store does not carry "
					<< title << endl;
				break;
			case 5:
				dvdList.dvdPrintTitle();
				break;
			case 6:
				dvdList.print();
				break;
			case 7:
				enterNewDVDInfo(dvdList);
				break;

				
			default:
				cout << "Invalid selection." << endl;
			}//end switch
			displayMenu(); //display menu
			cout << "Enter your choice: ";
			cin >> choice; //get the next request
			cin.get(ch);
			cout << endl;
		}//end while
	return 0;
}

void createDVDList(ifstream& infile,
	dvdListType& dvdList)
{
	string title;
	string star1;
	string star2;
	string producer;
	string director;
	string productionCo;
	char ch;
	int inStock;
	dvdType newDVD;
	getline(infile, title);
	while (infile)
	{
		cout << "Enter star 1 name\n";
		getline(infile, star1);
		cout << "Enter star 2name\n";

		getline(infile, star2);
		cout << "Enter producer name\n";

		getline(infile, producer);
		cout << "Enter director name\n";

		getline(infile, director);
		cout << "Enter production company name\n";

		getline(infile, productionCo);
		infile >> inStock;
		infile.get(ch);
		newDVD.setDVDInfo(title, star1, star2, producer,
			director, productionCo, inStock);

		dvdList.insertFirst(newDVD);
		getline(infile, title);
	}//end while
}//end createDVDList



void displayMenu()
{
	cout << "Select one of the following:" << endl;
	cout << "1: To check whether the store carries a "
		<< "particular DVD." << endl;
	cout << "2: To check out a DVD." << endl;
	cout << "3: To check in a DVD." << endl;
	cout << "4: To check whether a particular DVD is "
		<< "in stock." << endl;
	cout << "5: To print only the titles of all the DVDs."
		<< endl;
	cout << "6: To print a list of all the DVDs." << endl;
	cout << "7: Enter info of new dvd." << endl;
	cout << "9: To exit" << endl;
}


void enterNewDVDInfo(dvdListType& dvdList)
{
	string title, star1, star2, producer, director, productionCo;
	int inStock;

	cout << "Enter the title: ";
	cin.ignore(); // Clear the newline character left in the input buffer
	getline(cin, title);

	cout << "Enter the name of the first star: ";
	getline(cin, star1);

	cout << "Enter the name of the second star: ";
	getline(cin, star2);

	cout << "Enter the producer's name: ";
	getline(cin, producer);

	cout << "Enter the director's name: ";
	getline(cin, director);

	cout << "Enter the production company's name: ";
	getline(cin, productionCo);

	cout << "Enter the number of copies in stock: ";
	cin >> inStock;

	dvdType newDVD;
	newDVD.setDVDInfo(title, star1, star2, producer, director, productionCo, inStock);
	dvdList.insertFirst(newDVD);
}
