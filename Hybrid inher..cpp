#include<iostream>
using namespace std;
class animals{
	public:
		animals(){
			cout<<"These all are animals."<<endl;
		}
};
class cow : public virtual animals{
	public:
		cow(){
			cout<<"This is cow."<<endl;
		}
};
class dog : public virtual animals{
	public:
		dog(){
			cout<<"This is dog."<<endl;
		}
};
class mammals : public cow, public dog{
	public:
		mammals(){
			cout<<"These all are mammals."<<endl;
		}
};
int main(){
	mammals a;
	return 0;
}
