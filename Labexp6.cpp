#include<iostream>
#include<string>
using namespace std;

class Patient {
public:
    string name;
    int age;
    string disease;
    int room_number;

    void getDetails() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Disease: ";
        cin >> disease;
        cout << "Enter Room Number: ";
        cin >> room_number;
    }

    void showDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Disease: " << disease << endl;
        cout << "Room Number: " << room_number << endl;
    }
};

class Hospital {
private:
    Patient** patients;
    int patientCount;
    int capacity;

public:
    Hospital(int cap) {
        capacity = cap;
        patients = new Patient*[capacity]; 
        patientCount = 0;
    }

    void addPatient() {
        if (patientCount < capacity) {
            patients[patientCount] = new Patient; 
            cout << "\nEnter details for new patient " << patientCount + 1 << endl;
            patients[patientCount]->getDetails();
            patientCount++;
        } else {
            cout << "Hospital is at full capacity!" << endl;
        }
    }

    void displayAllPatients() {
        if (patientCount == 0) {
            cout << "No patients to display." << endl;
        } else {
            cout << "\nList of all patients:\n";
            for (int i = 0; i < patientCount; i++) {
                cout << "\nPatient " << i + 1 << ":\n";
                patients[i]->showDetails();
            }
        }
    }

    void searchPatientByName() {
        string searchName;
        cout << "Enter name of the patient to search: ";
        cin >> searchName;
        bool found = false;

        for (int i = 0; i < patientCount; i++) {
            if (patients[i]->name == searchName) {
                cout << "\nPatient found:\n";
                patients[i]->showDetails();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Patient not found!" << endl;
        }
    }

    void deletePatient() {
        string deleteName;
        cout << "Enter name of the patient to delete: ";
        cin >> deleteName;
        bool found = false;

        for (int i = 0; i < patientCount; i++) {
            if (patients[i]->name == deleteName) {
                delete patients[i]; 
                for (int j = i; j < patientCount - 1; j++) {
                    patients[j] = patients[j + 1]; 
                }
                patientCount--;
                cout << "Patient " << deleteName << " deleted successfully." << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Patient not found!" << endl;
        }
    }

    void exitHospital() {
        cout << "Exiting the system..." << endl;
    }

    Hospital() {
        for (int i = 0; i < patientCount; i++) {
            delete patients[i]; 
        }
        delete[] patients; 
        }
};

int main() {
    int capacity;
    cout << "Enter the maximum number of patients the hospital can handle: ";
    cin >> capacity;

    Hospital hospital(capacity);

    int choice;
    while (true) {
        cout << "\n1. Add New Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Search Patient by Name\n";
        cout << "4. Delete Patient\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hospital.addPatient();
                break;
            case 2:
                hospital.displayAllPatients();
                break;
            case 3:
                hospital.searchPatientByName();
                break;
            case 4:
                hospital.deletePatient();
                break;
            case 5:
                hospital.exitHospital();
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
