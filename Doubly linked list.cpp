#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int data){
			this->data=data;
			next=NULL;
			prev=NULL;
		}
};
void Display(Node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
void InsertAtHead(Node* &head,int x){
	Node* temp = new Node(x);
	temp->next = head;
	head->prev = temp;
	head=temp;
}
void InsertAtTail(Node* &head,int x){
	Node* n = new Node(x);
	Node* temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next = n;
	n->prev = temp;
}
void Delete(Node* &head,int pos){
	Node* temp = head;
	int count = 1;
	while(temp!=NULL && count!=pos){
		temp = temp->next;
		count++;
	}
	temp->prev->next=temp->next;
	if(temp->next!=NULL){
		temp->next->prev=temp->prev;
	}
	delete temp;
}
void DeleteAtHead(Node* &head){
	Node* todelete = head;
	head=head->next;
	head->prev=NULL;
	delete todelete;
}
int main()
{
	Node* node1 = new Node(10);
	InsertAtTail(node1,20);
	InsertAtTail(node1,30);
	InsertAtTail(node1,40);
	InsertAtHead(node1,0);
	Display(node1);
	return 0;
}
