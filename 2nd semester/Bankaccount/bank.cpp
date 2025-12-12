#ifndef BANK
#define BANK


#include <iostream>
using namespace std;


class BankAccount {


    int AccountNo;
    double Balance=0;

public:

    BankAccount()
    {
        FirstDeposit();
        setAccountNo();
    }

    void setAccountNo() {

        cout << "Enter an Account no : ";
        cin >> AccountNo;
    }

    int GetAccountNo() {

        return AccountNo;

    }


    void FirstDeposit() {

        cout << "To create account first deposit 500 or more : \n";
        double Amount;
        cin>>Amount;
        if (Amount>=500)
        {
            Balance+=Amount;
            cout<<"Congrats! your Account has been created successfully\n";
        }
        else{
            cout<<"Invalid Amount\n";
        }

    }

    double &GEtBalance() {
        return Balance;
    }

    void Withdraw() {

        cout << "Enter the amount yuo want to withdraw   your balance: " << GEtBalance() << endl;
        double Amount;
        cin >> Amount;


        if (Amount <= GEtBalance()) {
            GEtBalance() -= Amount;
            cout << "Your Amount Has been withdrawn\n";
        } else {
            cout << "Invalid Amount\n";
        }
    }

    void Deposit() {

        cout << "Enter the amount yuo want to Deposit   your balance: " << GEtBalance() << endl;
        double Amount;
        cin >> Amount;


        if (Amount > 0) {
            GEtBalance() += Amount;
            cout << "Your Amount Has been Deposited\n";
        } else {
            cout << "Invalid Amount\n";
        }
    }

    void Printinfo(){

        cout<<"Account no: "<<GetAccountNo()<<endl;
        cout<<"Balance  "<<GEtBalance()<<endl;
    }

};



#endif
