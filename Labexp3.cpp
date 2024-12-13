#include<iostream>
#include<string>
using namespace std;

class Bank {
private:
    int account_number;
    string name;
    float balance;

public:
    Bank() {
        account_number = 0;
        name = "";
        balance = 0.0;
    }

    void openAccount() {
        cout << "Enter Account Number: ";
        cin >> account_number;
        cout << "Enter Name: ";
        getline(cin, name);
        balance = 0;
        cout << "Account created successfully with Account Number " << account_number << endl;
    }

    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
        }
    }

    void showAccount() {
        cout << "\nAccount Details:\n";
        cout << "Account Number: " << account_number << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposit() {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }
};

int main() {
    Bank acc;
    int choice;
    bool accountOpened = false;

    while (true) {
        cout << "\nBanking Management System\n";
        cout << "1. Open Account\n";
        cout << "2. Withdraw\n";
        cout << "3. Show Account\n";
        cout << "4. Deposit\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                acc.openAccount();
                accountOpened = true;
                break;
            case 2:
                if (accountOpened) {
                    acc.withdraw();
                } else {
                    cout << "No account found. Please open an account first.\n";
                }
                break;
            case 3:
                if (accountOpened) {
                    acc.showAccount();
                } else {
                    cout << "No account found. Please open an account first.\n";
                }
                break;
            case 4:
                if (accountOpened) {
                    acc.deposit();
                } else {
                    cout << "No account found. Please open an account first.\n";
                }
                break;
            case 5:
                cout << "Exiting system...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
