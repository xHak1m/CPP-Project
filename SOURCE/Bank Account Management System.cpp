#include <iostream>
#include <string>

using namespace std;

// Base class: BankAccount
class BankAccount {
protected:
	string owner;
	double balance;

public:
	BankAccount(string name, double initialBalance)
		: owner(name), balance(initialBalance) {}
	
	virtual void deposit(double amount) {
		balance += amount;
		cout << owner << " deposited $" << amount << ". New Balance: $" << balance << endl;
	}
	
	virtual void withdraw(double amount) {
		if (amount > balance) {
			cout << "Insufficient balance!" << endl;
		} else {
			balance -= amount;
			cout << owner << " withdrew $" << amount << ". New Balance: $" << balance << endl;
		}
	}
	
	virtual void display() {
		cout << "Owner: " << owner << ", Balance: $" << balance << endl;
	}
	
	virtual ~BankAccount() {}
};

// Derived class: SavingsAccount
class SavingsAccount : public BankAccount {
private:
	double interestRate;

public:
	SavingsAccount(string name, double initialBalance, double rate)
		: BankAccount(name, initialBalance), interestRate(rate) {}
	
	void applyInterest() {
		balance += balance * (interestRate / 100);
		cout << "Interest applied! New Balance: $" << balance << endl;
	}
	
	void display() override {
		cout << "[Savings] ";
		BankAccount::display();
	}
};

// Derived class: CurrentAccount
class CurrentAccount : public BankAccount {
private:
	double overdraftLimit;

public:
	CurrentAccount(string name, double initialBalance, double overdraft)
		: BankAccount(name, initialBalance), overdraftLimit(overdraft) {}
	
	void withdraw(double amount) override {
		if (amount > balance + overdraftLimit) {
			cout << "Withdrawal exceeds overdraft limit!" << endl;
		} else {
			balance -= amount;
			cout << owner << " withdrew $" << amount << ". New Balance: $" << balance << endl;
		}
	}
	
	void display() override {
		cout << "[Current] ";
		BankAccount::display();
	}
};

// Main function
int main() {
	BankAccount* acc1 = new SavingsAccount("Alice", 1000, 5);
	BankAccount* acc2 = new CurrentAccount("Bob", 500, 200);
	
	cout << "\n--- Account Details ---\n";
	acc1->display();
	acc2->display();
	
	cout << "\n--- Transactions ---\n";
	acc1->deposit(200);
	acc1->withdraw(300);
	
	SavingsAccount* savings = dynamic_cast<SavingsAccount*>(acc1);
	if (savings)
		savings->applyInterest();
	
	acc2->withdraw(600);
	
	cout << "\n--- Final Account Details ---\n";
	acc1->display();
	acc2->display();
	
	delete acc1;
	delete acc2;
	
	return 0;
}