#ifndef LIBRARY_MANAGEMENT_BINARY_H
#define LIBRARY_MANAGEMENT_BINARY_H



class Binary {

public:
    void writeToFile();
    void ReadFromFile(int stID);
    void ModifyFile(int stID);
    void ShowAllFromFile();
    void DeleteAccount(int stID);

};


#endif //LIBRARY_MANAGEMENT_BINARY_H
