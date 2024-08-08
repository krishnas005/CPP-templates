#include<iostream>
#include<stack>
using namespace std;
class Queue{
	private:
		stack<int>s1;
		stack<int>s2;
	public:
		void push(int x){
			s1.push(x);
		}
		void pop(){
			if(s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
			if(s2.empty() && s1.empty()){
				cout<<"Queue is Empty!!"<<endl;
				return;
			}
			s2.pop();
		}
		int peek(){
			if(s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
			if(s1.empty() && s2.empty()){
				cout<<"Queue is Empty!!"<<endl;
				return -1;
			}	
			return s2.top();
		}
		bool isEmpty(){
				return s1.empty() && s2.empty();
		}
};
int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "Front element: " << q.peek() << endl;
    q.pop();
    q.pop();
    cout << "Front element: " << q.peek() << endl;
    return 0;
}
