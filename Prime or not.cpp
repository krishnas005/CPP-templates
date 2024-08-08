#include<iostream>
using namespace std;
bool isPrime(int n){
	if(n==0 || n==1){
		return 0;
	}
	for(int i=2;i<n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int num;
	cout<<"Enter the number to check for: "<<endl;
	cin>>num;
	if(isPrime(num)){
		cout<<num<<" is Prime.";
	}
	else{
		cout<<num<<" is not prime.";
	}
	return 0;
}
