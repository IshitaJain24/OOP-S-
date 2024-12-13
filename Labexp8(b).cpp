#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    int year;
    double rentalPrice;

public:
    Vehicle(string b, string m, int y, double r) : brand(b), model(m), year(y), rentalPrice(r) {}

    virtual double getRentalCost(int days) {
        return rentalPrice * days;
    }

    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(string b, string m, int y, double r, int doors) : Vehicle(b, m, y, r), numberOfDoors(doors) {}

    double getRentalCost(int days) override {
        double cost = rentalPrice * days;
        if (days > 7) {
            cost *= 0.95; // 5% discount for rentals longer than 7 days
        }
        return cost;
    }

    void displayInfo() {
        Vehicle::displayInfo();
        cout << "Number of Doors: " << numberOfDoors << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    double engineDisplacement;

public:
    Motorcycle(string b, string m, int y, double r, double ed) : Vehicle(b, m, y, r), engineDisplacement(ed) {}

    double getRentalCost(int days) override {
        double cost = rentalPrice * days;
        if (days < 3) {
            cost *= 0.90; // 10% discount for rentals shorter than 3 days
        }
        return cost;
    }

    void displayInfo() {
        Vehicle::displayInfo();
        cout << "Engine Displacement: " << engineDisplacement << " cc" << endl;
    }
};

class Bicycle : public Motorcycle {
private:
    string wireFrameMaterial;

public:
    Bicycle(string b, string m, int y, double r, double ed, string material) : Motorcycle(b, m, y, r, ed), wireFrameMaterial(material) {}

    double getRentalCost(int days) override {
        return 200 * days; // Fixed rental price for Bicycle
    }

    void displayInfo() {
        Motorcycle::displayInfo();
        cout << "Wire Frame Material: " << wireFrameMaterial << endl;
    }
};

int main() {
    Car car("Honda", "City", 2020, 1000, 4);
    Motorcycle motorcycle("Yamaha", "FZ", 2019, 500, 150);
    Bicycle bicycle("Hero", "Sprint", 2023, 0, 0, "Aluminium");

    cout << "Car Rental Info:" << endl;
    car.displayInfo();
    cout << "Rental Cost for 10 days: " << car.getRentalCost(10) << endl;
    cout << endl;

    cout << "Motorcycle Rental Info:" << endl;
    motorcycle.displayInfo();
    cout << "Rental Cost for 2 days: " << motorcycle.getRentalCost(2) << endl;
    cout << endl;

    cout << "Bicycle Rental Info:" << endl;
    bicycle.displayInfo();
    cout << "Rental Cost for 5 days: " << bicycle.getRentalCost(5) << endl;

    return 0;
}
