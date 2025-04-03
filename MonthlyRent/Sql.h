#pragma once
#include "sqlite/sqlite3.h"
#include "Rent.h"



class Sql
{
	sqlite3* db;
	int Rc;
public:

	void enterdata()
	{
		Rc=sqlite3_open("mydb.db", &db);
		if (!errorchk(Rc))
		{
			const char* createTableSql = "CREATE TABLE MyTable ( id INT, Name TEXT,rent TEXT);";
			Rc=sqlite3_exec(db, createTableSql, 0, 0,0);
		}

		if (Rc != SQLITE_OK) {
			std::cerr << "Error creating table: " << sqlite3_errmsg(db) << std::endl;
			
		}
		
		sqlite3_close(db);
	}



	void insertData()
	{

		Rc = sqlite3_open("mydb.db", &db);
		if (!errorchk(Rc))
		{
			const char* insertSQL = "INSERT INTO People (id , Name ,rent ) VALUES (1, 'John', 30,);";
			Rc = sqlite3_exec(db, insertSQL, 0, 0, 0);

			if (Rc != SQLITE_OK) {
				std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
				
			}
		}

	}


	bool errorchk(int rc)
	{
		if (rc) {
			std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
			return 1;
		}
		return 0;
	}

};

