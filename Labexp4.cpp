#include<iostream>
using namespace std;

struct Student {
    int roll_no;
    string name;
    float marks;
};

int main() {
    Student students[10];

    for(int i = 0; i < 10; i++) {
        cout << "Enter details for student " << i + 1 << endl;
        cout << "Roll Number: ";
        cin >> students[i].roll_no;
        cin.ignore();
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Marks: ";
        cin >> students[i].marks;
        cout << endl;
    }

    cout << "\nStudent Details:\n";
    for(int i = 0; i < 10; i++) {
        cout << "Student " << i + 1 << ": " << endl;
        cout << "Roll Number: " << students[i].roll_no << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Marks: " << students[i].marks << endl << endl;
    }

    return 0;
}
