#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string n, int id, double sal) : name(n), employeeID(id), salary(sal) {}

    virtual double calculateMonthlyPay() {
        return salary;
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Monthly Pay: " << calculateMonthlyPay() << endl;
    }
};

class Professor : public Employee {
private:
    string department;

public:
    Professor(string n, int id, double sal, string dept) : Employee(n, id, sal), department(dept) {}

    double calculateMonthlyPay() override {
        return salary + (0.10 * salary);
    }

    void displayInfo() {
        Employee::displayInfo();
        cout << "Department: " << department << endl;
    }
};

class AdminStaff : public Employee {
private:
    string position;

public:
    AdminStaff(string n, int id, double sal, string pos) : Employee(n, id, sal), position(pos) {}

    double calculateMonthlyPay() override {
        return salary + (0.05 * salary);
    }

    void displayInfo() {
        Employee::displayInfo();
        cout << "Position: " << position << endl;
    }
};

class Janitor : public Employee {
private:
    int hoursWorked;

public:
    Janitor(string n, int id, int hours) : Employee(n, id, 0), hoursWorked(hours) {
        salary = hoursWorked * 500;
    }

    double calculateMonthlyPay() override {
        return salary;
    }

    void displayInfo() {
        Employee::displayInfo();
        cout << "Hours Worked: " << hoursWorked << endl;
    }
};

int main() {
    Professor prof("Dr. Smith", 101, 50000, "Computer Science");
    AdminStaff admin("Alice Brown", 102, 40000, "Secretary");
    Janitor janitor("John Doe", 103, 160);

    cout << "Professor Info:" << endl;
    prof.displayInfo();
    cout << endl;

    cout << "Admin Staff Info:" << endl;
    admin.displayInfo();
    cout << endl;

    cout << "Janitor Info:" << endl;
    janitor.displayInfo();
    cout << endl;

    return 0;
}
