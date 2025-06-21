#include <iostream>

using namespace std;

// Base Class
class Employee {
protected:
	string name;
	int id;
public:
	Employee(string n, int i) : name(n), id(i) {}
	virtual void calculateSalary() = 0; // Pure virtual function
	void displayInfo() {
		cout << "ID: " << id << ", Name: " << name << endl;
	}
	virtual ~Employee() {} // Virtual destructor
};

class FullTimeEmployee : public Employee {
private:
	double monthlySalary;
public:
	FullTimeEmployee(string n, int i, double salary) : Employee(n, i), monthlySalary(salary) {}
	void calculateSalary() override {
		cout << "Full-Time Employee Salary: 5" << monthlySalary << endl;
	}
};

class PartTimeEmployee : public Employee {
private:
	double hourlyRate;
	int hoursWorked;
public:
	PartTimeEmployee(string n, int i, double rate, int hours) : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}
	void calculateSalary() override {
		cout << "Part-Time Employee Salary: $" << (hourlyRate * hoursWorked) << endl;
	}
};

// Main Function
int main() {
	Employee * emp1 = new FullTimeEmployee("Erick", 101, 5000);
	Employee * emp2 = new PartTimeEmployee("Parker", 102, 50, 50);
	
	cout << "\nEmployee Details & Salary Calculation:\n";
	emp1->displayInfo();
	emp1->calculateSalary();
	cout << endl;
	
	emp2->displayInfo();
	emp2->calculateSalary();
	
	// Clean up
	delete emp1;
	delete emp2;
	
	return 0;
}