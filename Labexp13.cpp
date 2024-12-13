#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    Student() : name(" "), rollNumber(0), marks(0.0) {}

    Student(string n, int r, float m) : name(n), rollNumber(r), marks(m) {}

    Student(const Student &s) : name(s.name), rollNumber(s.rollNumber), marks(s.marks) {}

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student student1("edf",239,93);
    Student student2("abc", 101, 89);
   


    student1.displayInfo();
    cout << endl;

   
    student2.displayInfo();
    cout << endl;

    
    

    return 0;
}
