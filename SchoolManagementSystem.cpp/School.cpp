#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Student {
    string name;
    int rollNumber;
    int age;
    string branchname;
};
void displayMenu() {
    cout << "-------------------------------------" << endl;
    cout << "School Management System Menu" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display All Students" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Update Student Information" << endl;
    cout << "5. Delete Student" << endl;
    cout << "6. Exit" << endl;
    cout << "-------------------------------------" << endl;
}
void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student name: ";
    getline(cin, newStudent.name);
    cout << "Enter brance name: ";
    getline(cin, newStudent.branchname);
    cout << "Enter student roll number: ";
    cin >> newStudent.rollNumber;

    cout << "Enter student age: ";
    cin >> newStudent.age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    students.push_back(newStudent);

    cout << "Student added successfully!" << endl;
}
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students in the system." << endl;
    } else {
        cout << "-------------------------------------" << endl;
        cout << "List of All Students" << endl;
        cout << "-------------------------------------" << endl;
        cout << setw(20) << "Name" << setw(15) << "Roll Number" << setw(10) << "Age" << endl;

        for (const auto& student : students) {
            cout << setw(20) << student.name << setw(15) << student.rollNumber << setw(10) << student.age << endl;
        }
    }
}

int searchStudent(const vector<Student>& students, int rollNumber) {
    auto it = find_if(students.begin(), students.end(),
                      [rollNumber](const Student& student) { return student.rollNumber == rollNumber; });

    if (it != students.end()) {
        return distance(students.begin(), it);
    } else {
        return -1; 
    }
}
void updateStudent(vector<Student>& students) {
    int rollNumber;
    cout << "Enter the roll number of the student to update: ";
    cin >> rollNumber;
    int index = searchStudent(students, rollNumber);

    if (index != -1) {
        cout << "Enter updated student name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, students[index].name);

        cout << "Enter updated student age: ";
        cin >> students[index].age;

        cout << "Student information updated successfully!" << endl;
    } else {
        cout << "Student not found." << endl;
    }
}
void deleteStudent(vector<Student>& students) {
    int rollNumber;
    cout << "Enter the roll number of the student to delete: ";
    cin >> rollNumber;

    int index = searchStudent(students, rollNumber);

    if (index != -1) {
        students.erase(students.begin() + index);
        cout << "Student deleted successfully!" << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

int main() {
    vector<Student> students; 

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3: {
                int rollNumber;
                cout << "Enter the roll number of the student to search: ";
                cin >> rollNumber;
                int index = searchStudent(students, rollNumber);
                if (index != -1) {
                    cout << "Student found at index " << index << "." << endl;
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            }
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}