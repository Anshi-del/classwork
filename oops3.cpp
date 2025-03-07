#include <bits/stdc++.h>
using namespace std;

struct Employee
{
    string name;
    string empid;
    float salary;
};

union Calculate
{
    float bonus;
    float loan;
};

class Details
{
private:
    Employee e;
    Calculate c;
    int choice;

public:
    void AddEmployee()
    {
        cout << "Enter name:";
        getline(cin, e.name); // input stream func, save the input,delimiter 
        if ((all_of(e.name.begin(), e.name.end(), ::isdigit)))
        {
            cout << "Name cannot be number. Please enter name" << endl;
            getline(cin, e.name);
        }

        cout << "Enter ID:";
        getline(cin, e.empid);
        cout << "Enter salary:";
        while (true)
        {
            cin >> e.salary;

            // Check if input is invalid
            if (cin.fail())
            {
                cin.clear();                                                   // Clear the error flag
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter a number: ";
            }
            else
            {
                break; // Input is valid, exit loop
            }
        }

        cin.ignore(); // cin buffer clear

        cout << "Enter loan(1) or bonus(2):";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter loan:";
            while (true)
            {
                cin >> c.loan;

                // Check if input is invalid
                if (cin.fail())
                {
                    cin.clear();                                                   // Clear the error flag
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. Please enter a number: ";
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
            cout << "Enter bonus:";
            while (true)
            {
                cin >> c.bonus;

                // Check if input is invalid
                if (cin.fail())
                {
                    cin.clear();                                                   // Clear the error flag
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. Please enter a number: ";
                }
                else
                {
                    break; // Input is valid, exit loop
                }
            }
            cin.ignore();
        }
    }
    void DisplayEmployee()
    {
        cout << "Name:" << e.name << " ";
        cout << "ID:" << e.empid << " ";
        cout << "Salary:" << e.salary << " ";
        if (choice == 1)
        {
            cout << "Loan:" << c.loan << " ";
        }
        else
        {
            cout << "Bonus:" << c.bonus << " ";
        }
    }
    void netSalary()
    {
        cout << e.name << " ";
        cout << "Net Salary:";

        if (choice == 1)
        {
            cout << e.salary - c.loan;
        }
        else if (choice == 2)
        {
            cout << e.salary + c.bonus;
        }
    }
};

int main()
{
    int num = 1;
    vector<Details> emp;
    int choose;
    int n;
    while (num)
    {
        cout << "Enter 1 to add employees:" << endl;
        cout << "Enter 2 to display employee details:" << endl;
        cout << "Enter 3 to print net salary:" << endl;
        cout << "Enter 4 to exit" << endl;
        cout << "Enter here :";
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "Enter the number of employee: ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                Details fd;
                fd.AddEmployee();
                emp.push_back(fd);
            }
            break;
        case 2:
            for (auto employee : emp)
            {
                employee.DisplayEmployee();
                cout << endl;
            }
            break;
        case 3:
            for (auto employee : emp)
            {
                employee.netSalary();
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
    return 0;
}