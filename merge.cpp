#include<iostream>
using namespace std;
class Array{
	public:
		int A[20];
		int size;
		int length;
};
void display(Array arr){
	cout<<"Elements are: ";
	for(int i=0;i<arr.length;i++){
		cout<<arr.A[i]<<" ";
	}
}
Array* merge(Array *arr1,Array *arr2){
	int i,j,k;
	i=j=k=0;
	 *arr3= new int(20);
	while(i<arr1->length && j<arr2->length){
		if(arr1->A[i]<arr2->A[j]){
			arr3->A[k++]=arr1->A[i++];
		}
		else{
			arr3->A[k++]=arr2->A[j++];
		}
	}
	for(;i<arr1->length;i++){
		arr3->A[k++]=arr1->A[i];
	}
	for(;j<arr2->length;j++){
		arr3->A[k++]=arr2->A[j];
	}
	arr3->length=arr1->length+arr2->length;
	arr3->size=10;
	return arr3;
}
int main()
{
	Array A1={{2,6,10,15,25},10,5};
	Array A2={{3,4,7,18,20},10,5};
	Array *A3;
	A3=merge(&arr1,&arr2);
	display(arr3);
	return 0;
}
