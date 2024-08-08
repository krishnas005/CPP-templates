#include<iostream>
using namespace std;
int LinearSearch(int arr[],int s,int n){
	for(int i=0;i<n;i++){
		if(arr[i]==s){
			return i;
		}
	}
	return -1;
}
int main()
{
	int num,element;
	cout<<"Enter the number of elements: "<<endl;
	cin>>num;
	int arr[num];
	cout<<"Enter the elements of array: "<<endl;
	for(int i=0;i<num;i++){
		cin>>arr[i];
	}
	cout<<"Enter the elemnt to search in array: "<<endl;
	cin>>element;
	int z=LinearSearch(arr,element,num);
	if(z!=-1){
		cout<<"Element found at index "<<z<<endl;
	}
	else{
		cout<<"Element not found.";
	}
	return 0;
}
