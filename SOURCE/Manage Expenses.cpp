#include <iostream>
#include <string>

using namespace std;

int main() {
	const int days = 30; // Number of days in a month
	float expenses[days];
	float total = 0, average = 0;
	float maxExpense = 0;
	int maxDay = 0;
	
	// Input daily expenses
	cout << "Enter your expenses for each day of the month (30 days):" << endl;
	
	for (int i = 0; i < days; i++) {
		cout << "Day " << i + 1 << ": $";
		cin >> expenses[i];
		
		total += expenses[i];
		
		if (expenses[i] > maxExpense) {
			maxExpense = expenses[i];
			maxDay = i + 1;
		}
	}
	
	// Calculate average
	average = total / days;
	
	// Output results
	cout << "\n- Expense Summary -" << endl;
	cout << "Total Expenses: $" << total << endl;
	cout << "Average Daily Expense: $" << average << endl;
	cout << "Highest Expense: $" << maxExpense << " on Day " << maxDay << endl;
	
	return 0;
}