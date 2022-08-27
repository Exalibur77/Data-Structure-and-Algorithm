// Implemenatation of a doubly ended queue
#include<iostream>
#include<climits>
using namespace std;

# define maxi 10

class deque{

    int *arr;
    int front,rear,cs,ms;

public:

    deque(int n=maxi){

        arr = new int[n];
        ms = n;
        front = rear = -1;
        cs = 0;
    }

    bool isFull(){
        return cs == ms;
    }


    void insertFront(int val){

        // if size is full can't insert more values
        if(isFull()){
            cout << "Queue Full" << endl;
            return;
        }

        // first element is added
        if(front == -1){
            front = 0;
            rear = 0;
        }
        
        else if(front == 0){
            front = ms-1;
        }

        else{
            front --;
        }

        arr[front] = val;
        cs++;

    }

    void insertEnd(int val){

        // if size is full can't insert more values
        if(isFull()){
            cout << "Queue Full" << endl;
            return;
        }

        // first element is added
        if(front == -1){
            front = 0;
            rear = 0;
        }
        
        else if(rear == ms-1){
            rear = 0;
        }

        else{
            rear ++;
        }

        arr[rear] = val;
        cs++;

    }

    bool isEmpty(){
        return cs==0;
    }

    void popFront(){

        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }

        if(front == ms-1){
            front = 0;
        }

        else{
            front ++;
        }
        cs--;

        if(cs == 0){
            front = rear = -1;
        }


    }

    void popEnd(){

        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }

        if(rear == 0){
            rear = ms-1;
        }

        else{
            rear --;
        }
        cs--;

        if(cs == 0){
            front = rear = -1;
        }
    }

    int getFront(){
        
        if(isEmpty()){
            return INT_MAX;
        }

        return arr[front];

    }

    int getBack(){
        
        if(isEmpty()){
            return INT_MAX;
        }

        return arr[rear];

    }

    int size(){
        return cs;
    }

};