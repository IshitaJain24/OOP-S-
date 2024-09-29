#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    // Default Constructor
    Student() {
        name = "";
        rollNumber = 0;
        marks = 0.0;
    }

    // Parameterized Constructor
    Student(string n, int r, float m) {
        name = n;
        rollNumber = r;
        marks = m;
    }

    // Copy Constructor
    Student(const Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        marks = s.marks;
    }

    // Function to display student info
    void displayInfo() const {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << ", Marks: " << marks << endl;
    }
};

// Main function to demonstrate constructors
int main() {
    // Using Default Constructor
    Student student1;
    cout << "Student 1 (Default Constructor):" << endl;
    student1.displayInfo();

    // Using Parameterized Constructor
    Student student2("John Doe", 101, 85.5);
    cout << "\nStudent 2 (Parameterized Constructor):" << endl;
    student2.displayInfo();

    // Using Copy Constructor
    Student student3 = student2;
    cout << "\nStudent 3 (Copy Constructor, Copy of Student 2):" << endl;
    student3.displayInfo();

    return 0;
}

