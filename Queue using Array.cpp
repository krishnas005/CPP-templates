#include<iostream>
#define n 100
using namespace std;
class Queue{
	int front;
	int back;
	int arr[n];
	public:
		Queue(){
			front=-1;
			back=-1;
		}
		bool isEmpty(){
			return(front==-1 && back==-1);
		}
		bool isFull(){
			return(back==n-1);
		}
		void push(int x){
			if(isFull()){
				cout<<"Queue is FULL!!"<<endl;
				return;
			}
			back++;
			arr[back]=x;
			if(front==-1){
				front++;
			}
		}
		void pop(){
			if(isEmpty()){
				cout<<"Queue is EMPTY!!"<<endl;
				return;
			}
			front++;
		}
		int peek(){
			if(isEmpty()){
				cout<<"Queue is EMPTY!! "<<endl;
				return -1;
			}
			return arr[front];
		}
};
int main()
{
	Queue q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	return 0;
}
