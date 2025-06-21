#include <iostream>

using namespace std;

int main() {
	int* arr; // Pointer to an integer (for dynamic array)
	int size; // Size of the array
	
	// Input the size of the array
	cout << "Enter the size of the array: ";
	cin >> size;
	
	arr = new int[size]; // Dynamically allocate memory
	
	cout << "Enter " << size << " integers:" << endl;
	for (int i = 0; i < size; i++) {
		cin >> arr[i]; // Store values at respective positions
	}
	
	// Display the values using the pointer
	cout << "Array elements: ";
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " "; // Access via pointer arithmetic
	}
	cout << endl;
	
	int index;
	cout << "Enter the index to modify (0 to " << size - 1 << "): ";
	cin >> index;
	
	if (index >= 0 && index < size) {
		cout << "Enter the new value: ";
		cin >> *(arr + index); // Modify element using pointer
	} else {
		cout << "Invalid index!" << endl;
	}
	
	// Display the updated array
	cout << "Updated array: ";
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
	
	delete[] arr; // Free the dynamically allocated memory
	return 0;
}