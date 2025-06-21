#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
	string name;
	int rollNumber;
	float marks[3]; // Marks in 3 subjects
	float totalMarks;
	char grade;
	
	void calculateGrade() {
		totalMarks = marks[0] + marks[1] + marks[2];
		float average = totalMarks / 3;
		
		if (average >= 90)
			grade = 'A';
		else if (average >= 75)
			grade = 'B';
		else if (average >= 50)
			grade = 'C';
		else
			grade = 'F';
	}
	
	void display() const {
		cout << "Name: " << name
			 << ", Roll No: " << rollNumber
			 << ", Total Marks: " << totalMarks
			 << ", Grade: " << grade << endl;
	}
};

class ReportCardSystem {
private:
	vector<Student> students;

public:
	// Add a new student
	void addStudent(const string& name, int roll, float marks[]) {
		Student s;
		s.name = name;
		s.rollNumber = roll;
		copy(marks, marks + 3, s.marks);
		s.calculateGrade();
		students.push_back(s);
		cout << "Student record added successfully!\n";
	}
	
	// Display all student records
	void displayStudents() const {
		if (students.empty()) {
			cout << "No student records found.\n";
			return;
		}
		
		cout << "\nAll Students:\n";
		for (const auto& s : students) {
			s.display();
		}
	}
	
	// Search for a student by roll number
	void searchStudent(int roll) const {
		for (const auto& s : students) {
			if (s.rollNumber == roll) {
				cout << "Student Found:\n";
				s.display();
				return;
			}
		}
		cout << "Student with roll number " << roll << " not found.\n";
	}
	
	// Sort students by total marks
	void sortStudents() {
		sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
			return a.totalMarks > b.totalMarks; // Descending order
		});
		cout << "Students sorted by total marks.\n";
	}
};

int main() {
	ReportCardSystem system;
	int choice;
	
	do {
		cout << "\nStudent Report Card System\n";
		cout << "1. Add Student\n";
		cout << "2. Display All Students\n";
		cout << "3. Search Student by Roll Number\n";
		cout << "4. Sort Students by Total Marks\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
		case 1: {
			string name;
			int roll;
			float marks[3];
			
			cin.ignore(); // To clear input buffer
			cout << "Enter student name: ";
			getline(cin, name);
			cout << "Enter roll number: ";
			cin >> roll;
			cout << "Enter marks in 3 subjects: ";
			cin >> marks[0] >> marks[1] >> marks[2];
			
			system.addStudent(name, roll, marks);
			break;
		}
		
		case 2:
			system.displayStudents();
			break;
		
		case 3: {
			int roll;
			cout << "Enter roll number to search: ";
			cin >> roll;
			system.searchStudent(roll);
			break;
		}
		
		case 4:
			system.sortStudents();
			break;
		
		case 5:
			cout << "Exiting the system. Goodbye!\n";
			break;
		
		default:
			cout << "Invalid choice! Please try again.\n";
		}
	
	} while (choice != 5);
	
	return 0;
}