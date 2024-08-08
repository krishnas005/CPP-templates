#include<iostream>
#include<algorithm>
using namespace std;

//void selectionSort(int arr[],int size) {
//	for(int i=0;i<size-1;i++) {
//		int min = i;
//		for(int j=i+1;j<size;j++) {
//			if(arr[j]<arr[min]) {
//				min = j;
//			}
//		}
//		swap(arr[i],arr[min]);
//	}
//}
//
//void print(int arr[]) {
//	for(int i=0;i<5;i++) {
//		cout<<arr[i]<<" ";
//	}cout << endl;
//}

int main() {
	int arr[] = {7,2,4,9,1};
//	int size = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
	cout<<n;
//	selectionSort(arr,size);
//	print(arr);
	return 0;
}