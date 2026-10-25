#include <iostream>
using namespace std;

// Structure defining a Binary Tree Node
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

class BinaryTree {
public:
    // 1. Pre-Order Traversal with Right Priority: Node -> Right -> Left (NRL)
    void preOrderNRL(Node* root) {
        if (root == nullptr) return;

        cout << root->data << " ";      // Process Current Node (N)
        preOrderNRL(root->right);       // Traverse Right Subtree First (R)
        preOrderNRL(root->left);        // Traverse Left Subtree Second (L)
    }

    // 2. In-Order Traversal with Right Priority: Right -> Node -> Left (RNL)
    void inOrderRNL(Node* root) {
        if (root == nullptr) return;

        inOrderRNL(root->right);        // Traverse Right Subtree First (R)
        cout << root->data << " ";      // Process Current Node (N)
        inOrderRNL(root->left);         // Traverse Left Subtree Second (L)
    }

    // 3. Post-Order Traversal with Right Priority: Right -> Left -> Node (RLN)
    void postOrderRLN(Node* root) {
        if (root == nullptr) return;

        postOrderRLN(root->right);      // Traverse Right Subtree First (R)
        postOrderRLN(root->left);       // Traverse Left Subtree Second (L)
        cout << root->data << " ";      // Process Current Node (N)
    }
};

int main() {
    // Constructing a sample Binary Tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    BinaryTree tree;

    cout << "Pre-Order (NRL):  ";
    tree.preOrderNRL(root);
    cout << "\nIn-Order (RNL):   ";
    tree.inOrderRNL(root);
    cout << "\nPost-Order (RLN): ";
    tree.postOrderRLN(root);
    cout << endl;

    return 0;
}

