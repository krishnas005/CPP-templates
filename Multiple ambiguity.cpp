#include<iostream>
using namespace std;
class A{
	protected:
	    int value_A;
	public:
		A(){
		value_A=10;	
		}
		void show(){
			cout<<"Value of A is : "<<value_A<<endl;
		}
};
class B{
	protected:
		int value_B;
	public:
		B(){
			value_B=20;
		}
		void show(){
			cout<<"Value of B is : "<<value_B<<endl;
		}
};
class C : public A, public B{
	protected:
	    int value_C;
	public:
		C(){
			value_C=30;
		}
		void show(){
			cout<<"Value of C is : "<<value_C<<endl;
		}
};
int main()
{
	C a;
	a.A::show();
	a.B::show();
	a.show();
	return 0;
}
