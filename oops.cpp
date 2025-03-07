#include <iostream>
#include <vector>
#include <string>

using namespace std;

int total_students = 0, total_marks = 0;

class Student {
private:
    string name;
    string rollNum;
    string ContactNum;
    vector<int> marks;
    float avg;

public:
    static vector<Student> students;

    Student() : marks(5, 0), avg(0) {}

    void setStudent() {
        Student s1;
        int t1 = 0;
        
        cout << "Enter the name of the student: ";
        cin >> s1.name;
        
        cout << "Enter the roll number of the student: ";
        cin >> s1.rollNum;
        
        cout << "Enter the contact number of the student: ";
        cin >> s1.ContactNum;
        
        cout << "Enter the marks of the student (5 subjects): ";
        for (int i = 0; i < 5; i++) {
            cin >> s1.marks[i];
            t1 += s1.marks[i];
        }
        
        s1.avg = (float)t1 / 5;
        total_marks += t1;
        total_students++;
        students.push_back(s1);
    }

    void ViewDetails() 
    {
        if (students.empty()) {
            cout << "No students to display!\n";
            return;
        }
        
        for (size_t i = 0; i < students.size(); i++) {
            cout << "----------------------------------------\n";
            cout << "Student " << i + 1 << ":\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Roll Number: " << students[i].rollNum << endl;
            cout << "Contact Number: " << students[i].ContactNum << endl;
            cout << "Marks: ";
            for (int j = 0; j < 5; j++) {
                cout << students[i].marks[j] << " ";
            }
            cout << endl;
            cout << "Average: " << students[i].avg << endl;
            cout << "----------------------------------------\n";
        }
    }

    void ClassAverage() {
        if (students.empty()) {
            cout << "No students found!\n";
            return;
        }
        cout << "The class average is: " << (total_marks / total_students) << endl;
    }

    void SubjectAvg() {
        if (students.empty()) {
            cout << "No students available!\n";
            return;
        }

        int n1;
        cout << "Enter the subject number (1-5) for which average is to be calculated: ";
        cin >> n1;

        if (n1 < 1 || n1 > 5) {
            cout << "Invalid subject number. Please enter a number between 1 and 5.\n";
            return;
        }

        int sum = 0;
        for (const auto& student : students) {
            sum += student.marks[n1 - 1];
        }
        
        cout << "The average marks for subject " << n1 << " is: " << (sum / students.size()) << endl;
    }
};

vector<Student> Student::students;

int main() {
    Student s;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Class Average\n";
        cout << "4. Subject Average\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.setStudent();
                break;
            case 2:
                s.ViewDetails();
                break;
            case 3:
                s.ClassAverage();
                break;
            case 4:
                s.SubjectAvg();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}