#include <iostream>

using namespace std;

int main() {
	int n;
	
	cout << "Enter the number of students: ";
	cin >> n;
	
	// Declare an array to store grades and variables for calculations
	double grades[n], sum = 0;
	
	cout << "Enter the grades: ";
	for (int i = 0; i < n; i++) {
		cin >> grades[i];
		sum += grades[i]; // Calculate the total sum of grades
	}
	
	// Calculate average, highest, and lowest grades
	double average = sum / n;
	double highest = grades[0], lowest = grades[0];
	
	for (int i = 1; i < n; i++) {
		if (grades[i] > highest) highest = grades[i]; // Update highest grade
		if (grades[i] < lowest) lowest = grades[i];   // Update lowest grade
	}
	
	// Display results
	cout << "\n--- Grades Analysis ---" << endl;
	cout << "Average Grade: " << average << endl;
	cout << "Highest Grade: " << highest << endl;
	cout << "Lowest Grade: " << lowest << endl;
	
	// Check if the class passed or failed
	if (average >= 50) {
		cout << "The class passed!" << endl;
	} else {
		cout << "The class failed!" << endl;
	}
	
	return 0;
}