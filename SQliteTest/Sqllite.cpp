#include "Sqllite.h"
#include <iomanip>

 bool Sqllite::CreateTable()
{
	

	const char* crtable = "CREATE TABLE IF NOT EXISTS MyTable (ID INT, Name TEXT, Month TEXT,RentGiven REAL,BalanceRent Real,TotalRent Real,ElectricityBill Real);";
	int rc = sqlite3_exec(db, crtable, 0, 0, 0);

	if (rc != SQLITE_OK) {
		std::cerr << "Error creating table: " << sqlite3_errmsg(db) << std::endl;
		return false;
	}

	return true;
}

void Sqllite::WriteData()
{
	

	const char* Insert = "INSERT INTO MyTable (ID,Name,Month,RentGiven,BalanceRent,TotalRent,ElectricityBill) VALUES (?,?,?,?,?,?,?);";
	sqlite3_stmt* stmt;
	rc = sqlite3_prepare_v2(db, Insert, -1, &stmt, 0);
	if (rc != SQLITE_OK) {
		std::cerr << "Failed to prepare the statement: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
		return;
	}

	Rent Myobj;
	Myobj.GetelectricityBill();
	Myobj.GetData();

	Myobj.Calculaterent();
	Myobj.Printdata();



	sqlite3_bind_int(stmt, 1, getidcount());
	
	sqlite3_bind_text(stmt, 2, Myobj.GetName(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, Myobj.GetMonth(), -1, SQLITE_STATIC);
	sqlite3_bind_double(stmt, 4, Myobj.GetPaidRent());
	sqlite3_bind_double(stmt, 5, Myobj.GetBalanceRent());
	sqlite3_bind_double(stmt, 6, Myobj.GetTotalRent());
	sqlite3_bind_double(stmt, 7, Myobj.GetBill());


	rc = sqlite3_step(stmt);

	if (rc != SQLITE_DONE) {
		std::cerr << "Failed to execute the statement: " << sqlite3_errmsg(db) << std::endl;
	}

	sqlite3_finalize(stmt);
	




}

 void Sqllite::openFile(string FileName)
{

	rc = sqlite3_open(FileName.c_str(), &db);
	if (rc != SQLITE_OK)
	{
		cout << "error file opening\n" << sqlite3_errmsg(db) << endl;
	}
}

  void Sqllite::PrintAllData() {
	 

	 const char* selectAll = "SELECT * FROM MyTable;";
	 sqlite3_stmt* stmt;
	 rc = sqlite3_prepare_v2(db, selectAll, -1, &stmt, 0);
	 if (rc != SQLITE_OK) {
		 std::cerr << "Failed to prepare the SELECT statement: " << sqlite3_errmsg(db) << std::endl;

		 return;
	 }
	 std::cout << "========================================================================================\n"
		 << "ID  NAME      Month        Rent Given     Balance Rent      Total rent    Total Bill\n"
		 << "========================================================================================\n";

	 while (sqlite3_step(stmt) == SQLITE_ROW) {
		 int id = sqlite3_column_int(stmt, 0);
		 const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		 const char* month = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
		 double rentGiven = sqlite3_column_double(stmt, 3);
		 double balanceRent = sqlite3_column_double(stmt, 4);
		 double TotalRent= sqlite3_column_double(stmt, 5);
		double Ebill= sqlite3_column_double(stmt, 6);
		
		
		 std::cout <<left<< setw(4)<< id << setw(10 )<< name << setw(15) << month << setw(15) << rentGiven << setw(17) << balanceRent << setw(16) <<TotalRent<< setw(19) <<Ebill << std::endl;
	 }


	 sqlite3_finalize(stmt);
	
 }


  void Sqllite::Search(const char* value)
  {


	  const char* selectAll = "SELECT * FROM MyTable;";
	  sqlite3_stmt* stmt;
	  rc = sqlite3_prepare_v2(db, selectAll, -1, &stmt, 0);
	  if (rc != SQLITE_OK) {
		  std::cerr << "Failed to prepare the SELECT statement: " << sqlite3_errmsg(db) << std::endl;

		  return;
	  }


	  bool flag = false;
	  while (sqlite3_step(stmt) == SQLITE_ROW) {

		  const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		  if (strcmp(name,value)==0)
		  {
			  if (!flag)
			  {
				  std::cout << "========================================================================================\n"
					  << "ID  NAME      Month        Rent Given     Balance Rent      Total rent    Total Bill\n"
					  << "========================================================================================\n";
				  flag = true;
			  }
			  
			  int id = sqlite3_column_int(stmt, 0);

			  const char* month = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
			  double rentGiven = sqlite3_column_double(stmt, 3);
			  double balanceRent = sqlite3_column_double(stmt, 4);
			  double TotalRent = sqlite3_column_double(stmt, 5);
			  double Ebill = sqlite3_column_double(stmt, 6);
			  std::cout << left << setw(4) << id << setw(10) << name << setw(15) << month << setw(15) << rentGiven << setw(17) << balanceRent << setw(16) << TotalRent << setw(19) << Ebill << std::endl;
		  }
		 
		  


		 
	  }


	  sqlite3_finalize(stmt);
	  

  }

  void Sqllite::Delete() {
	

	  const char* del = "DELETE FROM MyTable WHERE ID = ? AND Name = ?;";

	  sqlite3_stmt* stmt;
	  rc = sqlite3_prepare_v2(db, del, -1, &stmt, 0);

	  if (rc == SQLITE_OK) {
		  int id;
		  cout << "Enter ID to delete: ";
		  cin >> id;

		  cin.ignore();
		  string nam;
		  cout << "Enter name to delete: ";
		  getline(cin, nam);
		  const char* name = nam.c_str();

		  rc = sqlite3_bind_int(stmt, 1, id);
		  int rc1 = sqlite3_bind_text(stmt, 2, name, -1, SQLITE_STATIC);

		  if (rc != SQLITE_OK || rc1 != SQLITE_OK) {
			  cerr << "Error in binding ID or name to the DELETE statement." << endl;
		  }

		  rc = sqlite3_step(stmt);

		  if (rc == SQLITE_DONE) {
			  cout << "Row deleted successfully." << endl;
		  }
		  else {
			  std::cerr << "Error executing DELETE query: " << sqlite3_errmsg(db) << std::endl;
		  }

		  sqlite3_finalize(stmt);
	  }
	  else {
		  cerr << "Failed to prepare the DELETE statement." << endl;
	  }

	  
  }


  int Sqllite::getidcount()
  {
	  // Check if the CountTable exists, and if not, create it
	  const char* createCountTable = "CREATE TABLE IF NOT EXISTS CountTable(ID INT);";
	  int rc = sqlite3_exec(db, createCountTable, 0, 0, 0);

	  if (rc != SQLITE_OK) {
		  std::cerr << "Error creating CountTable: " << sqlite3_errmsg(db) << std::endl;
		  return -1; // Return an error code
	  }

	  int id = 0;

	  // Fetch the current ID count
	  const char* selectCount = "SELECT ID FROM CountTable;";
	  sqlite3_stmt* selectStmt;
	  rc = sqlite3_prepare_v2(db, selectCount, -1, &selectStmt, 0);

	  if (rc == SQLITE_OK) {
		  if (sqlite3_step(selectStmt) == SQLITE_ROW) {
			  id = sqlite3_column_int(selectStmt, 0);
		  }
		  else {
			  std::cerr << "No rows found in CountTable. Inserting a new row." << std::endl;
			  // Insert a new row with ID = 1
			  const char* insertCount = "INSERT INTO CountTable (ID) VALUES (1);";
			  rc = sqlite3_exec(db, insertCount, 0, 0, 0);
			  if (rc != SQLITE_OK) {
				  std::cerr << "Error inserting a new row into CountTable: " << sqlite3_errmsg(db) << std::endl;
				  return -1; // Return an error code
			  }
		  }
		  sqlite3_finalize(selectStmt);
	  }
	  else {
		  std::cerr << "Error fetching ID from CountTable: " << sqlite3_errmsg(db) << std::endl;
	  }

	  // Increment the ID count
	  id++;

	  // Update the CountTable with the new ID count
	  const char* updateCount = "UPDATE CountTable SET ID = ?;";
	  sqlite3_stmt* updateStmt;
	  rc = sqlite3_prepare_v2(db, updateCount, -1, &updateStmt, 0);

	  if (rc == SQLITE_OK) {
		  sqlite3_bind_int(updateStmt, 1, id);

		  if (sqlite3_step(updateStmt) != SQLITE_DONE) {
			  std::cerr << "Error updating ID in CountTable: " << sqlite3_errmsg(db) << std::endl;
		  }

		  sqlite3_finalize(updateStmt);
	  }
	  else {
		  std::cerr << "Error preparing update statement: " << sqlite3_errmsg(db) << std::endl;
	  }

	  return id;
  }



  Sqllite::Sqllite() {
	  rc = sqlite3_open(Filename.c_str(), &db);
	  if (rc != SQLITE_OK) {
		  std::cerr << "Error opening the database file: " << sqlite3_errmsg(db) << std::endl;
		  // Handle the error, e.g., throw an exception or exit the program.
	  }
  }

  Sqllite::~Sqllite() {
	  sqlite3_close(db);
  }