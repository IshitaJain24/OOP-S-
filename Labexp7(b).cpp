#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    const string aadharCard;
    const string panCard;
    string address;
    string contactNumber;

public:
    Person(string aadhar, string pan) : aadharCard(aadhar), panCard(pan) {}

    void setAddress(string addr) {
        address = addr;
    }

    void setContactNumber(string contact) {
        contactNumber = contact;
    }

    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    string getAadharCard() const {
        return aadharCard;
    }

    string getPanCard() const {
        return panCard;
    }

    string getAddress() const {
        return address;
    }

    string getContactNumber() const {
        return contactNumber;
    }
};

int main() {
    Person p1("1234-5678-9101", "ABCDE1234F");

    p1.setName("Ishita");
    p1.setAddress("123 , Jaipur");
    p1.setContactNumber("9876556398");

    cout << "Name: " << p1.getName() << endl;
    cout << "Aadhar Card: " << p1.getAadharCard() << endl;
    cout << "PAN Card: " << p1.getPanCard() << endl;
    cout << "Address: " << p1.getAddress() << endl;
    cout << "Contact Number: " << p1.getContactNumber() << endl;

    return 0;
}
