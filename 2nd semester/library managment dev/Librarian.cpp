#include <iostream>
#include <iomanip>
#include "Librarian.h"
using namespace std;

void Librarian::writeDAta() {

    cin.ignore();
    cout<<"Enter Student Name"<<endl;
     cin.getline(StudentName,20);
    cout<<"Enter Student ID"<<endl;
    cin>>StudentId;
    cout<<"Enter Book Name"<<endl;
    cin.ignore(); cin.getline(BookName,50);
    cout<<"Enter Date Issued  (eg: 25 March 2023)"<<endl;
    cin.getline(DateIssued,20);

}

void Librarian::ShowData() {

    cout<<"Student Name: "<<StudentName<<endl;
    cout<<"Student Id: "<<StudentId<<endl;
    cout<<"Book Name: "<<BookName<<endl;
    cout<<"Date issued: "<<DateIssued<<endl;



}

int Librarian::GetStudentId() const{
    return StudentId;
}

void Librarian::Modify() {
    cout<<"\t***Enter New Data***"<<endl;
    cout<<"Enter New Name"<<endl;
    cin.getline(StudentName,20);
    cout<<"Enter New ID"<<endl;
    cin>>StudentId;
    cout<<"Enter Book Name"<<endl;
    cin.ignore(); cin.getline(BookName,50);
    cout<<"Enter Date Issued  (eg: 25 March 2023)"<<endl;
    cin.getline(DateIssued,20);
}

void Librarian::showAll() {


    cout << left << setw(15) << StudentName
         << setw(25) << BookName
         << setw(10) << StudentId
         << "  " << DateIssued << endl;

}
