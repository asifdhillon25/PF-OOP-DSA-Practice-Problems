#ifndef SAVING
#define SAVING

#include <iostream>
#include "bank.cpp"
using namespace std;

class SavingAccount:public BankAccount
{
    float InterestRate;

public:

    SavingAccount()
    {

        SetInterestRAte();
    }


    void SetInterestRAte(){

        cout<<"Enter interest Rate\n";
        cin>>InterestRate;
    }

    float GetInterestRate()
    {
        return InterestRate;
    }

    void Postinterests()
    {
        float postinterest;
        postinterest=(GEtBalance()/100)*GetInterestRate();
        GEtBalance()+=postinterest;
        cout<<"Post interst with Amount "<<postinterest<<" have been Added in your Account\n";
    }


    void PrintInfos(){

        cout<<"   ***Account Holder Info***\n";
        Printinfo();
        cout<<"Interest Rate: "<<GetInterestRate()<<endl;

    }
};

#endif //SAVING