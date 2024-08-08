#include<iostream>
#include<stdio.h>
using namespace std;
class Array{
	public:
		int A[10];	
		int size;
		int length;
};
void display(Array arr){
	cout<<"Elements are: ";
	for(int i=0;i<arr.length;i++){
		cout<<arr.A[i]<<" ";
	}
}
void insert(Array *arr,int index,int data){
	for(int i=arr->length;i>index;i--){
		arr->A[i]=arr->A[i-1];
	}
	arr->length++;
	arr->A[index]=data;
}
void append(Array *arr,int x){
	if(arr->length<arr->size){
		arr->A[arr->length++]=x;
	}
}
void Delete(Array *arr,int index){
	for(int i=index;i<arr->length-1;i++){
		arr->A[i]=arr->A[i+1];

	}
	arr->length--;
}
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void reverse(Array *arr){
	int s=arr->length,j;
	for(int i=0,j=arr->length-1;i<j;i++,j--){
		swap(arr->A[i],arr->A[j]);
	}
}
int main()
{
	Array arr={{1,2,3,4,5,6},10,5};
//    insert(&arr,2,6);
//    append(&arr,6);
//    Delete(&arr,2);
    reverse(&arr);
	display(arr);
	return 0;
}
