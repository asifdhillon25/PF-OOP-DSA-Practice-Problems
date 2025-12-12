#ifndef CHECKING
#define CHECKING


#include <iostream>
#include <string>

#include "bank.cpp"

using namespace std;

class ChekingAccount:public BankAccount
{
    float InterestRate;
    float MinimumBalance;


public:

    ChekingAccount():BankAccount()
    {
        SetInterestRAte();
        SetMinimumBalance();
    }

    void SetInterestRAte(){

        cout<<"Enter interest Rate\n";
        cin>>InterestRate;
    }

    float GetInterestRate()
    {
        return InterestRate;
    }

    void SetMinimumBalance(){

        cout<<"Enter amount for minimum Balance\n";
        cin>>MinimumBalance;
    }

    float GetMinimumBalance()
    {
        return MinimumBalance;
    }

void writecheck()
{
        cout<<"Enter the account holder name\n";
        string Name;
        cin>>Name;
        cout<<"Enter the Account holder no\n";
        int acno;cin>>acno;
        cout<<"Enter the amount you want to send  your balance: " << GEtBalance() << endl;
        float amount;
        cin>>amount;
        if(amount<0 || amount>GEtBalance())
        {
            cout<<"Invalid Amount\n";
        }
        else
        {
            GEtBalance()-=amount;
            cout<<"Check has been written on the name of "<<Name<<endl;
        }


}

void Postinterestc()
{
        float postinterest;
        postinterest=(GEtBalance()/100)*GetInterestRate();
        GEtBalance()+=postinterest;
        cout<<"Post interst with Amount "<<postinterest<<" have been Added in your Account\n";
}


void PrintInfoc(){

        cout<<"   ***Account Holder Info***\n";
        Printinfo();
        cout<<"Interest Rate: "<<GetInterestRate()<<endl;
        cout<<"Minimum Balance: "<<GetMinimumBalance()<<endl;
    }

};


#endif
