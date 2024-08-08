#include<iostream>
using namespace std;
class internal{
	protected:
		int i_marks;
	public:
		void input_i(){
			cout<<"Enter Internal marks: ";
			cin>>i_marks;
		}
		void show_i(){
			cout<<"Internal marks: "<<i_marks<<endl;
		}
};
class external{
	protected:
	    int e_marks;
	public:
		void input_e(){
			cout<<"Enter External marks: ";
			cin>>e_marks;
		}
		void show_e(){
			cout<<"External marks: "<<e_marks<<endl;
		}
};
class result: public internal, public external{
	protected:
		int total;
	public:
		void input(){
			input_i();
			input_e();
		}
		void show(){
			show_i();
			show_e();
		}
	void ans(){
			total= i_marks+e_marks;
			cout<<"Total marks = "<<total<<endl;
		}
};
int main()
{
	result s1;
	s1.input();
	s1.show();
	s1.ans();
	return 0;
}
