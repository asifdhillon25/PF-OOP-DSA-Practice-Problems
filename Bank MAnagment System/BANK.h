#pragma once
class BANK {

    char CustomerName[20];
    double Balance;
    int Pincode;
public:
    BANK();
    bool CreateAccount();
    void ShowData();
    int GetcustomerId()const;
    void Modify();
    void showAll();
    void AddDeposit();
    void Withdraw();

};