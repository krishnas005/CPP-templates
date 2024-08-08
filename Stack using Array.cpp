#include<iostream>
using namespace std;

class Stack{
	public:
		int size;
		int top;
		int *arr;
};
void Create(Stack* st){
	int size;
	cout<<"Enter size: ";
	cin>>st->size;
	st->top = -1;
	st->arr = new int[st->size];
}
void Display(Stack st){
	for(int i=st.top;i>=0;i--){
		cout<<st.arr[i]<<endl;
	}
}
void push(Stack* st,int x){
	if(st->top==st->size-1){
		cout<<"Stack Overflowed!!"<<endl;
	}
	else{
		st->top++;
		st->arr[st->top] = x;
	}
}
void pop(Stack* st){
	int x=-1;
	if(st->top==-1){
		cout<<"Stack Underflown!!"<<endl;
	}
	else{
		st->arr[st->top--] = x;
	}
}
int peek(Stack st,int index){
	int x = -1;
	if(st.top-index+1<=0){
		cout<<"Invalid Index!!"<<endl;
	}
	else{
		x = st.arr[st.top-index+1];
	}
	return x;
}
bool isEmpty(Stack st){
	if(st.top==-1){
		return true;
	}
	else{
		return false;
	}
}
int isFull(Stack st){
	return st.top == st.size-1;
}
int StackTop(Stack st){
	if(!isEmpty(st)){
		return st.arr[st.top];
	}
	else{
		return -1;
	}
}
int main()
{
	Stack st;
	Create(&st);
	push(&st,10);
	push(&st,15);
	push(&st,20);
	push(&st,25);
//	pop(&st);
	Display(st);
//	cout<<isEmpty(st);
	return 0;
}
