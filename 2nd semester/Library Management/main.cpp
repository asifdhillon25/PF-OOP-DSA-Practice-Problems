#include <iostream>
using namespace std;
#include "Binary.h"



void end();
int main() {

    Binary obj;
    char choice;
do{
    system("cls");
    cout << "\n\n\t  Main Menu\n\n";
    cout << "\t1: Add Student Data\n\n"
         << "\t2: Modify student Data\n\n"
         << "\t3: Show Student Data\n\n"
         << "\t4: Show All Students Data\n\n"
         << "\t5: Delete Record\n\n"
         << "\t6: Exit\n";


    cout<<"\n\tEnter your choice\n";
    cin>>choice;
    system("cls");

    switch(choice) {
        case '1':
            obj.writeToFile();
            break;
        case '2':
            cout << "Enter Id of Student\n";
            int id;
            cin >> id;
            obj.ModifyFile(id);
            break;
        case '3':
            cout << "Enter Id of Student\n";
            int id2;
            cin >> id2;
            obj.ReadFromFile(id2);
            break;
        case '4':
            obj.ShowAllFromFile();
            break;
        case '5':
            cout << "Enter Id of Student\n";
            int id3;
            cin >> id3;
            obj.DeleteAccount(id3);
            break;
        case '6':
            end();
            break;
        default :
            cout << "\a";
    }
    cin.ignore();
    cin.get();
} while (choice!='6');








}

    void end(){

        cout<<"Thanks for using my code\n"
            <<"Made by Muhammad Asif\n"
            <<"f2022266062\n";


    }
