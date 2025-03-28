#include <iostream>
#include <string>
#include <sstream> 
#include <iomanip>
#include <cstdlib>//For using system("cls") to clear screen;

using namespace std;
string to_string(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}
class Seats
{
public:

    int seat[5][10], movie_count, num[100], count, col[100], numAdult[100], numstudent[100], numchild[100], ticketType[100], numTickets[100];
    string n[10], d[10], g[10], t[10], name[100], m_name[100], movie_timing[10], movie_duration[10];
    char row[100];

    Seats()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                seat[i][j] = 1;
            }
        }

        // Initialize with 3 movies
        n[0] = "Avengers: Endgame";
        g[0] = "Action/Sci-Fi";
        d[0] = "Anthony and Joe Russo";
        t[0] = "3 hours 2 mins";

        n[1] = "Batman Begins";
        g[1] = "Action/Adventure";
        d[1] = "Christopher Nolan";
        t[1] = "2 hours 20 mins";

        n[2] = "Demon Slayer: Mugen Train";
        g[2] = "Animation/Action";
        d[2] = "Haruo Sotozaki";
        t[2] = "1 hour 57 mins";
        movie_duration[0] = "3 hours 2 mins";
        movie_timing[0] = "09:00";

        movie_duration[1] = "2 hours 20 mins";
        movie_timing[1] = "12:00";

        movie_duration[2] = "1 hour 57 mins";
        movie_timing[2] = "15:00";

        movie_count = 3;
        count = 0;
    }

    int get_seat_status(char row, int seatnum)
    {
        int rowIndex = row - 'A';
        if (rowIndex < 0 || rowIndex >= 5 || seatnum < 1 || seatnum > 10)
        {
            return -1;
        }
        return seat[rowIndex][seatnum - 1];
    }

    void display_seats()
    {
        // Set the width for each column to improve alignment
        cout << setw(3) << " ";
        for (int i = 0; i < 10; i++)
        {
            cout << setw(3) << i + 1;
        }
        cout << endl;

        // Set the width for row labels to improve alignment
        for (int row = 0; row < 5; row++)
        {
            cout << setw(3) << static_cast<char>('A' + row);
            for (int col = 0; col < 10; col++)
            {
                if (seat[row][col] == 0)
                {
                    cout << setw(3) << "X"; // Set width for seat status
                }
                else
                {
                    cout << setw(3) << "-"; // Set width for seat status
                }
            }
            cout << endl;
        }
    }
    void display_movies()
    {
        if (movie_count == 0)
        {
            cout << "No movies available" << endl;
        }
        else
        {
            int maxNameLength = 0, maxGenreLength = 0, maxDirectorLength = 0, maxDurationLength = 0;
            // Find the maximum length of each field for alignment
            for (int i = 0; i < movie_count; i++)
            {
                maxNameLength = max(maxNameLength, static_cast<int>(n[i].length()));
                maxGenreLength = max(maxGenreLength, static_cast<int>(g[i].length()));
                maxDirectorLength = max(maxDirectorLength, static_cast<int>(d[i].length()));
                maxDurationLength = max(maxDurationLength, static_cast<int>(movie_duration[i].length())); // Use movie_duration array
            }
            // Display movies with proper alignment
            for (int i = 0; i < movie_count; i++)
            {
                cout << "" << endl;
                cout << "| Movie Name       : " << setw(maxNameLength) << left << n[i] << endl;
                cout << "| Movie Genre      : " << setw(maxGenreLength) << left << g[i] << endl;
                cout << "| Movie Director   : " << setw(maxDirectorLength) << left << d[i] << endl;
                cout << "| Movie Duration   : " << setw(maxDurationLength) << left << movie_duration[i] << endl; // Use movie_duration array
                cout << "| Movie Timing     : " << setw(maxDurationLength) << left << movie_timing[i] << endl; // Use movie_timing array
            }
            cout << "" << endl;
        }
    }



    void reserve_seat()
    {
        char row;
        int seatnum;
        int numAdult, numStudent, numChildren;

        // Ask for the name and phone number only once
        string bookingName;
        int bookingPhone;
        cout << "Enter Your name :" << endl;
        cin.ignore(); // To ignore the leftover newline character from previous input
        getline(cin, bookingName);
        cout << "Enter your Phone number" << endl;
        cin >> bookingPhone;
        if (cin.fail())
        {
            cin.clear(); // Clearing error flags
            cin.ignore(); // Clearing input buffer
            cout << "Invalid input. Please enter a valid phone number." << endl;
            return;
        }

        cout << "Following are the available Movies :" << endl;
        for (int i = 0; i < movie_count; i++)
        {
            cout << i + 1 << ". " << n[i] << endl;
        }

        cout << "Enter the index of the movie you want to watch:" << endl;
        int movieIndex;
        cin >> movieIndex;
        movieIndex--; // Adjusting index to match array indexing

        if (movieIndex < 0 || movieIndex >= movie_count)
        {
            cout << "Invalid movie selection." << endl;
            return;
        }

        // Store the selected movie name
        m_name[count] = n[movieIndex];

        // Store the selected movie timing
        movie_timing[count] = movie_timing[movieIndex];

        // Store the selected movie duration
        movie_duration[count] = movie_duration[movieIndex];

        // Asking for the number of tickets
        cout << "Enter the number of Adult tickets you want: ";
        cin >> numAdult;
        cout << "Enter the number of Student tickets you want: ";
        cin >> numStudent;
        cout << "Enter the number of Children tickets you want: ";
        cin >> numChildren;

        int totalSeats = numAdult + numStudent + numChildren;

        cout << "Following are the available seats" << endl;
        display_seats();

        // Initialize ticketType array for current booking
        int startIndex = count;

        // Loop for the total number of seats
        for (int i = 0; i < totalSeats; i++)
        {
            cout << "Enter the Row (A-E) for seat " << i + 1 << ": ";
            cin >> row;
            cout << "Enter the seat number (1-10) for seat " << i + 1 << ": ";
            cin >> seatnum;

            int rowIndex = row - 'A';
            if (rowIndex < 0 || rowIndex >= 5 || seatnum < 1 || seatnum > 10)
            {
                cout << "Invalid seat selection." << endl;
                i--; // To retry the current iteration
                continue;
            }
            if (seat[rowIndex][seatnum - 1] == 0)
            {
                cout << "Seat already reserved." << endl;
                i--; // To retry the current iteration
            }
            else
            {
                seat[rowIndex][seatnum - 1] = 0;
                cout << "Seat reserved successfully.(" << row << "," << seatnum << ")" << endl;
                this->row[count] = row; // Storing row information
                col[count] = seatnum;   // Storing column information

                // Assign ticket type
                if (i < numAdult)
                    ticketType[count] = 1; // Adult
                else if (i < numAdult + numStudent)
                    ticketType[count] = 2; // Student
                else
                    ticketType[count] = 3; // Child

                // Associate the phone number and name with the booking
                name[count] = bookingName;
                num[count] = bookingPhone;

                count++;
            }
        }
        // Calculate the total price
        int totalPrice = (numAdult * 500) + (numStudent * 300) + (numChildren * 100);
        cout << "Total price for the tickets is: " << totalPrice << " rupees." << endl;
    }

    void display_bookings() {
        if (count == 0) {
            cout << "No Booking right now" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << "Name           : " << (name[i].empty() ? "" : name[i]) << endl;
            cout << "Phone Number   : " << (num[i] == 0 ? "" : to_string(num[i])) << endl;
            cout << "Movie          : " << (m_name[i].empty() ? "*" : m_name[i]) << endl;
            cout << "Seat Location  : " << row[i] << "-" << col[i] << endl;
            cout << "Ticket Type    : ";
            if (ticketType[i] == 1)
                cout << "Adult" << endl;
            else if (ticketType[i] == 2)
                cout << "Student" << endl;
            else
                cout << "Children" << endl;
            cout << endl;
        }
    }



    void add_new_movies()
    {
        string m_name, genre, d_name, duration;
        if (movie_count >= 10)
        {
            cout << "You have entered the maximum number of movies." << endl;
        }
        else
        {
            cout << "Enter the name of Movie: ";
            cin.ignore();
            getline(cin, m_name);
            n[movie_count] = m_name;

            cout << "Enter the genre of movie: ";
            getline(cin, genre);
            g[movie_count] = genre;

            cout << "Enter the name of director: ";
            getline(cin, d_name);
            d[movie_count] = d_name;

            cout << "Enter the duration of movie (2 hours 37 mins): ";
            getline(cin, duration);
            t[movie_count] = duration;

            movie_count++;
            cout << "Your movie \"" << m_name << "\" has been added successfully." << endl;
        }
    }



    int get_movie_count() {
        return movie_count;
    }

};
void delete_movie(Seats& s)
{
    if (s.movie_count <= 3) {
        cout << "Cannot delete preloaded movies." << endl;
        return;
    }

    cout << "Movies Available for Deletion:" << endl;
    for (int i = 3; i < s.movie_count; i++) {
        cout << i << ". " << s.n[i] << endl;
    }

    cout << "Enter the index of the movie you want to delete:" << endl;
    int index;
    cin >> index;

    if (index < 3 || index >= s.movie_count) {
        cout << "Invalid movie index." << endl;
        return;
    }

    // Shift elements to overwrite the deleted movie
    for (int i = index; i < s.movie_count - 1; i++) {
        s.n[i] = s.n[i + 1];
        s.g[i] = s.g[i + 1];
        s.d[i] = s.d[i + 1];
        s.t[i] = s.t[i + 1];
    }

    // Decrement movie count
    s.movie_count--;

    cout << "Movie deleted successfully." << endl;
}

void ticketprice()
{
    int n;
    cout << "Which Ticket Do you want? \n 1-Adult\n 2-Student\n 3-Children\n";
    cin >> n;
    if (n == 1)
    {
        cout << "The price of Adult ticket is 500" << endl;
    }
    else if (n == 2)
    {
        cout << "The price of Student ticket is 300" << endl;
    }
    else if (n == 3)
    {
        cout << "The price of Children ticket is 100" << endl;
    }
}

void show_timings(Seats& s)
{
    int movie_count = s.get_movie_count();
    cout << setw(30) << left << "Movie Name" << setw(15) << left << "Timings" << endl;
    for (int i = 0; i < movie_count; i++)
    {
        cout << setw(30) << left << s.n[i];
        for (int j = 0; j < 1; j++)
        {
            cout << setw(5) << "09:00 " << setw(5) << "12:00 " << setw(5) << "15:00 "; // Timings
            cout << endl;
        }
    }
}


int main()
{
    Seats s;
    int ch, t = 1;
    while (t != 0)
    {
        cout << "\n1-For Booking Tickets" << endl;
        cout << "\n2-For Adding New Movies" << endl;
        cout << "\n3-Showing All Available movies" << endl;
        cout << "\n4-Showing Your Bookings" << endl;
        cout << "\n5-Showing Price of tickets" << endl;
        cout << "\n6-Showing Movies Timings" << endl;
        cout << "\n7-Available Seats" << endl;
        cout << "\n8-Delete Movies" << endl;
        cout << "\n9-show bill" << endl;
        cout << "\n10-Exit" << endl;
        cin >> ch;
        if (ch == 1)
        {
            system("cls");
            s.reserve_seat();
        }
        else if (ch == 2)
        {
            system("cls");
            s.add_new_movies();
        }
        else if (ch == 3)
        {
            system("cls");
            s.display_movies();
        }
        else if (ch == 4)
        {
            system("cls");
            s.display_bookings();
        }
        else if (ch == 5)
        {
            system("cls");
            ticketprice();
        }
        else if (ch == 6)
        {
            system("cls");
            show_timings(s);
        }
        else if (ch == 7)
        {
            system("cls");
            s.display_seats();
            cout << endl;
        }
        else if (ch == 8)
        {
            system("cls");
            delete_movie(s);
        }

        else if (ch == 10)
        {
            t = 0;
        }
        else
        {
            system("cls");
            cout << "Invalid Input (1-9)" << endl;
        }
    }
    return 0;
}



























//
//
//#include <iostream>
//#include <vector>
//#include "Cinema.h"
//
//using namespace std;
//
//
//int main()
//{
//
//
//    Cinema cinema;
//    string choice;
//    do {
//        cinema.ShowMenu();
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (stoi(choice)) {
//        case 1: {
//            cinema.AddCustomer();
//            break;
//        }
//        case 2: {
//            cinema.ShowCustomer();
//            break;
//        }
//        case 3: {
//            string movieTitle;
//            cout << "Enter movie title: ";
//            cin.ignore(); // To ignore the newline character left by previous input
//            getline(cin, movieTitle);
//            cinema.AddNewMovie(movieTitle);
//            break;
//        }
//        case 4: {
//            cinema.RemoveMOvie();
//            break;
//        }
//        case 5: {
//            cinema.RemoveCustomer();
//            break;
//        }
//        case 6: {
//            cinema.SHowAvailableSeats();
//            break;
//        }
//        case 7: {
//            cinema.SetScreenMovie();
//            break;
//        }
//       
//        case 9: {
//            cout << "Exiting..." << endl;
//            break;
//        }
//       
//
//        default: {
//            cout << "Invalid choice. Please try again." << endl;
//        }
//
//               
//        }
//
//        system("pause");
//        system("cls");
//    } while (choice != "9");
//        
//    return 0;
//
//	
//
//	
//
//	
//
//
//
//}
//
