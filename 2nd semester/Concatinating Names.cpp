#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;

public:
    Person(const string& n) : name(n) {}

    string getName() const {
        return name;
    }

    Person operator+(const Person& other) {
        string concatenatedName = name + other.name;
        return Person(concatenatedName);
    }

    bool operator==(const Person& other) {
        return (name == other.name);
    }
};

int main() {
    string name1, name2;

    cout << "Enter the first name: ";
    getline(cin, name1);

    cout << "Enter the second name: ";
    getline(cin, name2);

    Person person1(name1);
    Person person2(name2);

    Person concatPerson = person1 + person2;

    cout << "Concatenated name: " << concatPerson.getName() << endl;

    if (person1 == person2) {
        cout << "Both persons have the same name." << endl;
    } else {
        cout << "Both persons have different names." << endl;
    }

}

