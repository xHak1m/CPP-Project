#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
	map<string, vector<double>> expenses;
	int n;
	
	cout << "Enter number of expenses: ";
	cin >> n;
	
	// Input each expense
	for (int i = 0; i < n; ++i) {
		string category;
		double amount;
		
		cout << "\nExpense " << i + 1 << ":\n";
		
		cout << "Category: ";
		cin >> ws;
		getline(cin, category);
		
		cout << "Amount: ";
		cin >> amount;
		
		expenses[category].push_back(amount);
	}
	
	// Processing & Output
	double totalSpent = 0;
	string maxCategory;
	double maxCategoryTotal = 0;
	
	cout << "\n--- Summary ---\n";
	
	for (const auto& entry : expenses) {
		const string& category = entry.first;
		const vector<double>& amounts = entry.second;
		
		double categoryTotal = 0;
		
		for (double amount : amounts) {
			categoryTotal += amount;
		}
		
		cout << category << ": $" << fixed << setprecision(2) << categoryTotal << endl;
		
		totalSpent += categoryTotal;
		
		if (categoryTotal > maxCategoryTotal) {
			maxCategoryTotal = categoryTotal;
			maxCategory = category;
		}
	}
	
	cout << "Total Spent: $" << fixed << setprecision(2) << totalSpent << endl;
	cout << "Highest Spending Category: " << maxCategory << endl;
	
	return 0;
}