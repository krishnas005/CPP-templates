#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* left;
		Node* right;
		Node(int data) {
			this->data = data;
			left = NULL;
			right = NULL;
		}
};

Node* insertIntoBST(Node* root,int data) {
	if(!root){
		return new Node(data);
	}
	else if(data > root->data) {
		root->right = insertIntoBST(root->right,data);
	} else {
		root->left = insertIntoBST(root->left,data);
	}
	return root;
}

void CreateTree(Node* &root) {
	int data;
	cout<<"Enter data: ";
	cin>>data;
	while(data != -1) {
		root = insertIntoBST(root,data);
		cout<<"Enter data: ";
		cin>>data;
	}
}

void Inorder(Node* root) {
	if(!root) return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main() {
	
	Node* root = NULL;
	CreateTree(root);
    
    cout<<"Inorder Traversal: ";
    
    Inorder(root);
    
    return 0;
}