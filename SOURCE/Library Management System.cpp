#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
	string title;     // Stores the book's title
	string author;    // Stores the book's author
	bool isIssued;    // Tracks whether the book is issued or not

public:
	// Constructor
	Book(string t, string a) : title(t), author(a), isIssued(false) {}
	
	// Getters
	string getTitle() const { return title; }
	string getAuthor() const { return author; }
	bool getIsIssued() const { return isIssued; }
	
	// Issue the book
	void issueBook() { isIssued = true; }
	
	// Return the book
	void returnBook() { isIssued = false; }
	
	// Display book details
	void display() const {
		cout << "Title: " << title << ", Author: " << author;
		cout << (isIssued ? " [Issued]" : " [Available]") << endl;
	}
};

class Library {
private:
	vector<Book> books;

public:
	// Add a new book to the library
	void addBook(string title, string author) {
		books.push_back(Book(title, author));
		cout << "Book added successfully.\n";
	}
	
	// Display all books
	void displayBooks() const {
		if (books.empty()) {
			cout << "No books in the library.\n";
			return;
		}
		
		cout << "\nList of Books in the Library:\n";
		for (const auto& book : books) {
			book.display();
		}
	}
	
	// Search for a book by title
	void searchBook(string title) const {
		for (const auto& book : books) {
			if (book.getTitle() == title) {
				cout << "Book found: ";
				book.display();
				return;
			}
		}
		cout << "Book not found.\n";
	}
	
	// Issue a book
	void issueBook(string title) {
		for (auto& book : books) {
			if (book.getTitle() == title) {
				if (book.getIsIssued()) {
					cout << "Book is already issued.\n";
				} else {
					book.issueBook();
					cout << "Book issued successfully.\n";
				}
				return;
			}
		}
		cout << "Book not found.\n";
	}
	
	// Return a book
	void returnBook(string title) {
		for (auto& book : books) {
			if (book.getTitle() == title) {
				if (!book.getIsIssued()) {
					cout << "Book is already available.\n";
				} else {
					book.returnBook();
					cout << "Book returned successfully.\n";
				}
				return;
			}
		}
		cout << "Book not found.\n";
	}
};

// Main function
int main() {
	Library library;
	int choice;
	string title, author;
	
	do {
		cout << "\nLibrary Management System\n";
		cout << "1. Add New Book\n";
		cout << "2. Display All Books\n";
		cout << "3. Search Book by Title\n";
		cout << "4. Issue Book\n";
		cout << "5. Return Book\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(); // To clear input buffer
		
		switch (choice) {
			case 1:
				cout << "Enter book title: ";
				getline(cin, title);
				cout << "Enter author name: ";
				getline(cin, author);
				library.addBook(title, author);
				break;
			
			case 2:
				library.displayBooks();
				break;
			
			case 3:
				cout << "Enter book title to search: ";
				getline(cin, title);
				library.searchBook(title);
				break;
			
			case 4:
				cout << "Enter book title to issue: ";
				getline(cin, title);
				library.issueBook(title);
				break;
			
			case 5:
				cout << "Enter book title to return: ";
				getline(cin, title);
				library.returnBook(title);
				break;
			
			case 6:
				cout << "Exiting Library Management System. Goodbye!\n";
				break;
			
			default:
				cout << "Invalid choice! Please try again.\n";
		}
	} while (choice != 6);
	
	return 0;
}