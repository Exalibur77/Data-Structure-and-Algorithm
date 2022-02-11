#include<iostream>
using namespace std;

// class Template
template <class T> // when single parameter template<typename T>
class vector{

    public:
    int size;
    T *arr;

    vector(int size){
        this->size = size;

        arr = new T[size];
    }

    T accumulate(){

        T sum =0;

        for(int i=0 ; i<size ; i++){
            sum+=arr[i];
        }

        return sum;
    }

};

int main(){

    vector <int>v1(3);
    v1.arr[0]=-1;
    v1.arr[1]=10;
    v1.arr[2]=98;
    
    cout << v1.accumulate() << endl;

    vector<float> v2(3);
    v2.arr[0]=1.89;
    v2.arr[1]=10.9;
    v2.arr[2]=0.7;
    
    cout << v2.accumulate() << endl;


    return 0;
}