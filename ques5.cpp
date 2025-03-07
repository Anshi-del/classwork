#include <iostream>
using namespace std;

// Node structure for the binary search tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a node into the BST
Node* insertNode(Node* root, char data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to perform post-order traversal
void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse left subtree
    postOrderTraversal(root->left);

    // Traverse right subtree
    postOrderTraversal(root->right);

    // Visit node
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int n;
    char value;

    cout << "Enter the number of characters to insert into the BST: ";
    cin >> n;

    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "Post-order Traversal of the BST: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
