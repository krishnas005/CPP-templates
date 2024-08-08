#include<iostream>
using namespace std;
void quickSort(int a[],int start,int end) {
	if(start>=end) return;
	int i = start-1;
	int j = start;
	int pivot = end;
	while(j<pivot) {
		if(a[j]<a[pivot]){
			++i;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		++j;
	}
	++i;
	int temp = a[i];
	a[i] = a[pivot];
	a[pivot] = temp;
	quickSort(a,start,i-1);
	quickSort(a,i+1,end);
}
int main() {
	int arr[5] = {5,2,4,3,1};
	quickSort(arr,0,4);
	for(int i=0;i<5;i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}
