#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
	
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        cout << "Popped " << temp->data << " from the stack." << endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1;
        }

        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << std::endl;
            return;
        }

        Node* current = top;
        cout << "Stack: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();

    return 0;
}
