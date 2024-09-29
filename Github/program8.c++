#include <iostream>
using namespace std;

class BankAccount {
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string accountHolder, int accountNumber, double balance)
        : accountHolder(accountHolder), accountNumber(accountNumber), balance(balance) {}

    // Getters
    string getAccountHolder() const { return accountHolder; }
    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    // Friend function declaration
    friend void transferFunds(BankAccount &fromAccount, BankAccount &toAccount, double amount);
};

// Friend function definition
void transferFunds(BankAccount &fromAccount, BankAccount &toAccount, double amount) {
    if (fromAccount.getBalance() >= amount) {
        fromAccount.balance -= amount;
        toAccount.balance += amount;
    } else {
        cout << "Insufficient funds" << endl;
    }
}

int main() {
    // Create two bank accounts
    BankAccount account1("Ishita", 1234567890, 1000);
    BankAccount account2("Pranav", 1735478609, 900);

    // Transfer funds from account1 to account2
    transferFunds(account1, account2, 200);

    // Display updated balances
    cout << account1.getAccountHolder() << "'s balance: " << account1.getBalance() << endl;
    cout << account2.getAccountHolder() << "'s balance: " << account2.getBalance() << endl;

    return 0;
}