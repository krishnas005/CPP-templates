#include<iostream>
using namespace std;
int getMin(int num[],int n){
	int Min;
	for(int i=0;i<n;i++){
		Min= min(Min,num[i]);
	}
	return Min;
}
int getMax(int num[],int n){
	int Max;
	for(int i=0;i<n;i++){
		Max= max(Max,num[i]);
	}
	return Max;
}
int main()
{
	int size;
	cout<<"Enter the size: ";
	cin>>size;
	
	int num[20];
	
	cout<<"Enter the numbers: "<<endl;
	for(int i=0;i<size;i++){
		cin>>num[i];
	}
	cout<<"The Maximum number is: "<<getMax(num,size)<<endl;
	cout<<"The Minimum number is: "<<getMin(num,size)<<endl;
	return 0;
}
