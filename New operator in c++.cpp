#include<iostream>
using namespace std;
int main()
{
	int *a= new int(4);//to allocate memory to variable
	cout<<*a<<endl;//to print address
	delete a;//to delete the value 
	cout<<*a<<endl;
	int *b= new int[3];//to allocate memory to array
	b[0]=4;
	b[1]=40;
	b[2]=400;
	cout<<b[0];
	return 0;
}
