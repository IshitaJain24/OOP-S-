#include<iostream>
using namespace std;

class Electricity {
private:
    string name;
    int units;
    float bill;

public:
    void getDetails() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Units Consumed: ";
        cin >> units;
    }

    void calculateBill() {
        if (units >= 0 && units <= 100) {
            bill = units * 1.5;
        } else if (units > 100 && units <= 200) {
            bill = units * 2;
        } else if (units > 200 && units <= 300) {
            bill = units * 3;
        } else {
            bill = units * 3; 
        }
    }

    void showBill() {
        cout << "\nElectricity Bill Details\n";
        cout << "Name: " << name << endl;
        cout << "Units Consumed: " << units << endl;
        cout << "Total Bill: Rs " << bill << endl;
    }
};

int main() {
    Electricity person;
    person.getDetails();
    person.calculateBill();
    person.showBill();
    return 0;
}
