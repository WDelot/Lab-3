#include <iostream>
#include <string>
#include <stdexcept>
#include <Windows.h>
using namespace std;

class Person {
private:
    string lastName;
    string firstName;
    string middleName;
    string gender; 
    int birthYear;

public:
    Person() : lastName(""), firstName(""), middleName(""), gender("невідомий"), birthYear(0) {}
    Person(string ln, string fn, string mn, string g, int by) : lastName(ln), firstName(fn), middleName(mn), gender(g), birthYear(by) {
        if (by < 1900 || by > 2024) {
            throw invalid_argument("Invalid birth year");
        }
    }

    friend istream& operator>>(istream& is, Person& p) {
        cout << "Введіть прізвище: ";
        is >> p.lastName;
        cout << "Введіть ім'я: ";
        is >> p.firstName;
        cout << "Введіть по батькові: ";
        is >> p.middleName;
        cout << "Введіть гендер: ";
        is >> p.gender;
        cout << "Введіть рік народження: ";
        is >> p.birthYear;

        if (p.birthYear < 1900 || p.birthYear > 2024) {
            throw invalid_argument("Помилка року народження");
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "Прізвище: " << p.lastName << "\n"
            << "Ім'я: " << p.firstName << "\n"
            << "По батькові: " << p.middleName << "\n"
            << "Гендер: " << p.gender << "\n"
            << "Рік народження: " << p.birthYear;
        return os;
    }

    bool searchByLastName(const string& ln) const {
        return lastName == ln;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        Person person;
        cin >> person;
        cout << "\nІнформація:\n" << person;

        string searchLastName;
        cout << "\nВведіть прізвище для пошуку: ";
        cin >> searchLastName;

        if (person.searchByLastName(searchLastName)) {
            cout << "\nПерсону знайдено за прізвищем '" << searchLastName << "'.";
        }
        else {
            cout << "\nПерсону не знайдено за прізвищем '" << searchLastName << "'.";
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
