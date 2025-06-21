#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Book {
	string author;
	bool isAvailable;
};

// Display Book
void displayBooks(const map<string, Book>& library) {
	cout << "\n--- Book List ---\n";
	for (const auto& entry : library) {
		cout << "Title: " << entry.first
			 << " | Author: " << entry.second.author
			 << " | Status: " << (entry.second.isAvailable ? "Available" : "Reserved")
			 << endl;
	}
}

// Reserve Book
void reserveBook(map<string, Book>& library) {
	string title;
	
	cout << "Enter the title of the book to reserve: ";
	getline(cin >> ws, title);
	
	auto it = library.find(title);
	
	if (it != library.end()) {
		if (it->second.isAvailable) {
			it->second.isAvailable = false;
			cout << "Book reserved successfully!\n";
		} else {
			cout << "Book is already reserved.\n";
		}
	} else {
		cout << "Book not found.\n";
	}
}

// Cancel Reservation
void cancelReservation(map<string, Book>& library) {
	string title;
	
	cout << "Enter the title of the book to cancel reservation: ";
	getline(cin >> ws, title);
	
	auto it = library.find(title);
	
	if (it != library.end()) {
		if (!it->second.isAvailable) {
			it->second.isAvailable = true;
			cout << "Reservation cancelled successfully.\n";
		} else {
			cout << "Book is already available.\n";
		}
	} else {
		cout << "Book not found.\n";
	}
}

// Add a new Book
void addBook(map<string, Book>& library) {
	string title, author;
		
	cout << "Enter book title: ";
	getline(cin >> ws, title);
	
	cout << "Enter author: ";
	getline(cin, author);
	
	if (library.count(title)) {
		cout << "Book already exists.\n";
	} else {
		library[title] = {author, true};
		cout << "Book added successfully.\n";
	}
}

// Library Menu
void menu() {
	cout << "\n--- Library Menu ---\n";
	cout << "1. View All Books\n";
	cout << "2. Reserve a Book\n";
	cout << "3. Cancel Reservation\n";
	cout << "4. Add a Book\n";
	cout << "5. Exit\n";
	cout << "Enter your choice: ";
}

// Main Menu
int main() {
	map<string, Book> library = {
		{"1984", {"George Orwell", true}},
		{"The Hobbit", {"J.R.R. Tolkien", true}},
		{"Pride and Prejudice", {"Jane Austen", true}},
		{"To Kill a Mockingbird", {"Harper Lee", true}}
	};
	
	int choice;
	
	do {
		cout << "\n--- Library Menu ---\n";
		cout << "1. Display Books\n";
		cout << "2. Reserve Book\n";
		cout << "3. Cancel Reservation\n";
		cout << "4. Add Book\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			case 1: 
				displayBooks(library); 
				break;
			case 2: 
				reserveBook(library); 
				break;
			case 3: 
				cancelReservation(library); 
				break;
			case 4: 
				addBook(library); 
				break;
			case 5: 
				cout << "Exiting...\n"; 
				break;
			default: 
				cout << "Invalid choice.\n";
		}
	
	} while (choice != 5);
	
	return 0;
}
