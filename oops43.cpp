#include <iostream>
#include <vector>   /// Question :5
#include <iomanip>
using namespace std;

class Student {
public:
    char name[50];  
    char rollNo[20];  
    char contactNumber[11]; 
    int marks[5];  
    double totalMarks;
    double averageMarks;

    void calculateTotalAndAverage() {
        totalMarks = 0;
        for (int i = 0; i < 5; i++) {
            totalMarks += marks[i];
        }
        averageMarks = totalMarks / 5;
    }

    void isValidName() {
        while (true) {
            cout << "Enter Name: ";
            cin >> ws;  // Clear any leading whitespace
            cin.get(name, 50);  // Read full name including spaces

            bool validName = true;
            int length = 0;

            for (int i = 0; name[i] != '\0'; i++) {
                length++;
                if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' ')) {
                    validName = false;
                    break;
                }
            }

            if (length == 0 || !validName) {
                cout << "Invalid input! Name must only contain letters and spaces.\n";
            } else {
                break;
            }
        }
    }

    void isValidPhoneNumber() {
        while (true) {
            cout << "Enter Contact Number (10 digits): ";
            cin >> contactNumber;

            int length = 0;
            bool validPhone = true;

            for (int i = 0; contactNumber[i] != '\0'; i++) {
                length++;
                if (contactNumber[i] < '0' || contactNumber[i] > '9') {
                    validPhone = false;
                    break;
                }
            }

            if (length != 10 || !validPhone) {
                cout << "Invalid phone number! Please enter a valid 10-digit number.\n";
            } else {
                break;
            }
        }
    }

    void areValidMarks() {
        while (true) {
            bool validMarks = true;
            cout << "Enter Marks for 5 subjects (between 0 and 10): ";
            
            for (int i = 0; i < 5; i++) {
                cin >> marks[i];
                if (marks[i] < 0 || marks[i] > 10) {
                    validMarks = false;
                }
            }

            if (!validMarks) {
                cout << "Marks should be between 0 and 10 for all subjects.\n";
            } else {
                break;
            }
        }
    }
};

class ClassRecord {
private:
    vector<Student> students;
    int studentCount = 0;

public:
    void addStudent() {
        Student newStudent;
        cout << "Enter Roll No: ";
        cin >> newStudent.rollNo;
        newStudent.isValidName();
        newStudent.isValidPhoneNumber();
        newStudent.areValidMarks();
        newStudent.calculateTotalAndAverage();
        students.push_back(newStudent);
        studentCount++;
    }

    void displayStudentDetails() {
        cout << "\nStudent Details and Subject-wise Marks:\n";
        cout << "----------------------------------------------------------------------------------------------------------------------\n";
        cout << setw(15) << "Roll No" 
             << setw(20) << "Name" 
             << setw(15) << "Contact No" 
             << setw(15) << "Total Marks" 
             << setw(10) << "Average" 
             << " | " << setw(5) << "S1" 
             << setw(5) << "S2" 
             << setw(5) << "S3" 
             << setw(5) << "S4" 
             << setw(5) << "S5" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------\n";
        
        double subjectTotals[5] = {0};
        for (const auto &student : students) {
            cout << setw(15) << student.rollNo 
                 << setw(20) << student.name 
                 << setw(15) << student.contactNumber 
                 << setw(15) << student.totalMarks 
                 << setw(10) << student.averageMarks << " | ";
            for (int j = 0; j < 5; j++) {
                cout << setw(5) << student.marks[j] << " ";
                subjectTotals[j] += student.marks[j];
            }
            cout << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------\n";
        
        // Display total subject-wise marks under correct subject columns
        cout << setw(65) << "Total Subject-wise Marks:" << " | ";
        for (int i = 0; i < 5; i++) {
            cout << setw(5) << subjectTotals[i] << " ";
        }
        cout << endl;
        
        // Display average subject-wise marks under correct subject columns
        cout << setw(65) << "Average Subject-wise Marks:" << " | ";
        for (int i = 0; i < 5; i++) {
            cout << setw(5) << fixed << setprecision(1) << (subjectTotals[i] / studentCount) << " ";
        }
        cout << endl;
        
        cout << "----------------------------------------------------------------------------------------------------------------------\n";
    }

    void displayClassAverage() {
        double totalStudentAverage = 0;
        for (const auto &student : students) {
            totalStudentAverage += student.averageMarks;
        }
        double classTotalAverage = totalStudentAverage / studentCount;
        cout << "\nClass Average Marks: " << fixed << setprecision(1) << classTotalAverage << endl;
    }

    void displayTotalStudents() {
        cout << "\nTotal number of students in the class: " << studentCount << endl;
    }
};

int main() {
    ClassRecord classRecord;
    int numberOfStudents;
    
    cout << "Enter number of students in the class: ";
    cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; i++) {
        classRecord.addStudent();
    }

    classRecord.displayStudentDetails();
    classRecord.displayClassAverage();
    classRecord.displayTotalStudents();

    return 0;
}