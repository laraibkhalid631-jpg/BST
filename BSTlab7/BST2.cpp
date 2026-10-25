#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BSTLeafOperations {
public:
    // Helper function to insert data into the Binary Search Tree
    Node* insert(Node* root, int val) {
        if (root == nullptr) return new Node(val);
        if (val < root->data) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }

    // Function that prints leaf node values and keeps track of the total count
    void printAndCountLeafNodes(Node* root, int &count) {
        if (root == nullptr) return;

        // Condition checking if the current node has no children (Leaf Node)
        if (root->left == nullptr && root->right == nullptr) {
            cout << root->data << " ";
            count++;
            return;
        }

        // Recursively traverse both left and right branches
        printAndCountLeafNodes(root->left, count);
        printAndCountLeafNodes(root->right, count);
    }
};

int main() {
    BSTLeafOperations bst;
    Node* root = nullptr;

    // Building a sample BST
    root = bst.insert(root, 50);
    bst.insert(root, 30);
    bst.insert(root, 70);
    bst.insert(root, 20);
    bst.insert(root, 40);
    bst.insert(root, 60);
    bst.insert(root, 80);

    int leafCount = 0;
    cout << "Leaf Nodes in the BST: ";
    bst.printAndCountLeafNodes(root, leafCount);
    
    cout << "\nTotal Count of Leaf Nodes: " << leafCount << endl;

    return 0;
}

