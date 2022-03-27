
#include<iostream>
#include<string>
using namespace std;

template <class T>
class stack
{
private:
    
    T *arr;
    int top;
    int size;
    
public:
    stack(int size);
    
    void push(T ele){

        if(top < size-1){
            arr[++top] = ele;
        }

        else{
            cout << "Stack OverFlown" << endl;
        }

    }

    void pop();

    bool empty();

    T peek();

};

template <class T>
stack<T> ::stack(int size){

    this->size = size;
    arr = new T[size];
    top =-1;
}
template <class T>
void stack<T> ::pop(){

    if(top >=0 ) top--;
    
    else{
        cout << "Stack Empty" <<endl;
    }
}

template <class T>
bool stack<T> :: empty(){

    return top==-1;
}

template <class T>
T stack<T> :: peek(){

    if(top >=0) return arr[top];

    else{
        cout << "Stack Empty" << endl;
        
    }
    return 100;

}