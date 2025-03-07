#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int roll;
    float cgpa;
    Student* next;

    Student() {
        name = "";
        roll = 0;
        cgpa = 0.00;
        next = nullptr;
    }

    Student(const string& name1, int roll1, float cgpa1, Student* next1) {
        name = name1;
        roll = roll1;
        cgpa = cgpa1;
        next = next1;
    }

    Student(const string& name1, int roll1, float cgpa1) {
        name = name1;
        roll = roll1;
        cgpa = cgpa1;
        next = nullptr;
    }
};

Student* convertInfoToLinkedList(Student s[], int n) {
    if (n == 0) {
        return nullptr; // Empty list
    }

    Student* head = new Student(s[0].name, s[0].roll, s[0].cgpa);
    Student* tail = head;
    for (int i = 1; i < n; ++i) {
        Student* temp = new Student(s[i].name, s[i].roll, s[i].cgpa);
        tail->next = temp;
        tail = temp;
    }

    return head;
}

Student* deleteHead(Student* head) {
    if (head == nullptr) {
        return nullptr;
    }

   Student* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Student* deleteTail(Student* head) {
    if (head == nullptr || head->next == nullptr) {
        return deleteHead(head);
    }

    Student* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;

        
    }

    delete temp->next;
    temp->next = nullptr;
    return head;     
}

Student* deletek(Student* head, int k) {
    if (head == nullptr || k <= 0) {
        return head;
    }

    if (k == 1) {
        return deleteHead(head);
    }

    int cnt = 0;
    Student* prev = nullptr;
    Student* temp = head;
    while (temp != nullptr) {
        cnt++;
        if (cnt == k) {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Student* insertHead(Student* head, const string& name, int roll, float cgpa) {
    Student* temp = new Student(name, roll, cgpa, head);
    return temp;
}

Student* insertTail(Student* head, const string& name, int roll, float cgpa) {
    if (head == nullptr) {
        return new Student(name, roll, cgpa);
    }

    Student* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new Student(name, roll, cgpa);
    return head;
}

Student* insertk(Student* head, const string& name, int roll, float cgpa, int k) {
    if (head == nullptr) {
        if (k == 1) {
            return new Student(name, roll, cgpa);
        } else {
            return nullptr;
        }
    }

    if (k == 1) {
        return insertHead(head, name, roll, cgpa);
    }

    int cnt = 0;
    Student* temp = head;
    while (temp != nullptr) {
        cnt++;
        if (cnt == k - 1) {
            Student* newStudent = new Student(name, roll, cgpa);
            newStudent->next = temp->next;
            temp->next = newStudent;
            return head;
        }
        temp = temp->next;
    }

    return head; // If k is greater than the list's length
}



int main() {
   
    int n;
    int choice;
    string name;
       int roll;
            float cgpa;
            int k;


    cout << "Enter the number nodes you want: ";
    cin >> n;
    if(n<0){
        cout<<"enter +ve no. ";
    }
    

    Student s[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter name: ";
        cin >> s[i].name;
        cout << "Enter roll no: ";
        cin >> s[i].roll;
        cout << "Enter cgpa: ";
        cin >> s[i].cgpa;
    }

while(1){
    Student* head = convertInfoToLinkedList(s, n);

    cout << "Enter 1 to delete " << endl;
    cout << "Enter 2, to delete from end" << endl;
    cout << "Enter 3 to delete from any position " << endl;
    cout << "Enter 4 to insert at begin " << endl;
    cout << "Enter  5 to insert at end " << endl;
    cout << "Enter  6 to insert at any position " << endl;
    cout<<"enter 7 to display"<<endl;
    cout<<"enter 8 to exit"<<endl;
 
    
    cin >> choice;
    
    switch (choice) {
        case 1:
            head = deleteHead(head);
            break;
        case 2:
            head = deleteTail(head);
            break;
        case 3: {
            
            cout << "Enter the position of the node you want to delete: ";
            cin >> k;
            if(k<0){
                cout<<"enter +ve no.";
            }
            else if(k>n){
                cout<<"enter a valid value of k"<<endl;
            }
            head = deletek(head, k);
            break;
        }
        case 4: {
            
            cout << "Enter the name of the student: ";
            cin >> name;
            cout << "Enter the roll no of the student: ";
            cin >> roll;
            cout << "Enter the cgpa of the student: ";
            cin >> cgpa;
            head = insertHead(head, name, roll, cgpa);
            break;
        }
        case 5: {
            
            cout << "Enter the name of the student: ";
            cin >> name;
            cout << "Enter the roll no of the student: ";
            cin >> roll;
            cout << "Enter the cgpa of the student: ";
            cin >> cgpa;
            head = insertTail(head, name, roll, cgpa);
            break;
        }
     case 6: {
            
            cout << "Enter the name of the student: ";
            cin >> name;
            cout << "Enter the roll no of the student: ";
            cin >> roll;
            cout << "Enter the cgpa of the student: ";
            cin >> cgpa;

           
            {
                cout << "Enter the position to insert: ";
                cin >> k;

                if(k > n)
                {
                cout<<"not exist"<<endl;
                }
                else if(k < 0)
                {
                    cout<<"enter +ve no.\n";
                }
                
               
            }
            head = insertk(head, name, roll, cgpa, k);
            
            break;}
        case 7:{
          string name;
            int roll;
            float cgpa;
       
        }
         case 8:{
            exit(0);
            cout<<"exit "<<endl;
            break;
        } 
    

        default:
            cout << "Invalid choice." << endl;
    
    }
    

    // Print the linked list
    while (head != nullptr) {
        cout << "Name: " << head->name << endl;
        cout << "Roll: " << head->roll << endl;
        cout << "CGPA: " << head->cgpa << endl;
        head = head->next;
    }}

    return 0;
}
