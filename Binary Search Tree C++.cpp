#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
    	this->val = val;
    	left = NULL;
    	right = NULL;
	}
	
};

class BinarySearchTree {
	
public:
    Node* root;

    Node* insert(Node* node, int data) {
    	
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->val) {
            node->left = insert(node->left, data);
        } else if (data > node->val) {
            node->right = insert(node->right, data);
        }

        return node;
    }

    bool search(Node* node, int key) const {
        if (node == nullptr) {
            return false;
        }

        if (key == node->val) {
            return true;
        } else if (key < node->val) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
        
    }

    void inOrderTraversal(Node* node) const {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->val << " ";
            inOrderTraversal(node->right);
        }
    }

//public:
//    BinarySearchTree() : root(nullptr) {}
//
//    void insert(int key) {
//        root = insertRecursive(root, key);
//    }
//
//    bool search(int key) const {
//        return searchRecursive(root, key);
//    }
//
//    void inOrderTraversal() const {
//        inOrderTraversal(root);
//        cout << std::endl;
//    }
};

int main() {
	
    BinarySearchTree bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(6);
    bst.insert(12);
    bst.insert(30);
    bst.insert(7);
    bst.insert(17);

    cout << "In-order traversal: ";
    bst.inOrderTraversal();

    int keyToSearch = 6;
    if (bst.search(keyToSearch)) {
        cout << keyToSearch << " is present in the BST." << std::endl;
    } else {
        cout << keyToSearch << " is not present in the BST." << std::endl;
    }

    return 0;
}
