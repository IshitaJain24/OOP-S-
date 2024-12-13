#include <iostream>
#include <exception>
using namespace std;

class InsufficientFundException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient funds for withdrawal";
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundException();
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(1000);

    try {
        double w;
        cout << "Enter balance to withdraw: ";
        cin >> w;
        account.deposit(500);
        account.withdraw(w);
    } catch (const InsufficientFundException& e) {
        cout << e.what() << endl;
    }

    cout << "Current balance: " << account.getBalance() << endl;

    return 0;
}
