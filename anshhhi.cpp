#include <iostream>
#include <iomanip> // For setw()

using namespace std;

struct Student {
    string name;
    string rollno;
    float grade;
    float activityMarks;
    string activityType;
};

void displayTable(Student students[], int n) {
    cout << "\n--------------------------------------------------------------\n";
    cout << left << setw(15) << "Name" 
         << setw(15) << "Roll No" 
         << setw(10) << "Grade" 
         << setw(15) << "Activity" 
         << setw(10) << "Marks" << endl;
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << students[i].name
             << setw(15) << students[i].rollno
             << setw(10) << students[i].grade
             << setw(15) << students[i].activityType
             << setw(10) << students[i].activityMarks << endl;
    }
    cout << "--------------------------------------------------------------\n";
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    cin.ignore(); // Clear buffer

    Student students[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Roll No: ";
        getline(cin, students[i].rollno);
        cout << "Grade: ";
        cin >> students[i].grade;
        cout << "Enter activity (Sports/Music): ";
        cin >> students[i].activityType;
        cout << "Activity Marks (0-100): ";
        cin >> students[i].activityMarks;
        cin.ignore();
    }

    displayTable(students, n);
    return 0;
}

