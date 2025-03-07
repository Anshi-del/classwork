#include <iostream>
#include <string>

using namespace std;


struct Node {
    string name;
    int rollNo;
    float cgpi;
    Node* next;
    Node* prev;

    Node(string n, int r, float c) {
        name = n;
        rollNo = r;
        cgpi = c;
        next = nullptr;
        prev = nullptr;
    }
};


class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int count;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    
    void createList(int numberOfNodes) {
        string name;
        int rollNo;
        float cgpi;
        for (int i = 0; i < numberOfNodes; i++) {
            cout << "Enter the name, roll number, and CGPI for student " << i + 1 << ": ";
            cin >> name >> rollNo >> cgpi;
            insertEnd(name, rollNo, cgpi);
        }
    }

    
    void insertStart(string name, int rollNo, float cgpi) {
        Node* newNode = new Node(name, rollNo, cgpi);
        if (!head) { 
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
        cout << "Node inserted at the start." << endl;
    }

    void insertEnd(string name, int rollNo, float cgpi) {
        Node* newNode = new Node(name, rollNo, cgpi);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
        cout << "Node inserted at the end." << endl;
    }

    
    void insertAtPosition(string name, int rollNo, float cgpi, int position) {
        if (position < 1 || position > count + 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (position == 1) {
            insertStart(name, rollNo, cgpi);
            return;
        }
        if (position == count + 1) {
            insertEnd(name, rollNo, cgpi);
            return;
        }
        Node* newNode = new Node(name, rollNo, cgpi);
        Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        count++;
        cout << "Node inserted at position " << position << "." << endl;
    }

   
    void deleteStart() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        count--;
        cout << "Node deleted from the start." << endl;
    }

   
    void deleteEnd() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        count--;
        cout << "Node deleted from the end." << endl;
    }

   
    void deleteAtPosition(int position) {
        if (position < 1 || position > count) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (position == 1) {
            deleteStart();
            return;
        }
        if (position == count) {
            deleteEnd();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        count--;
        cout << "Node deleted at position " << position << "." << endl;
    }

    void displayList() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << "Name: " << temp->name << ", Roll No: " << temp->rollNo << ", CGPI: " << temp->cgpi << endl;
            temp = temp->next;
        }
    }

    void menu() {
        int choice, subChoice, numberOfNodes, position;
        string name;
        int rollNo;
        float cgpi;

        do {
            cout << "\nMENU:\n";
            cout << "1. Create List\n";
            cout << "2. Insert into List\n";
            cout << "3. Delete from List\n";
            cout << "4. Display List\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter the number of nodes to create: ";
                    cin >> numberOfNodes;
                    createList(numberOfNodes);
                    break;
                case 2:
                    cout << "Insertion Menu:\n";
                    cout << "1. Insert at Start\n";
                    cout << "2. Insert at Position\n";
                    cout << "3. Insert at End\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;
                    cout << "Enter the name, roll number, and CGPI: ";
                    cin >> name >> rollNo >> cgpi;
                    if (subChoice == 1) {
                        insertStart(name, rollNo, cgpi);
                    } else if (subChoice == 2) {
                        cout << "Enter the position to insert: ";
                        cin >> position;
                        insertAtPosition(name, rollNo, cgpi, position);
                    } else if (subChoice == 3) {
                        insertEnd(name, rollNo, cgpi);
                    } else {
                        cout << "Invalid choice!" << endl;
                    }
                    break;
                case 3:
                    cout << "Deletion Menu:\n";
                    cout << "1. Delete from Start\n";
                    cout << "2. Delete from Position\n";
                    cout << "3. Delete from End\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;
                    if (subChoice == 1) {
                        deleteStart();
                    } else if (subChoice == 2) {
                        cout << "Enter the position to delete: ";
                        cin >> position;
                        deleteAtPosition(position);
                    } else if (subChoice == 3) {
                        deleteEnd();
                    } else {
                        cout << "Invalid choice!" << endl;
                    }
                    break;
                case 4:
                    displayList();
                    break;
                case 5:
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
        } while (choice != 5);
    }
};

// Main function to run the program
int main() {
    DoublyLinkedList list;
    list.menu();
    return 0;
}
