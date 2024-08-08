#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
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
Node* createTree() {
	int data;
	cout<<"Enter data: ";
	cin>>data;
	Node* root = new Node(data);
	if(data == -1) return NULL;
	cout<<"Enter data for left of "<<data<<": ";
	root->left = createTree();
	cout<<"Enter data for right of "<<data<<": ";
	root->right = createTree();
	return root;
}
void Inorder(Node* root) {
	if(root == NULL) return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
void Preorder(Node* root) {
	if(root == NULL) return;
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}
void Postorder(Node* root) {
	if(root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}
void LevelOrder(Node* root) {
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();
		if(temp == NULL) {
			cout<<endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout<<temp->data<<" ";
			if(temp->left) {
				q.push(temp->left);
			}
			if(temp->right) {
				q.push(temp->right);
			}
		}
	}
}
void levelOrder(Node* root) {
	queue<Node*>q;
	q.push(root);
	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left) {
			q.push(temp->left);
		}
		if(temp->right){
		    q.push(temp->right);
		}
	}
}
vector<int>ans;
void leftView(Node* root,int level) {
	if(root == NULL) return;
	if(ans.size() == level) {
		ans.push_back(root->data);
	}
	leftView(root->left,level+1);
	leftView(root->right,level+1);
}
vector<int>res;
void rightView(Node* root, int level) {
	if(root == NULL) return;
	if(res.size() == level) {
		res.push_back(root->data);
	}
	rightView(root->right,level+1);
	rightView(root->left,level+1);
}
void topView(Node* root) {
	map<int,int> mp;
	queue<pair<Node*,int>> q;
	q.push(make_pair(root,0));
	
	while(!q.empty()) {
		
		pair<Node*,int>temp = q.front();
		q.pop();
		
		Node* frontNode = temp.first;
		int hd = temp.second;
		
		if(mp.find(hd) == mp.end()) {
			mp[hd] = frontNode->data;
		}
		
		if(frontNode->left) {
			q.push(make_pair(frontNode->left,hd-1));
		}
		
		if(frontNode->right) {
			q.push(make_pair(frontNode->right,hd+1));
		}
	}
	for(auto i:mp) {
		cout<<i.second<<" ";
	}
}
void bottomView(Node* root) {
	map<int,int> mp;
	queue<pair<Node*,int>> q;
	q.push(make_pair(root,0));
	
	while(!q.empty()) {
		
		pair<Node*,int>temp = q.front();
		q.pop();
		
		Node* frontNode = temp.first;
		int hd = temp.second;
		
		mp[hd] = frontNode->data;
		
		if(frontNode->left) {
			q.push(make_pair(frontNode->left,hd-1));
		}
		
		if(frontNode->right) {
			q.push(make_pair(frontNode->right,hd+1));
		}
	}
	for(auto i:mp) {
		cout<<i.second<<" ";
	}
}
void leftBoundary(Node* root) {
	if(root == NULL) return;
	if(root->left == NULL && root->right == NULL) {
		return;
	}
	cout<<root->data<<" ";
	// only go to left if it is possible to go on left
	if(root->left != NULL) {
		leftBoundary(root->left);
	}
	//agr left mn ja chuke toh right mn mt jao or agr nhi gye toh he jao #sirf ek jgha he jaana hai
	else {
		leftBoundary(root->right);
	}
}
void leafBoundary(Node* root) {
	if(root == NULL) return;
	if(root->left == NULL && root->right == NULL) {
		cout<<root->data<<" ";
	}
	leafBoundary(root->left);
	leafBoundary(root->right);
}
void rightBoundary(Node* root) {
	if(root == NULL) return;
	if(root->left == NULL && root->right == NULL) {
		return;
	}
	if(root->right!=NULL) {
		rightBoundary(root->right);
	} else {
		rightBoundary(root->left);
	}
	cout<<root->data<<" ";
}
void boundaryView(Node* root) {
	if(root == NULL) return;
	cout<<root->data;
	leftBoundary(root->left);
	leafBoundary(root->left);
	leafBoundary(root->right);
	rightBoundary(root->right);
}
int main() {
	Node* root = NULL;
	root = createTree();
	cout<<"Inorder Traversal: ";
	Inorder(root);
	cout<<endl;
	cout<<"Preorder Traversal: ";
	Preorder(root);
	cout<<endl;
	cout<<"Postorder Traversal: ";
	Postorder(root);
	cout<<endl;
	cout<<"Level Order Traversal: ";
	cout<<endl;
	LevelOrder(root);
	cout<<endl;
	cout<<"Level Order Traversal: ";
	levelOrder(root);
	cout<<endl;
	cout<<"Left View of Tree: ";
	int level = 0;
	leftView(root,level);
	for(auto i: ans) {
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<"Right View of Tree: ";
	rightView(root,level);
	for(auto i: res) {
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<"Top View of Tree: ";
	topView(root);
	cout<<endl;
	cout<<"Bottom View of Tree: ";
	bottomView(root);
	cout<<endl;
	cout<<"Boundary View of Tree: ";
	boundaryView(root);
	return 0;
}

// 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1