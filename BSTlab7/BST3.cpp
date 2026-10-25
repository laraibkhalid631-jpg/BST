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

class BSTDeletion {
public:
    // Helper function to insert data into the BST
    Node* insert(Node* root, int val) {
        if (root == nullptr) return new Node(val);
        if (val < root->data) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }

    // Helper function to locate the minimum node value (In-order Successor)
    Node* findMin(Node* root) {
        Node* current = root;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Core function to delete a node containing target key from the BST
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) return root;

        // Step 1: Traversal to locate the target node to delete
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } 
        // Step 2: Key found! Execute deletion logic cases
        else {
            // CASE 1 & CASE 2: Node has No Child or Only One Child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // CASE 3: Node has Both Children (Two children)
            // Fetch the in-order successor (smallest item in right subtree)
            Node* temp = findMin(root->right);

            // Copy successor value over to this node
            root->data = temp->data;

            // Delete the duplicate successor node from the right subtree path
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // In-order traversal output sequence tracking utility
    void inOrder(Node* root) {
        if (root == nullptr) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
};

int main() {
    BSTDeletion bst;
    Node* root = nullptr;

    // Standard insertion baseline
    root = bst.insert(root, 50);
    bst.insert(root, 30);
    bst.insert(root, 70);
    bst.insert(root, 20);
    bst.insert(root, 40);
    bst.insert(root, 60);
    bst.insert(root, 80);

    cout << "Original BST (In-Order traversal): ";
    bst.inOrder(root);
    cout << "\n\n";

    // Scenario 1 Testing: Deleting a leaf node (Case 1: No children)
    cout << "Deleting 20 (Leaf Node)..." << endl;
    root = bst.deleteNode(root, 20);
    cout << "BST state: "; bst.inOrder(root); cout << "\n\n";

    // Scenario 2 Testing: Deleting a node with single child (Case 2: One child)
    cout << "Deleting 30 (Node with one child: 40)..." << endl;
    root = bst.deleteNode(root, 30);
    cout << "BST state: "; bst.inOrder(root); cout << "\n\n";

    // Scenario 3 Testing: Deleting a node with two children (Case 3: Two children)
    cout << "Deleting 50 (Root Node with two children)..." << endl;
    root = bst.deleteNode(root, 50);
    cout << "Final BST state: "; bst.inOrder(root); cout << "\n";

    return 0;
}

