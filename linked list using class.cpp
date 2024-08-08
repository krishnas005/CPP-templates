#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data=data;
			next=NULL;
		}
};
void InsertAtTail(Node* &head,int d){
	Node* n = new Node(d);
	Node* temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}
void InsertAtHead(Node* &head,int d){
	Node* n = new Node(d);
	n->next=head;
	head=n;
}
void Delete(Node* &head,int d){
	Node* temp = head;
	while(temp->next->data!=d){
		temp=temp->next;
	}
	Node* todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
}
void print(Node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
bool Search(Node* head, int key){
	Node* temp = head;
	while(temp!=NULL){
		if(temp->data==key){
			return true;
		}
		temp=temp->next;
    }
		return false;	
}
Node* Reverse(Node* &head){
	Node* prevptr = NULL;
	Node* currptr = head;
	Node* nextptr;
	while(currptr!=NULL){
		nextptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
	}
	return prevptr;
}
void Reverse(Node* &head){
	Node* prevptr = NULL;
	Node* currptr = head;
	Node* nextptr;
	while(currptr!=NULL){
		nextptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
	}
	head = prevptr;
}
Node* Reverse(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        Node* prevptr = NULL;
        Node* temp = reverseList(head->next);
        head->next->next = head;
        head->next = prevptr;
        return temp;
    }

Node* kNodeReverse(Node* &head,int k){
	Node* prevptr = NULL;
	Node* currptr = head;
	Node* nextptr;
	int count = 0;
	while(currptr!=NULL && count<k){
		nextptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
		count++;
	}
	if(nextptr!=NULL){
		head->next = kNodeReverse(nextptr,k);
	}
	return prevptr;
}
int count(Node* head){
	int count = 0;
	while(head!=NULL){
		count++;
		head = head->next;
	}
	return count;
}
int sum(Node* head){
	int sum=0;
	while(head!=NULL){
		sum+=head->data;
		head=head->next;
	}
	return sum;
}

int MaxElement(Node* head){
	int max= -32768;
	while(head!=NULL){
		if(head->data > max)
			max = head->data;
		head=head->next;
	}
	return max;
}
bool isLoop(Node* head){
	Node *fast,*slow;
	fast=slow=head;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow){
			return true;
		}
	}
	return false;
}
bool isSorted(Node* head){
	Node* temp=head;
	while(temp->next!=NULL){
		if(temp->data>=temp->next->data){
			return false;
		}
		temp=temp->next;
	}
	return true;
}
Node* SortedDuplicate(Node* &head){
	Node* temp = head;
	while(temp->next!=NULL){
		if(temp->data==temp->next->data){
			Node* todelete = temp->next;
			temp->next=temp->next->next;
			delete todelete;
		}
		else{
			temp=temp->next;
		}
	}
	return head;
}
Node* mergeSortedList(Node* head1,Node* head2){
	Node* p1 = head1;
	Node* p2 = head2;
	Node* NewNode = new Node(-1);
	Node* p3 = NewNode;
	while(p1!=NULL && p2!=NULL){
		if(p1->data < p2->data){
			p3->next=p1;
			p1=p1->next;
			p3=p3->next;
		}
		else{
			p3->next=p2;
			p2=p2->next;
			p3=p3->next;
		}
	}
	while(p1!=NULL){
		p3->next=p1;
		p1=p1->next;
		p3=p3->next;
	}
	while(p2!=NULL){
		p3->next=p2;
		p2=p2->next;
		p3=p3->next;
	}
	return NewNode->next;
}
int main(){
	Node* node1 = new Node(10);
	InsertAtTail(node1,12);
	InsertAtTail(node1,14);
	InsertAtTail(node1,16);
	InsertAtHead(node1,8);
	InsertAtHead(node1,6);
	print(node1);
//	Reverse(node1);
//	Node* ReversedNode = Reverse(node1);
//	print(ReversedNode);
//  Node* NewHead = kNodeReverse(node1,k);
//  print(NewHead);
    cout<<"Number of Nodes: "<<count(node1)<<endl;
    cout<<"The sum of elements of Nodes: "<<sum(node1)<<endl;
    cout<<"The Maximum element is: "<<MaxElement(node1)<<endl;
	return 0;
}
