#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    static int totalAccounts;  
    static const float MIN_HIGH_VALUE; 
    int accountNumber;  
    float balance;  
public:
    BankAccount(float initialBalance) {
        accountNumber = ++totalAccounts;  
        balance = initialBalance;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "$" << amount << " deposited successfully.\n";
        } else {
            cout << "Deposit amount must be positive.\n";
        }
    }

    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "$" << amount << " withdrawn successfully.\n";
        } else {
            cout << "Insufficient balance or invalid withdrawal amount.\n";
        }
    }

    void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    bool isHighValueAccount() const {
        return balance >= MIN_HIGH_VALUE;
    }
};

int BankAccount::totalAccounts = 0;
const float BankAccount::MIN_HIGH_VALUE = 1000.0f;

class Bank {
private:
    vector<BankAccount> accounts;  

public:
    void addAccount(float initialBalance) {
        accounts.push_back(BankAccount(initialBalance));
    }

    void displayAllAccounts() const {
        cout << "\nAll Accounts:\n";
        for (const auto& account : accounts) {
            account.display();
        }
    }

    void displayHighValueAccounts() const {
        cout << "\nHigh-Value Accounts:\n";
        bool found = false;
        for (const auto& account : accounts) {
            if (account.isHighValueAccount()) {
                account.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No high-value accounts found.\n";
        }
    }

    void displayTotalAccounts() const {
        cout << "\nTotal number of accounts created: " << BankAccount::getTotalAccounts() << endl;
    }
};

int main() {
    Bank bank;

    bank.addAccount(1500.00f); 
    bank.addAccount(500.00f);  
    bank.addAccount(1200.00f); 
    bank.addAccount(800.00f);  
    bank.addAccount(2000.00f);  

    bank.displayAllAccounts();  
    bank.displayHighValueAccounts();

    bank.displayTotalAccounts();

    return 0;
}