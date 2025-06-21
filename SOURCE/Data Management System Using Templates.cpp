#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Template class for managing a generic database
template <typename T>
class Database {
private:
	vector<T> records;

public:
	// Add a record
	void addRecord(T record) {
		records.push_back(record);
	}
	
	// Search for a record
	bool searchRecord(T record) {
		for (T r : records) {
			if (r == record) {
				return true;
			}
		}
		return false;
	}
	
	// Sort records
	void sortRecords() {
		sort(records.begin(), records.end());
	}
	
	// Display all records
	void displayRecords() {
		if (records.empty()) {
			cout << "No records available!" << endl;
			return;
		}
		
		cout << "Stored Records:" << endl;
		for (T r : records) {
			cout << r << endl;
		}
	}
};

// Main function
int main() {
	int choice;
	
	Database<int> intDB;
	Database<string> strDB;
	
	do {
		cout << "\nDatabase Management System\n";
		cout << "1. Add Integer Record\n";
		cout << "2. Add String Record\n";
		cout << "3. Search Integer Record\n";
		cout << "4. Search String Record\n";
		cout << "5. Sort Integer Records\n";
		cout << "6. Sort String Records\n";
		cout << "7. Display Integer Records\n";
		cout << "8. Display String Records\n";
		cout << "9. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			case 1: {
				int num;
				cout << "Enter an integer: ";
				cin >> num;
				intDB.addRecord(num);
				cout << "Integer record added successfully!\n";
				break;
			}
			case 2: {
				string str;
				cout << "Enter a string: ";
				cin >> str;
				strDB.addRecord(str);
				cout << "String record added successfully!\n";
				break;
			}
			case 3: {
				int num;
				cout << "Enter an integer to search: ";
				cin >> num;
				if (intDB.searchRecord(num))
					cout << "Integer found in the database.\n";
				else
					cout << "Integer not found.\n";
				break;
			}
			case 4: {
				string str;
				cout << "Enter a string to search: ";
				cin >> str;
				if (strDB.searchRecord(str))
					cout << "String found in the database.\n";
				else
					cout << "String not found.\n";
				break;
			}
			case 5:
				intDB.sortRecords();
				cout << "Integer records sorted successfully!\n";
				break;
			case 6:
				strDB.sortRecords();
				cout << "String records sorted successfully!\n";
				break;
			case 7:
				intDB.displayRecords();
				break;
			case 8:
				strDB.displayRecords();
				break;
			case 9:
				cout << "Exiting the program...\n";
				break;
			default:
				cout << "Invalid choice! Please enter a valid option.\n";
		}
	} while (choice != 9);
	
	return 0;
}