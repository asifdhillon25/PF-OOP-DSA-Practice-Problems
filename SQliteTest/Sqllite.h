#pragma once
#include <iostream>
#include "sqlite/sqlite3.h"
using namespace std;
#include "Rent.h"

class Sqllite
{

	sqlite3* db;
	int rc;
	string Filename = "MyFile.db";

public:

	Sqllite();
	bool CreateTable();
	void WriteData();
	void openFile(string FileName);
	void PrintAllData();
    void Search(const char* value);
    void Delete();
	int getidcount();
	~Sqllite();

	



};


