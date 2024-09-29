
#include <iostream>

using namespace std;

class Bank {
	string name;
	char acc_type;
	float balance;

public:
	void open_account();
	void deposit_money();
	void withdraw_money();
	void display_account();
};

void Bank::open_account()
{
	name = "ABC";
	cout << "Enter your full name: "
		<< name << endl;
	
	acc_type = 'S';
	cout << "What type of account you want"
		<< " to open saving(S) or Current(C): "
		<< acc_type << endl;
	balance = 5000;
	cout << "Enter How much money you want to deposit: "
		<< balance << endl;
	cout << "Account Created Successfully";
}

void Bank::deposit_money()
{
	int Amount;
	Amount = 1000;
	cout << "Enter how much money"
		<< " you want to deposit: "
		<< Amount << endl;
	balance += Amount;
	cout << "\n Available Balance: "
		<< balance;
}

void Bank::display_account()
{
	cout << "Name: " << name << endl 
		<< "Type: " << acc_type << endl
		<< "Balance: " << balance << endl
		<< endl;
}

void Bank::withdraw_money()
{
	float amount;
	amount = 1000;
	cout << "Enter how much money "
		<< "you want to withdraw: "
		<< amount << endl;
	balance -= amount;
	cout << "\n Available balance: "
		<< balance;
}


int main()
{
	int choice;


	Bank customer;

	cout << "\n1) Open account \n\n";
	customer.open_account();
	cout << "\n------------------------"
		<< "-------------------------\n";

	cout << "\n2) Deposit account \n\n";
	customer.deposit_money();
	cout << "\n------------------------"
		<< "-------------------------\n";

	cout << "\n2) Withdraw money \n\n";
	customer.withdraw_money();
	cout << "\n------------------------"
		<< "-------------------------\n";

	cout << "\n4) Display Account \n\n";
	
	customer.display_account();
	cout << "\n------------------------"
		<< "-------------------------\n";

	return 0;
}