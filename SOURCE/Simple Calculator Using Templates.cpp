#include <iostream>
#include <cmath> // For pow() function

using namespace std;

// Template class for Calculator
template<typename T>
class Calculator {
private:
	T num1, num2;
public:
	Calculator(T a, T b) : num1(a), num2(b) {}
	T add() { return num1 + num2; }
	T subtract() { return num1 - num2; }
	T multiply() { return num1 * num2; }
	T divide() {
		if (num2 == 0) {
			cout << "Error: Division by zero is not allowed!" << endl;
			return 0;
		}
		return num1 / num2;
	}
	T power() {
		return pow(num1, num2);
	}
	void displayResults() {
		cout << "Addition: " << add() << endl;
		cout << "Subtraction: " << subtract() << endl;
		cout << "Multiplication: " << multiply() << endl;
		cout << "Division: " << divide() << endl;
		cout << "Power: " << power() << endl;
	}
};

int main() {
	double x, y;
	cout << "Enter two numbers: ";
	cin >> x >> y;
	// Create a Calculator object with user input
	Calculator<double> calc(x, y);
	// Display results
	calc.displayResults();
	return 0;
};
