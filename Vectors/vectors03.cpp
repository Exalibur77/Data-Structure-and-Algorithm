#include<iostream>
using namespace std;

class vector{

private:
    int * arr;
    int curr_size;
    int max_size;

public:
    // Constructor
    vector(){
        curr_size=0;
        max_size=1;
        arr=new int[max_size];
    }

    void push_back(int val){
        // Two Cases

        if(curr_size == max_size){
            // Create a new array and delete the previous one, double the capacity

            int *oldArr=arr;
            max_size=2*max_size;
            arr=new int[max_size];
            // Copy the elements to the new arr from old array

            for (int i = 0; i < curr_size; i++)
            {
                arr[i]=oldArr[i];
            }

            // Deletion of old Array
            
            delete []oldArr;

        }

        arr[curr_size]=val;
        curr_size++;

    }

    // cant make this function constant because class variable is being changed it is not constant
    void pop_back(){
        if(curr_size>0){
            curr_size--;
        }
    }

    bool isEmpty() const{
        return curr_size==0;
    }

    // Front , back , at(i), operator overloading

    int front() const{
        return arr[0];
    }

    int back() const{
        return arr[curr_size-1];
    }

    int at(const int i) const{
        return arr[i];
    }

    int size() const{
        return curr_size;
    }

    int capacity() const{
        return max_size;
    }

    // operator overloading
    // int i is now constant and given function is also constant as our function is not changing our class members.

    int operator[](const int i) const{
        return arr[i];
    }


};

int main(){

    vector v;

    v.push_back(12);
    v.push_back(1212);
    v.push_back(2);
    v.push_back(1);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;

    v.pop_back();

    cout << v.size() << " " << v.capacity() << endl;
    
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}