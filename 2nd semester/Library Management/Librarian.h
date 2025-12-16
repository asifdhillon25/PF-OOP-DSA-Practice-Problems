#ifndef LIBRARY_MANAGEMENT_LIBRARIAN_H
#define LIBRARY_MANAGEMENT_LIBRARIAN_H



class Librarian {

    char StudentName[20];
    char BookName[50];
    char DateIssued[20];
    int StudentId;
public:

    void writeDAta();
    void ShowData();
    int GetStudentId()const;
    void Modify();
    void showAll();


};


#endif //LIBRARY_MANAGEMENT_LIBRARIAN_H
