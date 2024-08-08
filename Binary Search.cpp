#include<iostream>
using namespace std;
class Array{
	public:
		int A[10];
		int size;
		int length;
};
int BinarySearch(Array arr,int key){
	int l=0,h=arr.length-1;
	int m=(l+h)/2;
	while(l<=h){
		if(key==arr.A[m]){
			return m;
		}
		else if(key<arr.A[m]){
			h=m-1;
		}
		else{
			l=m+1;
		}
		return 0;
	}
}
int main()
{
	Array A={{1,2,3,4,5,6,7,8,9,10},10,10};
	cout<<BinarySearch(A,5);
	return 0;
}
