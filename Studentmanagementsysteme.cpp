#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    float marks;
};

Student students[100];
int count = 0;

// Add student
void addStudent() {
    cout << "\nEnter ID: ";
    cin >> students[count].id;

    cout << "Enter Name: ";
    cin >> students[count].name;

    cout << "Enter Age: ";
    cin >> students[count].age;

    cout << "Enter Marks: ";
    cin >> students[count].marks;

    count++;
    cout << "Student added successfully!\n";
}

// Display all students
void displayStudents() {
    if (count == 0) {
        cout << "\nNo records found!\n";
        return;
    }

    cout << "\nStudent Records:\n";
    for (int i = 0; i < count; i++) {
        cout << "\nID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nAge: " << students[i].age;
        cout << "\nMarks: " << students[i].marks << endl;
    }
}

// Search student
void searchStudent() {
    int id;
    cout << "\nEnter ID to search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Marks: " << students[i].marks << endl;
            return;
        }
    }

    cout << "Student not found!\n";
}

// Delete student
void deleteStudent() {
    int id;
    cout << "\nEnter ID to delete: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Student deleted successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
