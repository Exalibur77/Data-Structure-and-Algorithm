#include<iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int rear,front,ms,cs;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        ms = n;
        arr = new int[n];
        front = 0;
        rear = n-1;
        cs = 0;
    }

    bool isFull(){
        return cs == ms;
    }
    
    bool enqueue(int value){
        
        if(isFull()){
            return false;
        }
        
        rear = (rear+1)%ms;
        
        arr[rear] = value;
        cs++;
        return true;
    }

    bool isEmpty(){
        return cs == 0;
    }
    
    int dequeue(){
        
        // empty
        if(isEmpty()){
            return -1;
        }
        
        int ans = arr[front];
        
        front = (front+1)%ms;
        cs--;
        
        cout << ans << " is popped " << endl;
        return ans;
    }
    
    int getFront(){
        
        if(isEmpty()) return -1;
        return arr[front];
    }

    int size(){
        return cs;
    }
};