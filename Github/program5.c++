#include <iostream>
using namespace std;

// Patient class to store the patient's details
class Patient {
public:
    string name;
    int age;
    string disease;
    int roomNumber;

    // Constructor to initialize patient data
    Patient(string name, int age, string disease, int roomNumber) {
        this->name = name;
        this->age = age;
        this->disease = disease;
        this->roomNumber = roomNumber;
    }
};

// Hospital class to manage patient records
class Hospital {
private:
    Patient** patients;  // Dynamic array of pointers to Patient objects
    int numPatients;     // Count of current patients
    int capacity;        // Capacity of the patient array

    // Resize function to expand the capacity of the patient array when needed
    void resize() {
        capacity *= 2;
        Patient** newPatients = new Patient*[capacity];
        for (int i = 0; i < numPatients; i++) {
            newPatients[i] = patients[i];
        }
        delete[] patients;  // Free the old memory
        patients = newPatients;
    }

public:
    // Constructor to initialize the hospital with a given capacity
    Hospital(int capacity = 2) {
        this->capacity = capacity;
        numPatients = 0;
        patients = new Patient*[capacity];
    }

    // Destructor to free dynamically allocated memory
    ~Hospital() {
        for (int i = 0; i < numPatients; i++) {
            delete patients[i];  // Free each patient's memory
        }
        delete[] patients;  // Free the array of pointers
    }

    // Function to add a new patient to the hospital
    void addPatient(string name, int age, string disease, int roomNumber) {
        if (numPatients == capacity) {
            resize();  // Resize the array if full
        }
        patients[numPatients++] = new Patient(name, age, disease, roomNumber);
        cout << "Patient added successfully!\n";
    }

    // Function to display all patients in the hospital
    void displayPatients() {
        if (numPatients == 0) {
            cout << "No patients to display.\n";
            return;
        }
        cout << "\nDisplaying all patients:\n";
        for (int i = 0; i < numPatients; i++) {
            cout << "Patient " << i + 1 << ": \n";
            cout << "  Name: " << patients[i]->name << "\n";
            cout << "  Age: " << patients[i]->age << "\n";
            cout << "  Disease: " << patients[i]->disease << "\n";
            cout << "  Room Number: " << patients[i]->roomNumber << "\n";
        }
    }

    // Function to search for a patient by name
    void searchPatient(string name) {
        bool found = false;
        for (int i = 0; i < numPatients; i++) {
            if (patients[i]->name == name) {
                cout << "\nPatient found: \n";
                cout << "  Name: " << patients[i]->name << "\n";
                cout << "  Age: " << patients[i]->age << "\n";
                cout << "  Disease: " << patients[i]->disease << "\n";
                cout << "  Room Number: " << patients[i]->roomNumber << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Patient not found.\n";
        }
    }

    // Function to delete a patient by name
    void deletePatient(string name) {
        bool found = false;
        for (int i = 0; i < numPatients; i++) {
            if (patients[i]->name == name) {
                delete patients[i];  // Free the memory of the found patient
                for (int j = i; j < numPatients - 1; j++) {
                    patients[j] = patients[j + 1];  // Shift the remaining patients
                }
                numPatients--;
                found = true;
                cout << "Patient deleted successfully.\n";
                break;
            }
        }
        if (!found) {
            cout << "Patient not found.\n";
        }
    }
};

// Main function to run the hospital management system
int main() {
    Hospital hospital;

    int choice;
    string name;
    int age, roomNumber;
    string disease;

    do {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient by Name\n";
        cout << "4. Delete Patient by Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Add a new patient
                cout << "Enter patient name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter patient age: ";
                cin >> age;
                cout << "Enter disease: ";
                cin.ignore();
                getline(cin, disease);
                cout << "Enter room number: ";
                cin >> roomNumber;
                hospital.addPatient(name, age, disease, roomNumber);
                break;

            case 2:
                // Display all patients
                hospital.displayPatients();
                break;

            case 3:
                // Search for a patient by name
                cout << "Enter patient name to search: ";
                cin.ignore();
                getline(cin, name);
                hospital.searchPatient(name);
                break;

            case 4:
                // Delete a patient by name
                cout << "Enter patient name to delete: ";
                cin.ignore();
                getline(cin, name);
                hospital.deletePatient(name);
                break;

            case 5:
                // Exit
                cout << "Exiting the system...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
