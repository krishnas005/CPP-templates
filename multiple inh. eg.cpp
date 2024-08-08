#include<iostream>
#include<cmath>
using namespace std;
class simple{
	public:
		int a,b,sum,diff,prod;
		float div;
		int getno_simp(int n1,int n2){
			a=n1;
			b=n2;
		}
		void process_simp(void){
			sum= a+b;
			diff= a-b;
			prod= a*b;
			div= (float)a/b;
		}
		void display_simp(void){
			cout<<"The sum of given numbers is "<<sum<<endl;
			cout<<"The difference of given numbers is "<<diff<<endl;
			cout<<"The product of given numbers is "<<prod<<endl;
			cout<<"The division of given numbers is "<<div<<endl;
		}
};
class scientific{
	public:
		int a,b;
		float sqr1,sqrt1,cube1,cubert1,sqr2,sqrt2,cube2,cubert2;
		int getno_sci(int n1,int n2){
			a=n1;
			b=n2;
		}
		void process_sci(void){
			sqr1= a*a;
			sqrt1= sqrt(a);
			cube1= a*a*a;
			cubert1= cbrt(a);
			sqr2= b*b;
			sqrt2= sqrt(b);
			cube2= b*b*b;
			cubert2= cbrt(b);
		}
		void display_sci(void){
			cout<<"The square of 1st number is "<<sqr1<<endl;
			cout<<"The square root of 1st number is "<<sqrt1<<endl;
			cout<<"The cube of 1st number is "<<cube1<<endl;
			cout<<"The cube root of 1st number is "<<cubert1<<endl;
			cout<<"The square of 2nd number is "<<sqr2<<endl;
			cout<<"The square root of 2nd number is "<<sqrt2<<endl;
			cout<<"The cube of 2nd number is "<<cube2<<endl;
			cout<<"The cube root of 2nd number is "<<cubert2<<endl;
		}
};
class Hybrid : public simple,public scientific{
	public:
	void set_no(int a,int b){
		getno_simp(a,b);
		getno_sci(a,b);
	}
	void process(void){
		process_simp();
		process_sci();
	}
	void display(){
		display_simp();
		display_sci();
	}
};
int main()
{
	int a,b;
	cout<<"Enter two numbers a and b : "<<endl;
	cin>>a>>b;
	
	Hybrid call;
	call.set_no(a,b);
	call.process();
	call.display();
	return 0;
}
