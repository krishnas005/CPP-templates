#include<iostream>
using namespace std;
int Reverse(int n){
	int rem;
	int rev=0;
	while(n!=0){
		rem = n%10;
		rev = rev*10+rem;
		n/=10;
	}
	return rev;
}
int main(){
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	cout<<"Reverse of given number is: "<<Reverse(n);
	return 0;
}
