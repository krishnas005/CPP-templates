#include<iostream>
using namespace std;

class Heap {
	public:
		int size;
		int arr[101];
		Heap() {
			size = 0;
		}
		void Insert(int val) {
			size++;
			int index = size;
			arr[index] = val;
			while(index>1) {
				if(arr[index]>arr[index/2]) {
					swap(arr[index],arr[index/2]);
					index = index/2;
				} else {
					break;
				}
			}
		}
		int Delete() {
			int ans = arr[1];
			arr[1] = arr[size];
			size--;
			int index = 1;
			while(index < size) {
				int leftIndex = 2*index;
				int rightIndex = 2*index+1;
				int largestKaIndex = index;
				if(leftIndex<=size && arr[largestKaIndex]<arr[leftIndex]) {
					largestKaIndex = leftIndex;
				}
				if(rightIndex<=size && arr[largestKaIndex]<arr[rightIndex]) {
					largestKaIndex = rightIndex;
				}
				if(index == largestKaIndex) {
					break;
				} else {
					swap(arr[index],arr[largestKaIndex]);
					index = largestKaIndex;
				}
			}
			return ans;
		}
};

void heapify(int *arr,int n,int index) {
	
	int leftIndex = 2*index;
	int rightIndex = 2*index+1;
	int largestKaIndex = index;
	
	if(leftIndex<n && arr[leftIndex]>arr[largestKaIndex]) {
		largestKaIndex = leftIndex;
	}
	
	else if(rightIndex<n && arr[rightIndex]>arr[largestKaIndex]) {
		largestKaIndex = rightIndex;
	}
	
	if(index != largestKaIndex) {
		swap(arr[index],arr[largestKaIndex]);
		index = largestKaIndex;
		heapify(arr,n,index);
	}
	
}

void buildHeap(int arr[],int n) {
	for(int i=n/2;i>=0;i--) {
		heapify(arr,n,i);
	}
}

void heapSort(int arr[],int n) {
	buildHeap(arr,n);
	while(n!=1) {
	    swap(arr[0],arr[n-1]);
	    n--;
	    heapify(arr,n,0);
	}
}
 

int main() {
//	Heap h;
//	h.Insert(10);
//	h.Insert(20);
//	h.Insert(5);
//	h.Insert(11);
//	h.Insert(6);
//	for(int i=1;i<=h.size;i++) {
//		cout<<h.arr[i]<<" ";
//	} cout<<endl;
//	h.Insert(110);
//	for(int i=1;i<=h.size;i++) {
//		cout<<h.arr[i]<<" ";
//	} cout<<endl;
//	cout<<h.Delete()<<endl;
//	for(int i=1;i<=h.size;i++) {
//		cout<<h.arr[i]<<" ";
//	} cout<<endl;
    int n = 5;
    int arr[n] = {10,2,20,30,5};
    buildHeap(arr,n);
    for(int i=0;i<n;i++) {
    	cout<<arr[i]<<" ";
	}
	cout<<endl;
	heapSort(arr,n);
	for(int i=0;i<n;i++) {
    	cout<<arr[i]<<" ";
	}
	return 0;
}