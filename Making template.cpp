#include<iostream>
using namespace std;
template <class T>
class vector{
	public:
		T *arr;
		int size;
	public:
		vector(int m){
			size=m;
			arr= new T[size];
		}
		T dotProduct(vector &v){
			T d=0;
			for(int i=0;i<size;i++){
				d+=this->arr[i]*v.arr[i];
			}
			return d;
		}
};
int main()
{
	vector <float>v1(2);
	v1.arr[0]=4.2;
	v1.arr[1]=5.1;
	vector <float>v2(2);
	v2.arr[0]=6.3;
	v2.arr[1]=7.8;
	float z= v1.dotProduct(v2);
	cout<<"Dot product is: "<<z<<"   "<<": )"<<endl;
	return 0;
}
