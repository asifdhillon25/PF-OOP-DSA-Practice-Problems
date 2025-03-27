#pragma once
class Customer {
public:
    // Getter functions
    int getID() const {
        return ID;
    }

    int getCustomerScreen() const {
        return ScreenNO;
    }

    void SetCustomerScreen(int scrNO)  {
        ScreenNO = scrNO;
    }

    int getSeatno() const {
        return Seatno;
    }

    // Setter functions
    void setID(int newID) {
        ID = newID;
    }

    void setSeatno(int newSeatno) {
        Seatno = newSeatno;
    }

private:
    int ID;
    int ScreenNO;
    int Seatno;
};


