#pragma once
class Binary {

    int MasterKey;
public:
    Binary();
    void ChangeMasterKey(int PreviousKey);
    int GetMasterkey();
    void CreateAccount();
    void ShowData(int ID);
    void ModifyCustomerData(int ID);
    void ShowAllFromFile(int MasterKey);
    void DeleteAccount(int ID);
    void AddDeposit(int ID);
    void Withdraw(int ID);
    bool checkSamekey(int ID);

};

