#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
};
int main()
{
    int a;
    cin >> a;

    Node *n1 = new Node();
    n1->data = 1;
    Node *head = n1;
    Node *n2 = new Node();
    n2->data = 2;
    n1->next = n2;
   

        // Insertion at the start

        Node *start = new Node();
        start->data = 0;
        start->next = head;
        head = start;
        

    // Insertion at the end
 
        Node *end = new Node();
        end->data = 7;
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = end;
        temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        

        return 0;
    }
