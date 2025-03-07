

#include <iostream>

using namespace std;


struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


TreeNode* insert(TreeNode* root, char value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


void preorder(TreeNode* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    TreeNode* root = nullptr;
    char value;
    char choice;

    cout << "Enter characters to insert into the BST (enter '1' to quit):" << endl;

    while (true) {
        cin >> value;
        if (value == '1') {
            break;
        }
        root = insert(root, value);
    }

    cout << "Inorder Traversal of your entered characters : ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal of  entered characters: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal of entered characters: ";
    postorder(root);
    cout << endl;

    return 0;
}

