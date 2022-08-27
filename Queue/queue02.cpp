#include<iostream>
#include"queue1.h"

// Queue Implementation Using Arrays
using namespace std;

int main(){

    queue<char> q;

    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('x');
    q.enqueue('z');
    q.enqueue('q');

    cout << q.size() << endl;

    cout << q.front() << endl;

    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";

    cout << endl;

    cout << q.front() << endl;

    cout << q.size() << endl;

    cout << q.dequeue() << " " << endl;

    cout << q.size() << endl;

    cout << q.dequeue() << " " << endl;
    
    return 0;
}