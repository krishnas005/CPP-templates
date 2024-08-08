#include<iostream>
#include<queue>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int data){
			this->data=data;
			right=NULL;
			left=NULL;
		}
};
Node* CreateTree(Node* root){
	int data;
	cout<<"Enter the data: ";
	cin>>data;
	root = new Node(data);
	if(data==-1){
		return NULL;
	}
	cout<<"Enter data for inserting in left of "<<data<<" =>"<<endl;
	root->left = CreateTree(root->left);
	cout<<"Enter data for inserting in right of "<<data<<" =>"<<endl;
	root->right = CreateTree(root->right);
	return root;
}
Node* LevelOrdertraversal(Node* root){
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}
void Inorder(Node* root){
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
void Preorder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}
void Postorder(Node* root){
	if(root==NULL){
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}
int main()
{
	Node* root = NULL;
	root = CreateTree(root);
	cout<<"Level order traversal is as follows: "<<endl;
	LevelOrdertraversal(root);
    cout<<"\nInorder traversal is as follows: "<<endl;
	Inorder(root);
	cout<<"\nPreorder traversal is as follows: "<<endl;
    Preorder(root);
    cout<<"\nPostorder traversal is as follows: "<<endl;
    Postorder(root);
	return 0;
}
