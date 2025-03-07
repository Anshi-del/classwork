#include <iostream>
#include <stack>
using namespace std;

// Node structure for the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to perform non-recursive in-order traversal
void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    stack<Node*> s;
    Node* current = root;

    while (!s.empty() || current != nullptr) {
        // Reach the leftmost Node of the current Node
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Current must be nullptr at this point
        current = s.top();
        s.pop();
        cout << current->data << " ";

        // We have visited the node and its left subtree. Now, visit the right subtree.
        current = current->right;
        
    }
}

int main() {
    Node* root = nullptr;

    int n, value;
    cout << "Enter the number of elements to insert into the BST: ";
    cin >> n;

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "In-order traversal of the BST (non-recursive): ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
