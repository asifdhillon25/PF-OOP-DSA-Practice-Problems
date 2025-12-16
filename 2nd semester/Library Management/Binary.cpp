#include <iostream>
#include <fstream>
using namespace std;
#include "Librarian.h"

#include "Binary.h"

void Binary::writeToFile() {

    Librarian obj;
    fstream Datafile;
    Datafile.open("LibraryData.dat",ios::out|ios::binary|ios::app);
    if(!Datafile)
    {
        cout<<"Error! File not open "<<endl;
        return;
    }
    obj.writeDAta();
    Datafile.write(reinterpret_cast<char*>(&obj),sizeof(obj));
    Datafile.close();
    cout<<"Data has been stored"<<endl;
}

 void Binary::ReadFromFile(int stID) {

    bool flag=false;
    Librarian obj;
    fstream Datafile;
    Datafile.open("LibraryData.dat",ios::in|ios::binary);
    if(!Datafile)
    {
        cout<<"Error! File not open "<<endl;
        return;
    }


    while (Datafile.read(reinterpret_cast<char*>(&obj),sizeof(obj)))
    {
        if(obj.GetStudentId()==stID)
        {
            obj.ShowData();
            flag=true;
        }
    }
    if(!flag)
    {
        cout<<"No Data with this ID"<<endl;
    }
    Datafile.close();


}

void Binary::ModifyFile(int stID) {

    bool flag=false;
    Librarian obj;
    fstream Datafile;
    Datafile.open("LibraryData.dat",ios::in|ios::out|ios::binary);
    if(!Datafile)
    {
        cout<<"Error! File not open "<<endl;
        return;
    }


    while (Datafile.eof(), !flag)
    {
        Datafile.read(reinterpret_cast<char*>(&obj),sizeof(obj));

        if(obj.GetStudentId()==stID)
        {
            obj.ShowData();
            cout<<"Enter new Data"<<endl;
            obj.Modify();
            int pos=(-1)*static_cast<int>(sizeof(obj));
            Datafile.seekp(pos,ios::cur);
            Datafile.write(reinterpret_cast<char*>(&obj),sizeof(obj));
            flag=true;
        }
    }
    if(!flag)
    {
        cout<<"No Data with this ID"<<endl;
    }
    Datafile.close();

}

void Binary::ShowAllFromFile() {

    Librarian obj;
    ifstream Datafile;
    Datafile.open("LibraryData.dat",ios::binary);
    if(!Datafile)
    {
        cout<<"Error! File not open "<<endl;
        return;
    }

    cout<<"StudentName"<<"     "<<"BookName"<<"                "<<"StudentId"
        <<"  "<< "DateIssued"<<endl;
    while ( Datafile.read(reinterpret_cast<char*>(&obj),sizeof(obj))) {
        obj.showAll();
    }
    Datafile.close();
}

void Binary::DeleteAccount(int stID) {

    Librarian obj;
    ifstream Datafile;
    ofstream TempFile;

    TempFile.open("Temp.dat",ios::binary);
    Datafile.open("LibraryData.dat",ios::binary);
    if(!Datafile || !TempFile)
    {
        cout<<"Error! File not open "<<endl;
        return;
    }
    Datafile.seekg(0,ios::beg);

    while ( Datafile.read(reinterpret_cast<char*>(&obj),sizeof(obj))) {

        if(stID==obj.GetStudentId())
        {
            obj.ShowData();
        }
        if(stID!=obj.GetStudentId())
        {
            TempFile.write(reinterpret_cast<char*>(&obj),sizeof(obj));
        }
    }
    Datafile.close();
    TempFile.close();

    remove("LibraryData.dat");
    rename("Temp.dat","LibraryData.dat");
    cout<<"\nThis record has been Deleted\n";
}
