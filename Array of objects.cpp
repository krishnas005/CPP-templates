#include<iostream>
using namespace std;
class complex{
	private:
		int real,imag;
	public:
		int setdata(int a,int b){
			real=a;
			imag=b;
		}
		void getdata(void){
			cout<<"Real part= "<<
			real<<endl<<"Imaginary part= "<<
			imag<<endl;
		}
};
int main()
{
	complex *ptr= new complex[3];
	complex *ptrtemp= ptr;
	for(int i=0;i<3;i++){
		int a,b;
		cout<<"Enter real and imaginary part of complex"<<i+1<<endl;
		cin>>a>>b;
		ptr->setdata(a,b);
		ptr++;
	}
	for(int i=0;i<3;i++){
		cout<<"Complex"<<i+1<<endl;
		ptrtemp->getdata();
		ptrtemp++;
	}
	return 0;
}
