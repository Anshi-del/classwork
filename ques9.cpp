// #include <iostream>
// #include <vector>
// using namespace std;

// // Node structure for the B-Tree
// class BTreeNode {
// public:
//     vector<int> keys;     // Vector of keys
//     vector<BTreeNode*> children; // Vector of child pointers
//     int t;                // Minimum degree
//     bool isLeaf;          // True if leaf node

//     BTreeNode(int t, bool isLeaf);
//     void insertNonFull(int key);
//     void splitChild(int i, BTreeNode* child);
//     void traverse();
// };

// class BTree {
// public:
//     BTreeNode* root;
//     int t;  // Minimum degree

//     BTree(int t);
//     void insert(int key);
//     void traverse() {
//         if (root != nullptr) root->traverse();
//     }
// };

// BTreeNode::BTreeNode(int t, bool isLeaf)
//     : t(t), isLeaf(isLeaf) {}

// // Traverse all nodes in the B-Tree
// void BTreeNode::traverse() {
//     for (int i = 0; i < keys.size(); ++i) {
//         if (!isLeaf) {
//             children[i]->traverse();
//         }
//         cout << keys[i] << " ";
//     }
//     if (!isLeaf) {
//         children.back()->traverse();
//     }
// }

// // Insert a key into a non-full node
// void BTreeNode::insertNonFull(int key) {
//     int i = keys.size() - 1;

//     if (isLeaf) {
//         while (i >= 0 && keys[i] > key) {
//             i--;
//         }
//         keys.insert(keys.begin() + i + 1, key);
//     } else {
//         while (i >= 0 && keys[i] > key) {
//             i--;
//         }
//         if (children[i + 1]->keys.size() == 2 * t - 1) {
//             splitChild(i + 1, children[i + 1]);
//             if (keys[i + 1] < key) {
//                 i++;
//             }
//         }
//         children[i + 1]->insertNonFull(key);
//     }
// }

// // Split the child node when it is full
// void BTreeNode::splitChild(int i, BTreeNode* child) {
//     BTreeNode* newChild = new BTreeNode(child->t, child->isLeaf);
//     for (int j = 0; j < t - 1; ++j) {
//         newChild->keys.push_back(child->keys[j + t]);
//     }
//     if (!child->isLeaf) {
//         for (int j = 0; j < t; ++j) {
//             newChild->children.push_back(child->children[j + t]);
//         }
//     }
//     child->keys.resize(t - 1);
//     child->children.resize(t);

//     children.insert(children.begin() + i + 1, newChild);
//     keys.insert(keys.begin() + i, child->keys[t - 1]);
// }

// BTree::BTree(int t) : t(t), root(nullptr) {}

// void BTree::insert(int key) {
//     if (!root) {
//         root = new BTreeNode(t, true);
//         root->keys.push_back(key);
//     } else {
//         if (root->keys.size() == 2 * t - 1) {
//             BTreeNode* newRoot = new BTreeNode(t, false);
//             newRoot->children.push_back(root);
//             newRoot->splitChild(0, root);
//             int i = (newRoot->keys[0] < key) ? 1 : 0;
//             newRoot->children[i]->insertNonFull(key);
//             root = newRoot;
//         } else {
//             root->insertNonFull(key);
//         }
//     }
// }

// int main() {
//     int t;
//     cout << "Enter minimum degree of B-Tree: ";
//     cin >> t;

//     BTree bTree(t);
//     int n, key;

//     cout << "Enter number of elements to insert: ";
//     cin >> n;

//     cout << "Enter the elements:" << endl;
//     for (int i = 0; i < n; ++i) {
//         cin >> key;
//         bTree.insert(key);
//     }

//     cout << "B-Tree traversal: ";
//     bTree.traverse();
//     cout << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at index `i`
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;         // Initialize largest as root
    int left = 2 * i + 1;    // Left child
    int right = 2 * i + 2;   // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Heap Sort algorithm
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);  // Move current root to the end
        heapify(arr, i, 0);    // Call heapify on the reduced heap
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    heapSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
