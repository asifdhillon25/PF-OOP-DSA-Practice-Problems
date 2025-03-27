#pragma once
#include <iostream>
using namespace std;
#include <string> // Include the <string> header for string usage

class Movies {
public:
    Movies(int iD,string movieName);
    // Getter functions
    int getID() const {
        return ID;
    }

    std::string getMovieTitle() const {
        return MovieTitle;
    }

    // Setter functions
    void setID(int newID) {
        ID = newID;
    }

    void setMovieTitle(const std::string& newMovieTitle) {
        MovieTitle = newMovieTitle;
    }

private:
    int ID;
    std::string MovieTitle;
};


