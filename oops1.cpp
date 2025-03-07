#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    string rollno;
    float grade;
};
union Activity
{
    float sports;
    float music;
};

class finalDetails
{
private:
    Student s;
    Activity a;
    int choice;

public:
    void addStudent()
    {
        cout << "Enter name:";
        getline(cin, s.name);
        if ((all_of(s.name.begin(), s.name.end(), ::isdigit))) // 
        {
            cout << "Name cannot be number. Please enter name" << endl;
            getline(cin, s.name); // getline 
        }

        cout << "Enter rollno:";
        getline(cin, s.rollno);

        cout << "Enter marks:(0-100):";
       while (true) {
        cin >> s.grade;

        // Check if input is invalid
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number: ";}
        else if(s.grade > 100 || s.grade < 0)
            {
                cout << "Invalid input. Please enter marks between 0-100" << endl;
                
            }
         else {
            break; // Input is valid, exit loop
        }
    }
            
            
        cin.ignore(); // cin buffer clear

        cout << "Enter sports(1) or music(2):";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter sports marks(0-100):";

            while (true)
            {
                cin >> a.sports;

                // Check if input is invalid
                if (cin.fail()) // memory allocation 
                {
                    cin.clear();                                                   // Clear the error flag
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. Please enter a number: ";
                }
                else if (a.sports > 100 || a.sports < 0)
                {
                    cout << "Invalid input. Please enter marks between 0-100" << endl;
                    
                }
                else
                {
                    break; // Input is valid, exit loop
                }
            }

            cin.ignore();
        }
        else if (choice == 2)
        {
            cout << "Enter music marks(0-100):";
            while (true)
            {
                cin >> a.music;

                // Check if input is invalid
                if (cin.fail())
                {
                    cin.clear();                                                   // Clear the error flag
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. Please enter a number: ";
                }
                else if (a.music > 100 || a.music < 0)
                {
                    cout << "Invalid input. Please enter marks between 0-100" << endl;
                   
                }
                else
                {
                    break; // Input is valid, exit loop
                }
            }

            cin.ignore();
        }
        else
        {
            cout << "Invalid choice";
            cin >> choice;
            cin.ignore();
        }
    }
    void displayStudent()
    {
        cout << "Name:" << s.name << " ";
        cout << "Rollno:" << s.rollno << " ";
        cout << "Grade:" << s.grade << " ";
        if (choice == 1)
        {

            cout << "Sportsmarks:" << a.sports << " ";
        }
        else
        {
            cout << "Musicmarks:" << a.music << " ";
        }
    }
    void averageGrade()
    {
        cout << s.name << " ";
        cout << "Average marks:";

        if (choice == 1)
        {
            cout << (s.grade + a.sports) / 2;
        }
        else if (choice == 2)
        {
            cout << (s.grade + a.music) / 2;
        }
    }
};
int main()
{
    int num = 1;
    int choose;
    int n;

    vector<finalDetails> info;
    while (num)
    {
        cout << "Enter 1 to add students:" << endl;
        cout << "Enter 2 to display students details:" << endl;
        cout << "Enter 3 to print average grade of all students:" << endl;
        cout << "Enter 4 to exit" << endl;
        cout << "Enter here :";
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "Enter the number of students: ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                finalDetails fd;
                fd.addStudent();
                info.push_back(fd);
            }
            break;
        case 2:
            for (auto student : info)
            {
                student.displayStudent();
                
                cout << endl;
            }
            break;
        case 3:
            for (auto student : info)
            {
                student.averageGrade();
                cout << endl;
            }
            break;
        case 4:
            num = 0;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            num = 0;
        }
        
    }
    //cout<< info[0].s.name;
    return 0;
}

// ques 5 write a program to manage studdent record of a claass with given capicity(dynamic ). the program should allow input for each student details including name , rollno. , cont no., ans marks of 
// 5 subject . the syetem should then compute and display 
// :1) detail of student contaning all the things
// 2) subject wise marks of the entire class.
// entry for the student must be dyanmic and in tabular format and calculate student wise,subj wise and total class;

// ques 1 and 3 done 
// ques 4 part 1)
// 