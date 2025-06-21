#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int choice;
	double num1, num2, result;
	
	cout << "**********************************" << endl;
	cout << "*      WELCOME TO CALCULATOR     *" << endl;
	cout << "**********************************" << endl;
	
	while (true) {
		cout << "\nSelect an operation:\n";
		cout << "1. Addition (+)\n";
		cout << "2. Subtraction (-)\n";
		cout << "3. Multiplication (*)\n";
		cout << "4. Division (/)\n";
		cout << "5. Exit\n";
		cout << "Enter your choice (1-5): ";
		cin >> choice;
		
		if (choice == 5) {
			cout << "Thank you for using the calculator!" << endl;
			break;
		}
		
		cout << "Enter two numbers: ";
		cin >> num1 >> num2;
		
		switch (choice) {
			case 1:
				result = num1 + num2;
				cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
				break;
				
			case 2:
				result = num1 - num2;
				cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
				break;
				
			case 3:
				result = num1 * num2;
				cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
				break;
				
			case 4:
				if (num2 != 0) {
					result = num1 / num2;
					cout << fixed << setprecision(2);
					cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
				} else {
					cout << "Error! Division by zero is undefined." << endl;
				}
				break;
				
			default:
				cout << "Invalid choice! Please select a valid option." << endl;
		}
		
		cout << "\n----------------------------------\n";
	}
	
	return 0;
}