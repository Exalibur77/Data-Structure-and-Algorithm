#include<iostream>
#include<string>
using namespace std;

// Queue Implementation Using Arrays

template <class T>
class queue {
public:
    T arr[100000];
    int start,rear;
    
    queue() {
        // Implement the Constructor
        start =0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return start == rear;
        
    }

    // template <class T>
    void enqueue(T data) {
        // Implement the enqueue() function
        
        if(rear >= 100000) {
             cout << "Full" << endl;
            return;
        }
        
        arr[rear] = data;
        rear++;
        
    }

    T dequeue() {
        // Implement the dequeue() function
        
        if(isEmpty()){
            cout << "So Sorry Queue Is Empty .. !" << endl;
            return -1;
        }
        
        int x = arr[start++];
        
        if(start == rear){
            start = 0;
            rear = 0;
        }
        
        return x;
    }

    T front() {
        // Implement the front() function
        
        if(isEmpty()){
            return -1;
        }
        
        return arr[start];
        
        
    }

    int size(){
        return rear-start;
    }
};