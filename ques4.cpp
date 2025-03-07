#include <bits/stdc++.h>
using namespace std;

// Deque Implementation using Array
class dqimpl_array {
public:
    int start = -1;
    int end = -1;
    int currsize = 0;
   int size = 6;
   int dq[6];


    void push_front(int x) {
        if (currsize == size) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (currsize == 0) {
            start = end = 0;
            dq[start] = x;
        } else {
            start = (start - 1 + size) % size;
            dq[start] = x;
        }
        currsize++;
    } 

    void delete_front() {
        if (currsize == 0) {
            cout << "Underflow" << endl;
            return;
        }
        start = (start + 1) % size;
        currsize--;
        if (currsize == 0) {
            start = end = -1;
        }
    }

    void push_back(int x) {
        if (currsize == size) {
            cout << "Overflow" << endl;
            return;
        }
        if (currsize == 0) {
            start = end = 0;
            dq[end] = x;
        } else {
            end = (end + 1) % size;
            dq[end] = x;
        }
        currsize++;
    }

    void delete_back() {
        if (currsize == 0) {
            cout << "Underflow" << endl;
            return;
        }
        end = (end - 1 + size) % size;
        currsize--;
        if (currsize == 0) {
            start = end = -1;
        }
    }

    void display() {
        if (currsize == 0) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deque elements: ";
        int i = start;
        for (int count = 0; count < currsize; count++) {
            cout << dq[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

class dqimpl {
public:
    int data;
    dqimpl* next;

    dqimpl(int data1, dqimpl* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

class Deque {
private:
    dqimpl* head;
    int size;

public:
    Deque() {
        head = nullptr;
        size = 0;
    }

    void push_front(int x) {
        if (head == nullptr) {
            head = new dqimpl(x);
        } else {
            dqimpl* new_node = new dqimpl(x);
            new_node->next = head;
            head = new_node;
        }
        size++;
    }

    void delete_front() {
        if (head == nullptr) {
            cout << "Deque is empty!" << endl;
        } else {
            dqimpl* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    void push_back(int x) {
        if (head == nullptr) {
            head = new dqimpl(x);
        } else {
            dqimpl* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            dqimpl* new_node = new dqimpl(x);
            temp->next = new_node;
        }
        size++;
    }

    void delete_back() {
        if (head == nullptr) {
            cout << "Deque is empty!" << endl;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            size--;
        } else {
            dqimpl* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            size--;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Deque is empty!" << endl;
            return;
        }
        dqimpl* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int get_size() {
        return size;
    }
};

int main() {
    int choice;
    cout << "Choose Deque Implementation:\n1. Array\n2. Linked List\n";
    cin >> choice;

    if (choice == 1) {
        dqimpl_array dq;
        int choice, x;
        while (true) {
            cout << "\n Deque Operations using Array " << endl;
            cout << "1. Push Front" << endl;
            cout << "2. Push Back" << endl;
            cout << "3. Delete Front" << endl;
            cout << "4. Delete Back" << endl;
            cout << "5. Display" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter element to push at front: ";
                    cin >> x;
                    dq.push_front(x);
                    break;

                case 2:
                    cout << "Enter element to push at back: ";
                    cin >> x;
                    dq.push_back(x);
                    break;

                case 3:
                    dq.delete_front();
                    break;

                case 4:
                    dq.delete_back();
                    break;

                case 5:
                    dq.display();
                    break;

                case 6:
                    cout << "EXITED" << endl;
                    return 0;

                default:
                    cout << "Invalid choice, please try again!" << endl;
            }
        }
    } else if (choice == 2) {
        Deque dq;
        int choice, x;
        while (true) {
            cout << "\n Deque Operations using Linked List " << endl;
            cout << "1. Push Front" << endl;
            cout << "2. Push Back" << endl;
            cout << "3. Delete Front" << endl;
            cout << "4. Delete Back" << endl;
            cout << "5. Display" << endl;
            cout << "6. Get Size" << endl;
            cout << "7. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter element to push at front: ";
                    cin >> x;
                    dq.push_front(x);
                    break;

                case 2:
                    cout << "Enter element to push at back: ";
                    cin >> x;
                    dq.push_back(x);
                    break;

                case 3:
                    dq.delete_front();
                    break;

                case 4:
                    dq.delete_back();
                    break;

                case 5:
                    dq.display();
                    break;

                case 6:
                    cout << "Size of deque: " << dq.get_size() << endl;
                    break;

                case 7:
                    cout << "EXITED." << endl;
                    return 0;

                default:
                    cout << "Invalid choice, please try again!" << endl;
            }
        }
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}