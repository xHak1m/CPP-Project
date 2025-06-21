#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to add an item to the inventory
void addItem(vector<string>& inventory) {
	string item;
	cout << "Enter item name: ";
	cin >> item;
	inventory.push_back(item);
	cout << "Item added successfully!" << endl;
}

// Function to display all items in the inventory
void displayItems(const vector<string>& inventory) {
	if (inventory.empty()) {
		cout << "No items in the inventory." << endl;
		return;
	}
	
	cout << "Inventory List:" << endl;
	for (size_t i = 0; i < inventory.size(); ++i) {
		cout << i + 1 << ". " << inventory[i] << endl;
	}
}

// Function to search for an item by name
void searchItem(const vector<string>& inventory) {
	string item;
	cout << "Enter the item name to search: ";
	cin >> item;
	
	bool found = false;
	for (const auto& invItem : inventory) {
		if (invItem == item) {
			cout << "Item found: " << invItem << endl;
			found = true;
			break;
		}
	}
	
	if (!found) {
		cout << "Item not found." << endl;
	}
}

// Function to delete an item by name
void deleteItem(vector<string>& inventory) {
	string item;
	cout << "Enter the item name to delete: ";
	cin >> item;
	
	auto it = find(inventory.begin(), inventory.end(), item);
	if (it != inventory.end()) {
		inventory.erase(it);
		cout << "Item deleted successfully!" << endl;
	} else {
		cout << "Item not found." << endl;
	}
}

int main() {
	vector<string> inventory;
	int choice;
	
	do {
		cout << "\nSimple Inventory Management System\n";
		cout << "1. Add Item\n";
		cout << "2. Display Items\n";
		cout << "3. Search Item\n";
		cout << "4. Delete Item\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			case 1:
				addItem(inventory);
				break;
			case 2:
				displayItems(inventory);
				break;
			case 3:
				searchItem(inventory);
				break;
			case 4:
				deleteItem(inventory);
				break;
			case 5:
				cout << "Exiting the system." << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
		}
	
	} while (choice != 5);
	
	return 0;
}