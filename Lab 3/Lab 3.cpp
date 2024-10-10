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
    Person() : lastName(""), firstName(""), middleName(""), gender("��������"), birthYear(0) {}
    Person(string ln, string fn, string mn, string g, int by) : lastName(ln), firstName(fn), middleName(mn), gender(g), birthYear(by) {
        if (by < 1900 || by > 2024) {
            throw invalid_argument("Invalid birth year");
        }
    }

    friend istream& operator>>(istream& is, Person& p) {
        cout << "������ �������: ";
        is >> p.lastName;
        cout << "������ ��'�: ";
        is >> p.firstName;
        cout << "������ �� �������: ";
        is >> p.middleName;
        cout << "������ ������: ";
        is >> p.gender;
        cout << "������ �� ����������: ";
        is >> p.birthYear;

        if (p.birthYear < 1900 || p.birthYear > 2024) {
            throw invalid_argument("������� ���� ����������");
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "�������: " << p.lastName << "\n"
            << "��'�: " << p.firstName << "\n"
            << "�� �������: " << p.middleName << "\n"
            << "������: " << p.gender << "\n"
            << "г� ����������: " << p.birthYear;
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
        cout << "\n����������:\n" << person;

        string searchLastName;
        cout << "\n������ ������� ��� ������: ";
        cin >> searchLastName;

        if (person.searchByLastName(searchLastName)) {
            cout << "\n������� �������� �� �������� '" << searchLastName << "'.";
        }
        else {
            cout << "\n������� �� �������� �� �������� '" << searchLastName << "'.";
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
